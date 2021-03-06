#include  "parseTree.h"
#include  "tokens.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv ) {
	ParseTree  ptree;
	string fname="";
	if (argc > 1) {
		fname.append(argv[1]);
	}
	ptree.init(fname);
	ptree.build();
	
	std::map<std::string,double> symbolTable;
	cout << "\n\n" << endl;
	ptree.execute(symbolTable);
}
