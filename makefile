all: bin/gom bin/testing

bin/gom: build build/main.o build/function.o build/bot.o
	gcc build/main.o build/function.o build/bot.o -o bin/gom

build/main.o: src/main.c
	gcc -Wall -g -std=c99 -c src/main.c -o build/main.o

build/function.o: src/function.c
	gcc -Wall -g -std=c99 -c src/function.c -o build/function.o

build/bot.o: src/bot.c
	gcc -Wall -g -std=c99 -c src/bot.c -o build/bot.o

bin/testing: build/function.o build/test/main.o build/test/tests.o build/bot.o
	gcc -Wall build/function.o build/test/main.o build/test/tests.o build/bot.o -o bin/testing

build/test/main.o: test/main.c
	gcc -Wall -std=c99 -c test/main.c -o build/test/main.o -Ithirdparty 

build/test/tests.o: test/tests.c
	gcc -Wall -std=c99 -c test/tests.c -o build/test/tests.o -Ithirdparty -Isrc


