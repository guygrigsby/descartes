#include "operator.h"
#include "number.h"

void  Operator::setLeft(Expr* ptr) {
	if (left == NULL)	left = ptr;	
	else				left->setLeft(ptr);
}

void Operator::print() {
	std::cout << this->getKind() << std::endl;
}
double Operator::eval(std::map<std::string,double> &symbolTable) {
	double ret;
	switch (getKind()) {
		case PLUS: {
			ret = getRight()->eval(symbolTable) + getLeft()->eval(symbolTable);
			break;
		}
		case MINUS: {
			ret = getRight()->eval(symbolTable) - getLeft()->eval(symbolTable);
			break;
		}
		case DIV: {
			ret = getRight()->eval(symbolTable) / getLeft()->eval(symbolTable);
			break;
		}
		case TIMES: {
			ret = getRight()->eval(symbolTable) * getLeft()->eval(symbolTable);
			break;
		}
	}
	//print();
	



	return ret;
}
