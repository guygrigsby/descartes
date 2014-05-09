#include "printStmt.h"


void PrintStmt::parse(Scanner &scan) {
	scan.nextToken();
	idList.push_front(scan.getCurrName());
	scan.nextToken();
	int symb = scan.getCurrSymb();
	while (symb == COMMA) {
		scan.nextToken();
		idList.push_front(scan.getCurrName());
		scan.nextToken();
		symb = scan.getCurrSymb();
	}
}
void PrintStmt::toStdOut(std::map<std::string,double> &symbolTable) {
	std::list<std::string>::reverse_iterator iter;
  	for(iter = idList.rbegin(); iter != idList.rend(); iter++) {
   		std::string var = *iter;
   		double value = symbolTable[*iter];
   		printf("%s = %f\n", var.c_str(), value );
   	}

}