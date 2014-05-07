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
		case LT: {
			ret = (getLeft()->eval(symbolTable) < getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case LE: {
			ret = (getLeft()->eval(symbolTable) <= getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case EQ: {
			ret = (getLeft()->eval(symbolTable) == getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case GE: {
			ret = (getLeft()->eval(symbolTable) >= getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case GT: {
			ret = (getLeft()->eval(symbolTable) > getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case NE: {
			ret = (getLeft()->eval(symbolTable) != getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case AND: {
			ret = (getLeft()->eval(symbolTable) && getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
		case OR: {
			ret = (getLeft()->eval(symbolTable) || getRight()->eval(symbolTable)) ? 1 : 0;
			break;
		}
	}
	//print();



	return ret;
}
