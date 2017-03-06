#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "audio.h"

#define AUDIO_FILE1 "res/soud03.wav"
#define SCREEN_W 1000
#define SCREEN_H 600
#ifndef GAMEOVER_H_
#define GAMEOVER_H_
void gameOver(const char *filename){
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
    aud(AUDIO_FILE1);
    al_rest(2.0);
    al_destroy_bitmap(background);
    al_destroy_display(display);
    //al_uninstall_system();  
}
/*
ERRORES
001 -> Failed to initialize allegro!
002 -> Failed to create display!
003 -> Failed to load background bitmap!
*/
#endif
