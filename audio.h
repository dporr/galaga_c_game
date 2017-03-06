#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#ifndef AUDIO_H_
#define AUDIO_H_
void aud(const char *filename){
  ALLEGRO_SAMPLE *sample=NULL;
  if(!al_init())             fprintf(stderr, "Error 001\n"); 
  if(!al_install_audio())    fprintf(stderr, "Error 002\n");
  if(!al_init_acodec_addon())fprintf(stderr, "Error 003\n");
  if (!al_reserve_samples(1))fprintf(stderr, "Error 004\n");
  sample = al_load_sample(filename);
  if (!sample)               printf( "Audio clip sample not loaded!\n" );
  /* Loop the sample until the display closes. */
  al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
  //  al_rest(5.0); 
  //al_destroy_sample(sample);
}
/*                                                                                                                                               
ERRORES                                                                                                                                        
001 -> Failed to initialize allegro!                                                                                                           
002 -> Failed to initialize audio!                                                                                                              
003 -> Failed to initialize audio codecs!                                                                                                       004 -> Failed to reserve sambles! 
*/
#endif
