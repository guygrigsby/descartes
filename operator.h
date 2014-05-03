/*	For nodes containing operators such as +, -, *, /
**  Written by Aaron Gordon
*/
#ifndef OPERATOR_h
#define OPERATOR_h

#include "expr.h"
#include <stdlib.h>
#include <map>
#include "number.h"

class Operator : public  Expr {
	 Expr	*left;
	 Expr 	*right;
	 public: Operator() {left = NULL; };			//constructor
	 public: Operator(int type) {left = NULL;  nodekind = type;};		//constructor
	 public: Expr* getRight(){ return right;};		//returns right child
	 public: Expr* getLeft(){ return left;};		//returns Left child
	 public: void  setRight(Expr* ptr) {right = ptr;};	//assigns to right
	 public: void  setLeft(Expr* ptr); 				//assigns to Left
	 public: void print(); //prints the op
	 public: double eval(std::map<std::string,double> &symbolTable); // evaluates the operator subtree
};
#endif
