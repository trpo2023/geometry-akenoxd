CFLAGS = -Wall -Wextra -Werror
VPATH = src/geometry src/lib obj obj/src/geometry obj/src/lib bin

all: app 

lib.a: check_error.o 

app: main.o print_error.o check_error.o calcul.o
	$(CC) $(CFLAGS)  obj/src/geometry/main.o obj/src/lib/check_error.o obj/src/lib/print_error.o obj/src/lib/calcul.o -o bin/$@ -lm

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o obj/src/geometry/$@ -I src/lib 

print_error.o: print_error.c
	$(CC) -c $(CFLAGS) $< -o obj/src/lib/$@

check_error.o: check_error.c
	$(CC) -c $(CFLAGS) $< -o obj/src/lib/$@

calcul.o: calcul.c
	$(CC) -c $(CFLAGS) $< -o obj/src/lib/$@ -lm

clean: 
	rm obj/src/lib/*.o
	rm obj/src/geometry/*.o
	rm bin/app