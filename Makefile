all:
	gcc -o rabin main.c rabin-karp.c -lm -W -Wall -ansi -pedantic -std=c11
clean:
	rm rabin