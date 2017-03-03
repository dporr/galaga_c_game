#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

//Manejaremos enemigos en 3 grupos diferentes
enemy** enemies_r,enemies_rand,enemies_l;

void main(char* argv,int* argc){}

//generamos distintos niveles de dificultad
void level_generator(){}

//Definimos animaciones de inicio del nivel para hacerlo llamativo
void cool_r_entrance(enemy** enemies_r){}
void cool_rand_entrance(enemy** enemies_rand){}
void cool_l_entrance(enemy** enemies_l){}

//Enemigos genericos
typedef struct enemy {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  int health;
  int alive;// esta viva
  ALLEGRO_BITMAP *enemy_ship; //imagen a renderizar
} enemy_t;


//Queremos que haya un boss en ciertos niveles o cuando el usuario alcance cierto punteo
typedef struct boss {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  int health;// esta viva
  int powers;
  ALLEGRO_BITMAP *boss_ship; //imagen a renderizar
} boss_t;