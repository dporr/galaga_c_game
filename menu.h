#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "audio.h"

#define AUDIO_FILE "res/soud01.wav"
#define SCREEN_W 1000
#define SCREEN_H 600
#ifndef MENU_H_
#define MENU_H_
void menu(const char *filename){
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP  *background=NULL;
    if(!al_init()) fprintf(stderr, "Errror 001\n");
    al_init_image_addon();
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display) fprintf(stderr, "Error 002\n");
    background=al_load_bitmap(filename);
    if(!background)fprintf(stderr, "Error 003\n");
    al_draw_bitmap(background,0,0,0);
    al_flip_display();
    aud(AUDIO_FILE);
    al_rest(3.0);
    al_destroy_display(display);
    al_destroy_bitmap(background);
    al_uninstall_system();  
}
/*
ERRORES
001 -> Failed to initialize allegro!
002 -> Failed to create display!
003 -> Failed to load background bitmap!
*/
#endif
