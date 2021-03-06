/*	To build the parse tree for Descarte
**  Written by Aaron Gordon
*/
#ifndef  PARSETREE_h
#define  PARSETREE_h

#include	"stmtNode.h"
#include	"scanner.h"
#include    "operator.h"

class ParseTree {
	private:	StmtNode *root;		//points to recursive descent tree
				Scanner  scan;		//Scanner object to retrieve tokens
				void execute(std::map<std::string,double> &symbolTable, StmtNode* rootNode);

	public:		ParseTree();		//constructori
				ParseTree(Scanner &scan);
				void build();
				void execute(std::map<std::string,double> &symbolTable);
				void stmtTail (StmtNode &current);
				void stmt (StmtNode  *&current); 
				void init(std::string fname);
};
#endif
