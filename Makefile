all : program

program : abc.cpp main.cpp stack.h
	g++ $^ -o $@
clean : 
	rm -f *.out
