CPPFLAGS = -Wall -Wextra
all:
	g++ $(CPPFLAGS) ./src/stress.cpp -o ./bin/stress -fopenmp
clean:
	$(RM) ./bin/*
default: all
