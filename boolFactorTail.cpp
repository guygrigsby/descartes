#include <stdlib.h>
#include "boolFactorTail.h"
#include "boolFactor.h"
#include "operator.h"

Expr * BoolFactorTail::parse(Scanner &scan) {
	Expr		*subtree;				//the expression subtree
	Expr		*rhs;					//lhs of the above subtree
	BoolFactor		*f	= new BoolFactor();		
	BoolFactorTail	*ft	= new BoolFactorTail();
	// factor-tail:  *  factor  factor-tail
	//			  	 /  factor  factor-tail
	if (scan.getCurrSymb() == AND) {	
		Operator   *op = new Operator(scan.getCurrSymb());
		scan.nextToken();
		rhs		= f->parse(scan);			//get the factor
		op->setRight(rhs);
		subtree = ft->parse(scan);			//get the factor-tail
		if (subtree != NULL) {
			subtree->setLeft(op);
			return subtree;
		} else return  op;
	} //if * or /
	return NULL;
}
