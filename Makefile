CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
VPATH = src/geometry src/lib obj obj/src/geometry obj/src/lib bin

all: app 

app: main.o lib.a
	$(CC) $(CFLAGS) -o bin/$@ $^ -lm

lib.a: calcul.o check_error.o print.o
	ar rcs $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o obj/src/geometry/$@ -I src/lib 

print.o: print.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o obj/src/lib/$@ -I src/lib

check_error.o: check_error.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o obj/src/lib/$@

calcul.o: calcul.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o obj/src/lib/$@ -lm

clean: 
	rm obj/src/lib/*.o
	rm obj/src/geometry/*.o
	rm lib.a
	rm bin/app
	rm obj/src/geometry/*.d
	rm obj/src/lib/*.d