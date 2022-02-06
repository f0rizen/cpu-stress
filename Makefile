SHELL=/bin/bash
CXXFLAGS = -Wall -Wextra -std=c++11
all:
	$(RM) -r build
	mkdir build
	$(CXX) $(CXXFLAGS) src/stress.cpp -o build/stress -fopenmp -lboost_program_options
clean:
	$(RM) build/*
default: all
