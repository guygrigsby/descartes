/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef BOOL_FACTORTAIL_h
#define BOOL_FACTORTAIL_h

#include "scanner.h"
#include "boolExpr.h"
#include "factor.h"
#include "tokens.h"

class BoolFactorTail {
		 public: BoolFactorTail() { };		//constructor
		 public: Expr * parse(Scanner &);	
};
#endif
