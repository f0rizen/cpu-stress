SHELL=/bin/bash
CPPFLAGS = -Wall -Wextra -std=gnu++17
all:
	$(RM) -r bin
	mkdir bin
	g++ $(CPPFLAGS) src/stress.cpp -o bin/stress -fopenmp
clean:
	$(RM) bin/*
default: all
