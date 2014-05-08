#ifndef END_H
#define END_H

#include "tokens.h"
#include "stmtNode.h"


class End : public StmtNode {

	public:	End (){ nodekind = PERIOD;}; 	//constructor

};
#endif
