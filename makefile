
/bin/gom: build/main.o build/function.o build/bot_defender.o build/bot_attacking.o build/bot_easy.o
		gcc build/main.o build/function.o build/bot_defender.o build/bot_attacking.o build/bot_easy.o -o bin/gom
build/main.o: src/main.c

		gcc -Wall -Werror -g -std=c99 -c src/main.c -o build/main.o

build/function.o: src/function.c

		gcc -Wall -Werror -g -std=c99 -c src/function.c -o build/function.o

build/bot_defender.o: src/bot_defender.c

		gcc -Wall -g -std=c99 -c src/bot_defender.c -o build/bot_defender.o

build/bot_attacking.o: src/bot_attacking.c

		gcc -Wall -g -std=c99 -c src/bot_attacking.c -o build/bot_attacking.o

build/bot_easy.o: src/bot_easy.c

		gcc -Wall -g -std=c99 -c src/bot_easy.c -o build/bot_easy.o



