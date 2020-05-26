CC=cc

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

CFLAGS=-std=c11 -Wall -Wextra -Werror -pedantic -O2 `pkg-config --cflags gtk+-3.0 flatpak`
LDFLAGS=-O2 `pkg-config --libs gtk+-3.0 flatpak`

flatpkmngr: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) flatpkmngr
