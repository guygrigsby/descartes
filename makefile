
CCFILES = 	parseTree.cpp  \
			scanner.cpp  \
			descarte.cpp  \
			becomes.cpp   \
			expr.cpp  \
			term.cpp  \
			termTail.cpp  \
			factor.cpp  \
			factorTail.cpp \
			operator.cpp \
			error.cpp

OFILES = 	parseTree.o  \
			scanner.o  \
			descarte.o  \
			becomes.o   \
			expr.o \
			term.o  \
			termTail.o  \
			factor.o  \
			factorTail.o \
			operator.o \
			error.o

HFILES = 	parseTree.h  \
			scanner.h  \
			string.h  \
			descarte.h  \
			becomes.h   \
			expr.h \
			term.h  \
			termTail.h  \
			factor.h  \
			factorTail.h \
			operator.h \
			error.h

handout: 	
			cat  \
			becomes.h     \
			becomes.cpp     \
			divide  \
			descarte.cpp    \
			divide  \
			error.h  \
			error.cpp  \
			divide  \
			expr.h   \
			expr.cpp    \
			divide  \
			term.h    \
			term.cpp    \
			divide  \
			termTail.h    \
			termTail.cpp    \
			divide  \
			factor.h    \
			factor.cpp    \
			divide  \
			factorTail.h   \
			factorTail.cpp   \
			divide  \
			operator.h   \
			operator.cpp   \
			divide  \
			parseTree.h    \
			parseTree.cpp    \
			divide  \
			node.h \
			divide  \
			stmtnode.h \
			divide  \
			Id.h \
			| expand -4 >> all

zip: 	
			mkdir descartes
			cp  \
			becomes.h     \
			becomes.cpp     \
			descarte.cpp    \
			error.h  \
			error.cpp  \
			expr.h   \
			expr.cpp    \
			factor.h    \
			factor.cpp    \
			factorTail.h   \
			factorTail.cpp   \
			operator.h   \
			operator.cpp   \
			parseTree.h    \
			parseTree.cpp    \
			term.h    \
			term.cpp    \
			termTail.h    \
			termTail.cpp    \
			node.h \
			stmtnode.h \
			Id.h \
			scanner.h \
			scanner.cpp \
			tokens.h \
			makefile \
			descartes
			tar -zcvf descartes.tar.gz descartes

			
desc: $(OFILES)
	c++ -std=c++11 -o descarte $(OFILES) -lstdc++

descarte.o: descarte.cpp
	c++ -std=c++11 -c descarte.cpp

becomes.o: becomes.cpp
	c++ -std=c++11 -c becomes.cpp

parseTree.o: parseTree.cpp
	c++ -std=c++11 -c parseTree.cpp

scanner.o: scanner.cpp
	c++ -std=c++11 -c scanner.cpp

string.o: string.cpp
	c++ -std=c++11 -c string.cpp

expr.o:  expr.cpp
	c++ -std=c++11 -c expr.cpp

term.o:  term.cpp
	c++ -std=c++11 -c term.cpp

termTail.o:  termTail.cpp
	c++ -std=c++11 -c termTail.cpp

factor.o:  factor.cpp
	c++ -std=c++11 -c factor.cpp

factorTail.o:  factorTail.cpp
	c++ -std=c++11 -c factorTail.cpp

operator.o:  operator.cpp
	c++ -std=c++11 -c operator.cpp

error.o:  error.cpp
	c++ -std=c++11 -c error.cpp

remove: 
	rm $(OFILES)

clean: remove $(OFILES)
	c++ -std=c++11 -o descarte $(OFILES) -lstdc++

