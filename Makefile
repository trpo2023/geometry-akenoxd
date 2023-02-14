all:
	gcc -Wall main.c -o app -lm
run:
	gcc -Wall main.c -o app -lm
	./app example