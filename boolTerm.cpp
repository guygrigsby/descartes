#include <stdlib.h>
#include "boolTerm.h"
#include "boolFactor.h"
#include "boolFactorTail.h"

Expr * BoolTerm::parse(Scanner &scan) {
	Expr		*subtree;				//the expression subtree
	Expr		*lhs;					//lhs of the above subtree
	BoolFactor		*f	= new BoolFactor();		//from the grammar
	BoolFactorTail	*ft	= new BoolFactorTail();	//from the grammar
	lhs		= f->parse(scan);			//get the factor
	subtree = ft->parse(scan);			//get the factor-tail
	if (subtree == NULL)		return lhs;
	else {
		subtree->setLeft(lhs);
		return subtree;
	}
}
