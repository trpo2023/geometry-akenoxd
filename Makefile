CFLAGS = -Wall -Wextra -Werror

all: app 

app: main.o check_error.o
	$(CC) $(CFLAGS) -o  bin/$@ $^ -lm

main.o: main.c
	$(CC) -c $(CFLAGS)  -o $@ $< -lm

check_error.o: check_error.c
	$(CC) -c $(CFLAGS) -o $@ $<	