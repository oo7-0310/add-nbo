CC = gcc
CFLAGS = -Wall -Wextra

all: add-nbo

add-nbo: add-nbo.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f add-nbo

