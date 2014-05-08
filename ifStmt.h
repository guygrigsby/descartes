

#ifndef IF_STMT_h
#define IF_STMT_h

#include "tokens.h"
#include "stmtnode.h"
#include "scanner.h"
#include "expr.h"

class IfStmt : public StmtNode {
	private:
			Expr*		cond;
			StmtNode*  	subtree;
			//ElsePart*	elsePart;
	public: IfStmt() {nodeKind = IF};
			void parse(Scanner &scan);
			void setStmtList(StmtList* list) {subtree = list;};
			StmtNode* getIfStmtList() {return subtree;};		
			StmtNode* getElseStmtList() {return elsePart->getStmtList();};	
			bool isCondTrue();

};
#endif