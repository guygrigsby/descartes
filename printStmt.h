#ifndef PRINTSTMT_H
#define PRINTSTMT_H

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "id.h"
#include <list>

#include <map>


class PrintStmt : public StmtNode {
	protected:
					std::list<std::string> idList; 	//list of ids
	public:	PrintStmt (){ nodekind = PRINT;}; 	//constructor
			void toStdOut(std::map<std::string,double> &symbolTable); //prints the ids and contents
			void parse(Scanner &can);
};
#endif
