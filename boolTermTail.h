/*	For nodes representing numbers
**  Written by Aaron Gordon
*/
#ifndef BOOLTERMTAIL_h
#define BOOLTERMTAIL_h

#include "scanner.h"
#include "expr.h"
#include "term.h"
#include "tokens.h"
#include "operator.h"

class BoolTermTail {
		 public: BoolTermTail() { };		//constructor
		 public: Expr * parse(Scanner &);	
};
#endif
