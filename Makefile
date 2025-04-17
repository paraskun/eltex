CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c11

bit: bit.o
	gcc $(CFLAGS) -o bit.out bit.o

bit.o: bit/bit.c
	gcc $(CFLAGS) -c bit/bit.c

clean:
	rm -rf *.o
	rm -rf *.out
