
all: main.cpp
	g++ -g -Wall -Werror -o main main.cpp
clean:
	$(RM) main
