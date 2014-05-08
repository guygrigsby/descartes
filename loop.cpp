/*	For nodes representing loop statements 
**  Written by Guy Grigsby
*/
#include "tokens.h"
#include "stmtNode.h"
#include "scanner.h"
#include "expr.h"
#include "error.h"
#include "loop.h"

void Loop::parse(Scanner &scan) { //LOOP ID COLON stmt-list REPEAT
		
	scan.nextToken();
	setName(scan.getCurrName());
	scan.nextToken();
	if (scan.getCurrSymb() != COLON) {
		std::string msg  = "Loop::assignMembers:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-75, msg);
	}

	scan.nextToken();
}

void Loop::execute(std::map<std::string,double> &symbolTable) {

}
