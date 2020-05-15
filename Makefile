CC=cc

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

CFLAGS=-std=c11 -Wall -Wextra -pedantic `pkg-config --cflags gtk+-3.0 flatpak`
LDFLAGS=`pkg-config --libs gtk+-3.0 flatpak`

flatpkmngr: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) flatpkmngr
