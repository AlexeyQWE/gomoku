/bin/gom: build build/main.o build/function.o build/bot.o
		gcc build/main.o build/function.o build/bot.o -o bin/gom

build/main.o: src/main.c
		gcc -Wall -Werror -g -std=c99 -c src/main.c -o build/main.o

build/function.o: src/function.c
		 gcc -Wall -Werror -g -std=c99 -c src/function.c -o build/function.o

build/bot.o: src/bot.c
		 gcc -Wall -Werror -g -std=c99 -c src/bot.c -o build/bot.o


