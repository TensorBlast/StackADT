all: stackclient.o stack.o
	gcc -o stackclient stackclient.o stack.o

stack.o: stack.c stack.h
	gcc -c stack.c

stackclient.o: stackclient.c stack.h
	gcc -c stackclient.c