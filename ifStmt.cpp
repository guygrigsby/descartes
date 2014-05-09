
#include "tokens.h"
#include "ifStmt.h"
#include "number.h"
#include "error.h"
#include "expr.h"
#include <iostream>
#include <map>

using namespace std;

void  IfStmt::parse(Scanner &scan) {	//parses if stmt
	if (scan.getCurrSymb() != IF) {
		string msg  = "IfStmt::parse:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-77, msg);
	} //if
	scan.nextToken();
	Expr  *ex = new Expr();
	setCond(ex->parse(scan));
	if (scan.getCurrSymb() != THEN) {
		string msg  = "IfStmt::parse:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-79, msg);
	} //if
	scan.nextToken();

}

bool IfStmt::hasElsePart(Scanner &scan) {
	cout << "IfStmt::hasElsePart" << endl;
	if (scan.getCurrSymb() == FI) {
		scan.nextToken();
		return false;
	}
	if (scan.getCurrSymb() != ELSE) {
		string msg  = "IfStmt::ElsePart:  wrong token type found --> ";
		msg.append(scan.getCurrName());
		new Error(-77, msg);
	} //if
	scan.nextToken();
	return true;
}
bool IfStmt::isCondTrue(map<string,double> &symbolTable) {
	return cond->eval(symbolTable) != 0;	
}
