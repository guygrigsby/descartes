

#ifndef IF_STMT_h
#define IF_STMT_h

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "expr.h"
#include <map>

class IfStmt : public StmtNode {
	private:
			Expr*		cond;
			StmtNode*  	subtree;
			StmtNode*	elsePart;
	public: IfStmt() {nodekind = IF;};
			void parse(Scanner &scan);
			void setStmtList(StmtNode* list) {subtree = list;};
			void setElsePart(StmtNode* el) {elsePart = el;};
			bool hasElsePart(Scanner &scan);
			bool hasElsePart() {return elsePart != NULL;};
			void setCond(Expr* exp) {cond = exp;};
			StmtNode* getIfStmtList() {return subtree;};	
			bool isCondTrue(std::map<std::string,double> &symbolTable);
			StmtNode* getElseStmtList() {return elsePart;};	

};
#endif