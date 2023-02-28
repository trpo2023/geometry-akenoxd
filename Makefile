all: app

app: main.c
	gcc -Wall main.c -o app -lm
run:
	./app example