/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef BOOLTERM_H
#define BOOLTERM_H

#include "scanner.h"
#include "expr.h"

class BoolTerm {
		 public: BoolTerm() { };		//constructor
		 public: Expr * parse(Scanner &);	
};
#endif
