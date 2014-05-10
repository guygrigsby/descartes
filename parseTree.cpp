/*	To build the parse tree for Descarte
**  Written by Aaron Gordon
*/

//-------------------------
#include    <stdio.h>
#include    "tokens.h"
#include	"node.h"
#include	"parseTree.h"
#include	"becomes.h"
#include	"id.h"
#include	"error.h"
#include	"operator.h"
#include	"number.h"
#include	"loop.h"
#include	"repeat.h"
#include	"end.h"
#include 	"ifStmt.h"
#include 	"fi.h"
#include	"else.h"
#include 	"breakStmt.h"
#include	"printStmt.h"
#include	"readStmt.h"



#include <iostream>
#include <string>
#include <map>


using namespace std;


ParseTree::ParseTree(){
	root = NULL;
}//constructor

void ParseTree::init(string fname) {
	scan.init(fname);
} 

void ParseTree::execute(std::map<std::string,double> &symbolTable, StmtNode *rootNode){
	StmtNode *curr = rootNode;
	Number *num;
	Operator *op;
	Loop *loop;
	cout << "\nParseTree::executing" << endl;
	while (curr != NULL ) {
		stmtStack.push(curr);
		switch (curr->getKind()) {
			case BECOMES: {
				Becomes  *be = (Becomes *) curr;
				Node *n = be->getLHS();
				Id  *id = (Id *)n;
				cout <<  id->getName()  << "  := " ;
				n = be->getRHS();
				Expr * exp = (Expr *) n;
				double value = exp->eval(symbolTable);
				symbolTable[id->getName()] = value;
				cout << value << endl;
				break;
			}
			case LOOP: {
				Loop *loop = (Loop *) curr;
				curr = loop->getStmtList();
				continue;
			}
			case IF: {
				IfStmt *ifStmt = (IfStmt *) curr;
				if (ifStmt->isCondTrue(symbolTable)) {
					curr = ifStmt->getIfStmtList();
				} else if (ifStmt->hasElsePart()) {
					curr = ifStmt->getElseStmtList();
				} else {
					break;
				}

				continue;
			}
			case PRINT: {
				PrintStmt *printStmt = (PrintStmt *) curr;
				printStmt->toStdOut(symbolTable);
				break;
			}
			case READ: {
				ReadStmt *readStmt = (ReadStmt *) curr;
				readStmt->fromStdIn(symbolTable);
				break;
			}
			case BREAK: {
				BreakStmt *breakStmt = (BreakStmt *) curr;
				string breakId = breakStmt->getId();
				StmtNode *stmt = stmtStack.top();
				while(stmt != NULL) {
					if (stmt->getKind() == LOOP) {
						Loop *loop = (Loop *) stmt;
						if (breakStmt->getId().empty()) {
							curr = loop->getNext();
							stmtStack.pop();
							break;
						} else if (!loop->getName().compare(breakStmt->getId())) {
							curr = loop->getNext();
							stmtStack.pop();
							break;
						}
					}
					stmtStack.pop();
					stmt = stmtStack.top();
				}
				continue;
			}
			case PERIOD: {
				cout << "End Program" << endl;
				exit(0);
			}
			case REPEAT: {
				StmtNode *stmt = stmtStack.top();
				while(stmt != NULL) {
					if (stmt->getKind() == LOOP) {
						Loop *loop = (Loop *) stmt;
						curr = loop->getStmtList();
						break;
					} else {
						stmtStack.pop();
						stmt = stmtStack.top();
					}
				}
				//stmtStack.pop();
				continue;
			}
			case FI: {
				StmtNode *stmt = stmtStack.top();
				while(stmt != NULL) {
					if (stmt->getKind() == IF) {
						IfStmt *ifStmt = (IfStmt *) stmt;
						curr = ifStmt->getNext();
						break;
					} else {
						stmtStack.pop();
						stmt = stmtStack.top();
					}
				}
				stmtStack.pop();
				continue;
			}
			case ELSE: {
				break;
			}
			default: char msg[100];
				cout << "Cannot execute unknown type" << endl;
				break;
		}
		curr = curr->getNext();
	}//while
}//execute

void ParseTree::execute(std::map<std::string,double> &symbolTable){
	execute(symbolTable, root);
}

void ParseTree::build() {  /* prog : stmt stmt-tail */
    stmt(root);				//root points to first statement node after call
    stmtTail(*root);		//pass in node where rest of pgm is to be attached
	cout << "time to end, token is " << scan.getCurrSymb() << endl;
    if (scan.getCurrSymb() != PERIOD) new Error(6, " PERIOD expected");
} //build

void ParseTree::stmtTail (StmtNode &current) {
/*  Current is the end of a chain of statements.  If there are more
    statements, tack them on the end. */
	StmtNode *nextStmt;
    if (scan.getCurrSymb() == SEMICOLON)  { // stmt-tail : SEMICOLON stmt stmt-tail 
	  cout << "stmtTail: " << endl;
	  scan.nextToken();
      stmt(nextStmt);				//create the statement node for the next statement
      current.setNext(nextStmt);	//attach it to the list of nodes
      stmtTail(*nextStmt);//build up the rest of the program
    } // else stmt-tail is empty; do nothing
} //stmtTail

void ParseTree::stmt (StmtNode *&current) {//create a statement node and have current point to it
	int symb = scan.getCurrSymb();
	switch (symb) {
	case ID: {
		Becomes *be;
		be = new Becomes();
		current = be;
		be->assignment(scan);	//find an assignment statement
		// expr
		break;					// stmt : ID := expr 
	}
	case PERIOD: {
		current = new End();
		cout << "PERIOD. Program end" << endl;
		break;
	}
	case LOOP: {
		Loop *loop = new Loop();
		current = loop;
		loop->parse(scan); // create statement list in loop
		StmtNode *loopRoot;
		stmt(loopRoot);
		stmtTail(*loopRoot);
		loop->setStmtList(loopRoot);
		scan.nextToken();//swallow REPEAT TODO this should be done in repeat.cpp
		break; // loop = 
	}
	case REPEAT: {
		current = new Repeat();
		break;
	}
	case IF: {
		IfStmt* ifStmt = new IfStmt();
		current = ifStmt;
		ifStmt->parse(scan);
		StmtNode *ifRoot;
		stmt(ifRoot);
		stmtTail(*ifRoot);
		ifStmt->setStmtList(ifRoot);
		if (ifStmt->hasElsePart(scan)) {
			StmtNode *elseRoot;
			stmt(elseRoot);
			stmtTail(*elseRoot);
			ifStmt->setElsePart(elseRoot);
			scan.nextToken();
		}
		break;
	}
	case PRINT: {
		PrintStmt *printStmt = new PrintStmt();
		printStmt->parse(scan);
		current = printStmt;
		break;
	}
	case READ: {
		ReadStmt *readStmt = new ReadStmt();
		readStmt->parse(scan);
		current = readStmt;
		break;
	}
	case BREAK: {
		BreakStmt *breakStmt = new BreakStmt();
		breakStmt->parse(scan);
		current = breakStmt;
		break;
	}
	case FI: {
		current = new Fi();
		break;
	}
	case ELSE: {
		current = new Else();
		break;
	}

	default: char msg[100];
			 string msg2="Unrecognized statement: ";
			 new Error(4,msg2.append( scan.getCurrName()));
	}
} //ParseTree
