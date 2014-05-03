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
			ret = getLeft()->eval(symbolTable) + getRight()->eval(symbolTable);
			break;
		}
		case MINUS: {
			ret = getLeft()->eval(symbolTable) - getRight()->eval(symbolTable);
			break;
		}
		case DIV: {
			ret = getLeft()->eval(symbolTable) / getRight()->eval(symbolTable);
			break;
		}
		case TIMES: {
			ret = getLeft()->eval(symbolTable) * getRight()->eval(symbolTable);
			break;
		}
	}
	//print();
	



	return ret;
}
