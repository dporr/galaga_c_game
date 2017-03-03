CC=gcc
CFLAGS=-Wall -I/usr/local/include -L/usr/local/lib
ALLEGRO_CFLAGS=-Wall -I/usr/local/include -L/usr/local/lib -lallegro_image -lallegro

juego: juego.c
	$(CC) juego.c -o juego $(ALLEGRO_CFLAGS)

.PHONY: clean
clean:
	$(RM) program eccentric bit_ops bit_count editor juego
