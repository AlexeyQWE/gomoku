GOMOKU: build build/main.o build/function.o 

		gcc build/main.o build/function.o -o bin/GOMOKU

build/main.o: src/main.c

		gcc -Wall -Werror -c src/main.c -o build/main.o

build/function.o: src/function.c

		 gcc -Wall -Werror -c src/function.c -o build/function.o


