CC = gcc
CFLAGS = -Wall -Wextra -Wwrite-strings -std=c11 -g

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(basename $(wildcard *.c))