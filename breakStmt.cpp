
#include "tokens.h"
#include "error.h"
#include <iostream>
#include "breakStmt.h"

using namespace std;

void  BreakStmt::parse(Scanner &scan) {	//parses if stmt
	if (scan.getCurrSymb() != BREAK) {
		string msg  = "BreakStmt::parse:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-93, msg);
	} //if
	scan.nextToken();

	if (scan.getCurrSymb() != SEMICOLON) {
		setId(scan.getCurrName());
	}
	scan.nextToken();
}