#include <stdlib.h>
#include "boolFactor.h"
#include "error.h"
#include "arithExpr.h"
#include "operator.h"
#include <iostream>

using namespace std;

Expr * BoolFactor::parse(Scanner &scan) {
	
	Expr			*subtree;				//the expression subtree
	Expr			*lhs;					//lhs of the above subtree
	ArithExpr		*ae	= new ArithExpr();		//from the grammar
	lhs = ae->parse(scan);
	int symb = scan.getCurrSymb();
	if (symb == LT || symb == LE ||
			symb == EQ || symb == GE ||
			symb == GT || symb == NE) {
		Operator   *op = new Operator(symb);
		scan.nextToken();
		op->setLeft(lhs);
		ae = new ArithExpr();
		subtree = ae->parse(scan);			//get the term-tail
		if (subtree == NULL)	return lhs;
		else {
			op->setRight(subtree);
			return op;
		}
	}
	return lhs;
}
