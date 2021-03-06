
CCFILES = 	$(wildcard *.cpp)

OFILES = 	$(patsubst %.cpp,%.o,$(CCFILES))
		
desc: $(OFILES) clean
	c++ -o descarte -g $(OFILES) -lstdc++

$(OFILES): $(CCFILES)
	c++ -std=c++11 -c -g $(CCFILES)

.PHONY: clean
	clean:
	rm *.o

