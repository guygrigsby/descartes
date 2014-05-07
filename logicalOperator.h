/*	For nodes containing operators such as +, -, *, /
**  Written by Aaron Gordon
*/
#ifndef LOGICAL_OPERATOR_h
#define LOGICAL_OPERATOR_h

#include "expr.h"
#include "boolExpr.h"
#include <stdlib.h>
#include <map>
#include "number.h"

class LogicalOperator : public  Expr {
	 Expr	*left;
	 Expr 	*right;
	 public: LogicalOperator() {left = NULL; };			//constructor
	 public: LogicalOperator(int type) {left = NULL;  nodekind = type;};		//constructor
	 public: Expr* getRight(){ return right;};		//returns right child
	 public: Expr* getLeft(){ return left;};		//returns Left child
	 public: void  setRight(BoolExpr* ptr) {right = ptr;};	//assigns to right
	 public: void  setLeft(BoolExpr* ptr); 				//assigns to Left
	 public: void print(); //prints the op
	 public: double eval(std::map<std::string,double> &symbolTable); // evaluates the operator subtree
};
#endif
