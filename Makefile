CC=gcc
CFLAGS=-Wall -I/usr/local/include -L/usr/local/lib --debug
ALLEGRO_CFLAGS=-Wall -I/usr/local/include -L/usr/local/lib -lallegro_image -lallegro -lallegro_audio -lallegro_acodec -lallegro_primitives

juego: juego.c
	$(CC) juego.c -o juego $(ALLEGRO_CFLAGS) --debug

.PHONY: clean
clean:
	$(RM) program eccentric bit_ops bit_count editor juego
