#ifndef BREAK_H
#define BREAK_H

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"


class BreakStmt : public StmtNode {
	private:
			std::string  id;
	public:	BreakStmt (){ nodekind = BREAK;}; 	//constructor
			std::string getId() {return id;};
			void parse(Scanner &scan);
			void setId(std::string name) {id = name;};
};
#endif
