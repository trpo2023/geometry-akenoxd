CFLAGS = -Wall -Wextra -Werror
CPPFLAGS =  -MMD
OBJPATH = obj/src/lib

all: bin/app 

bin/app: obj/src/geometry/main.o obj/src/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/src/lib/lib.a: obj/src/lib/print.o obj/src/lib/calcul.o obj/src/lib/check_error.o
	ar rcs $@ $^

obj/src/geometry/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib  

obj/src/lib/print.o: src/lib/print.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib

obj/src/lib/check_error.o: src/lib/check_error.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@

obj/src/lib/calcul.o: src/lib/calcul.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -lm

.PHONY: clean

clean: 
	rm obj/src/lib/*.o
	rm obj/src/geometry/*.o
	rm bin/app
	rm obj/src/geometry/*.d
	rm obj/src/lib/*.d
	rm obj/src/lib/lib.a

-include orj/src/geometry/main.d orj/src/lib/calcul.d orj/src/lib/check_error.d orj/src/lib/print.d