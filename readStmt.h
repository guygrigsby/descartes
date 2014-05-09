#ifndef READSTMT_H
#define READSTMT_H

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "id.h"
#include <list>

#include <map>


class ReadStmt : public StmtNode {
	protected:
					std::list<std::string> idList; 	//list of ids
	public:	ReadStmt (){ nodekind = READ;}; 	//constructor
			void fromStdIn(std::map<std::string,double> &symbolTable); // reads the contents in order listed
			void parse(Scanner &can);
};
#endif
