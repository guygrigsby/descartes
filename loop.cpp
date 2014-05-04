/*	For nodes representing loop statements 
**  Written by Guy Grigsby
*/
#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "expr.h"
#include "error.h"
#include "loop.h"
#include "parseTree.h"

void Loop::assignMembers(Scanner &scan) { //LOOP ID COLON stmt-list REPEAT
		
	scan.nextToken();
	setName(scan.getCurrName());
	scan.nextToken();
	if (scan.getCurrSymb() != COLON) {
		std::string msg  = "Loop::assignMembers:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-75, msg);
	}

	scan.nextToken();
	subTree = new ParseTree(scan);
	subTree->build();
	scan.nextToken(); // just eat the repeat
	scan.nextToken(); // just eat the repeat
}

bool broken = false;
void Loop::execute(std::map<std::string,double> &symbolTable) {
	while (!broken) {
		subTree->execute(symbolTable);	
	}
}
