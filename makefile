gom: build build/main.o build/function.o 

		gcc build/main.o build/function.o -o gom

build/main.o: src/main.c

		gcc -Wall -Werror -std=c99 -c src/main.c -o build/main.o

build/function.o: src/function.c

		 gcc -Wall -Werror  -std=c99 -c src/function.c -o build/function.o


