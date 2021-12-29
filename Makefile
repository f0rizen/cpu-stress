SHELL=/bin/bash
CXXFLAGS = -Wall -Wextra -std=c++11
all:
	$(RM) -r bin
	mkdir bin
	$(CXX) $(CXXFLAGS) src/stress.cpp -o bin/stress -fopenmp
clean:
	$(RM) bin/*
default: all
