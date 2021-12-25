SHELL=/bin/bash
CPPFLAGS = -Wall -Wextra -std=c++11
all:
	$(RM) -r bin
	mkdir bin
	$(CXX) $(CPPFLAGS) src/stress.cpp -o bin/stress -fopenmp
clean:
	$(RM) bin/*
default: all
