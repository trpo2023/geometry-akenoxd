CFLAGS = -Wall -Wextra -Werror
VPATH = src/geometry src/lib

all: app 

app: main.o check_error.o
	$(CC) $(CFLAGS)  obj/main.o obj/check_error.o -o bin/$@  -lm

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o obj/$@ -I src/lib -lm

check_error.o: check_error.c
	$(CC) -c $(CFLAGS) $< -o obj/$@