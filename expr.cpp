/*	For nodes representing arithmetic expressions
**  Written by Aaron Gordon
*/

#include  <iostream>
#include  "expr.h"
#include  "operator.h"
#include  "boolTerm.h"
#include  "boolTermTail.h"
#include  <stdlib.h>

Expr * Expr::parse(Scanner &scan){
	Expr		*subtree;				//the expression subtree
	Expr		*lhs;					//lhs of the above subtree
	BoolTerm		*t	= new BoolTerm();		//from the grammar
	BoolTermTail	*tt	= new BoolTermTail();	//from the grammar
	lhs		= t->parse(scan);			//get the term
	subtree = tt->parse(scan);			//get the term-tail
	if (subtree == NULL)	return lhs;
	else {
		subtree->setLeft(lhs);
		return subtree;
	}
};  //parse

