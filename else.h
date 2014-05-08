#ifndef ELSE_H
#define ELSE_H

#include "tokens.h"
#include "stmtNode.h"


class Else : public StmtNode {

	public:	Else (){ nodekind = ELSE;}; 	//constructor
};
#endif
