all:
	gcc -Wall -Werror -std=c99 fila.h fila.o main.c -o main
mem:
	gcc -g3 -Wall -Werror -std=c99 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer fila.h fila.o main.c -o main
run:
	./main
