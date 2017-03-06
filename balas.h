#include <stdio.h>
#define BULLET_IMG "res/bullet.png"
#define MAX_BALAS 15
#ifndef BALAS_H_
#define BALAS_H_

typedef struct balas {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *balas_bmp; //imagen a renderizar
} balas_t;
balas_t** balas;
int n_balas=0;

void bal(){

  balas  =(balas_t**) malloc(sizeof(balas_t*) * MAX_BALAS);
    if(n_balas<MAX_BALAS){
    for(int j = 0;j<n_balas;j++){
      if((balas[j])->y <= 0){
        n_balas++;
        continue;
        //free(bullets[j])
        //bullets[j] = (bullet_t*) malloc(sizeof(bullet_t));;
      }
      (balas[j])->y-=10;
      al_draw_scaled_bitmap((balas[j])->balas_bmp,0,0,128,128,(balas[j])->x,(balas[j])->y,20,20,ALLEGRO_FLIP_VERTICAL); 
    }
  }
}

#endif
