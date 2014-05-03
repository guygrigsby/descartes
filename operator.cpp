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



	Expr * lhs = getLeft();
	



	return ret;
}
