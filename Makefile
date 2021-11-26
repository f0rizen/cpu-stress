SHELL=/bin/bash
CPPFLAGS = -Wall -Wextra
all:
	$(RM) -r bin
	mkdir bin
	g++ $(CPPFLAGS) src/stress.cpp -o bin/stress -fopenmp
clean:
	$(RM) bin/*
default: all
