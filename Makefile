CFLAGS = -Wall -Wextra -Werror
CPPFLAGS =  -MMD
OBJPATH = obj/src/lib

all: bin/app 

test: bin/test

bin/app: obj/src/geometry/main.o obj/src/lib/libAs.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/src/lib/libAs.a: obj/src/lib/print.o obj/src/lib/calcul.o obj/src/lib/check_error.o
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

bin/test: obj/test/main.o  obj/test/test.o
	$(CC) $(CFLAGS) -L obj/src/lib -l As obj/src/lib/check_error.o -o $@ $^ -lm

obj/test/main.o: test/main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I thirdparty

obj/test/test.o: test/parser_test.c
		$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I thirdparty -I src/lib

clean: 
	rm obj/src/lib/*.o
	rm obj/src/geometry/*.o
	rm bin/app
	rm obj/src/geometry/*.d
	rm obj/src/lib/*.d
	rm obj/src/lib/lib.a

-include orj/src/geometry/main.d orj/src/lib/calcul.d orj/src/lib/check_error.d orj/src/lib/print.d