CC     = gcc
CFLAGS = -Wall -Wextra -Wwrite-strings -std=c11 -g

SRCS = main.c bits.c
OBJS = $(SRCS:.c=.o)
TARGET = app

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c bits.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)