/*	For nodes representing expressions
**  Written by Aaron Gordon
*/
#ifndef EXPR_H
#define EXPR_H

#include  "node.h"
#include  "scanner.h"
#include  <iostream>
#include  <map>

class Expr : public Node {
	public:	Expr (){ }; 	//constructor
	public:	Expr * parse(Scanner &scan);
	public: virtual void setLeft(Expr *) {std::cout << "expr.setLeft" << std::endl;  };
	public: virtual double eval(std::map<std::string,double> &symbolTable) {std::cout << "exp.eval" << std::endl; return 0;};
};
#endif
