#include "readStmt.h"


void ReadStmt::parse(Scanner &scan) {
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
void ReadStmt::fromStdIn(std::map<std::string,double> &symbolTable) {
	std::list<std::string>::reverse_iterator iter;
  	for(iter = idList.rbegin(); iter != idList.rend(); iter++) {
   		std::string var = *iter;
   		double value;
   		std:: cout << "Enter Value for " + *iter << std::endl;
   		std::cin >> value;
   		symbolTable[*iter] = value;
   		printf("%s set to %f ", var.c_str(), value );
   	}

}