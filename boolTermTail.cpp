#include <stdlib.h>
#include "boolTermTail.h"
#include "boolTerm.h"
#include "expr.h"

Expr * BoolTermTail::parse(Scanner &scan) {
	Expr		*subtree;				//the expression subtree
	Expr		*rhs;					//lhs of the above subtree
	BoolTerm		*t	= new BoolTerm();		
	BoolTermTail	*tt	= new BoolTermTail();
	// term-tail:  +  term  term-tail
	//			   -  term  term-tail
	if (scan.getCurrSymb() == OR) {	
		Operator   *op = new Operator(scan.getCurrSymb());
		scan.nextToken();
		rhs		= t->parse(scan);			//get the term
		op->setRight(rhs);
		subtree = tt->parse(scan);			//get the term-tail
		if (subtree != NULL) {
			subtree->setLeft(op);
			return subtree;
		} else return  op;
	} //if * or /
	return NULL;
}
