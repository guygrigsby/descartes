/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef BOOLFACTOR_H
#define BOOLFACTOR_H

#include "scanner.h"
#include "boolExpr.h"

class BoolFactor {
		 public: BoolFactor() { };		//constructor
		 public: Expr * parse(Scanner &);	
};
#endif
