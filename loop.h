/*	For nodes representing loop statements 
**  Written by Guy Grigsby
*/
#ifndef LOOP_H
#define LOOP_H

#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "expr.h"
#include "id.h"
#include "parseTree.h"
#include <list>

class Loop : public StmtNode { //LOOP ID COLON stmt-list REPEAT
	private:	std::string		id; //loop name
	private:	ParseTree *subTree;
	public:	Loop (){ nodekind = LOOP;}; 	//constructor
	public:	void assignMembers(Scanner &scan);		//parses loop stmt
	public: void execute(std::map<std::string, double> &symbolTable);
			void setName(std::string name) {id = name;};
			std::string getName() {return id;};

};
#endif
