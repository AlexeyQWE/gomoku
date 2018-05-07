gom: build build/main.o build/function.o build/bot.o

		gcc build/main.o build/function.o build/bot.o -o gom

build/main.o: src/main.c

		gcc -Wall -g -Werror -std=c99 -c src/main.c -o build/main.o

build/function.o: src/function.c

		 gcc -Wall -g -Werror  -std=c99 -c src/function.c -o build/function.o

build/bot.o: src/bot.c

		 gcc -Wall -g -Werror  -std=c99 -c src/bot.c -o build/bot.o


