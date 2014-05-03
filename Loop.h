/*	For nodes representing loop statements 
**  Written by Guy Grigsby
*/
#ifndef LOOP_H
#define LOOP_H

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "expr.h"
#include "id.h"

class Loop : public StmtNode {
	private:	std::string		id; //loop name
				Expr	*rhs;		//right hand side of assignment statement
	public:	Becomes (){ nodekind = LOOP;}; 	//constructor
			Id *getLHS() {return lhs;};			//accessor
			Expr *getRHS() {return rhs;};		//accessor
			void setRHS(Expr *n) {rhs = n;};
			void setLHS(Id *n) {lhs = n;};
			void assignment(Scanner &scan);		//parses assignment stmt
};
#endif
