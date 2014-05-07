/*	For nodes representing expressions
**  Written by Aaron Gordon
*/
#ifndef ARITHEXPR_H
#define ARITHEXPR_H

#include  "scanner.h"
#include  "expr.h"
#include  <iostream>
#include  <map>

class ArithExpr : public Expr {
	public:	ArithExpr (){ }; 	//constructor
	public:	Expr * parse(Scanner &scan);
	public: virtual void setLeft(Expr *) {std::cout << "expr.setLeft" << std::endl;  };
	public: virtual double eval(std::map<std::string,double> &symbolTable) {std::cout << "exp.eval" << std::endl; return 0;};
};
#endif
