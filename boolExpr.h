/*	For nodes representing expressions
**  Written by Aaron Gordon
*/
#ifndef BOOLEXPR_H
#define BOOLEXPR_H

#include  "expr.h"
#include  "scanner.h"
#include  <iostream>
#include  <map>

#include  "expr.h"
class BoolExpr : public Expr {
	public:	BoolExpr (){ }; 	//constructor
	public:	Expr * parse(Scanner &scan);
	public: virtual void setLeft(Expr *) {std::cout << "expr.setLeft" << std::endl;  };
	public: virtual double eval(std::map<std::string,double> &symbolTable) {std::cout << "exp.eval" << std::endl; return 0;};
};
#endif
