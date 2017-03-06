#include <stdlib.h>
#define ENEMY_SHIP "res/enem.png"
#define BULLET_IMG "res/bullet.png"
#define MAX_BULLETS 15
#define ROWS 3
#define MAX_ROW 5
//Enemigos genericos
typedef struct enemy {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *ship; //imagen a renderizar
} enemy_t;
typedef struct bullet {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *bullet_bmp; //imagen a renderizar
} bullet_t;
bullet_t** bullets;
int n_bullets=0;
//Queremos que haya un boss en ciertos niveles o cuando el usuario alcance cierto punteo
typedef struct boss {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  int health;// esta viva
  int powers;
  ALLEGRO_BITMAP *boss_ship; //imagen a renderizar
} boss_t;
//Prototipo funciones
void display_enemies();
enemy_t** init_enemies();
void shot(enemy_t* shooter);
void display_bullet();
enemy_t** enemies;
enemy_t** init_enemies(){
  bullets =(bullet_t**) malloc(sizeof(bullet_t*) * MAX_BULLETS);
  enemies = (enemy_t**) malloc(sizeof(enemy_t*) * ROWS);
  if(enemies){
    for(int j = 0;j<MAX_ROW;j++){
      enemies[j] = (enemy_t*) malloc(sizeof(enemy_t) * MAX_ROW);
      for(int k = 0;k<ROWS;k++){
        (enemies[j][k]).ship = al_load_bitmap(ENEMY_SHIP);;
        (enemies[j][k]).x = 40 + (j * 180);
        (enemies[j][k]).y = 10 + (k * 80);
      }
    }
  }
  return enemies;
}

void display_enemies() {
  for(int j = 0;j<MAX_ROW;j++){
    for(int k = 0;k<ROWS;k++){
     //(enemies[j][k]).x += (rand()%3) * ((rand()%4));
     //clea(enemies[j][k]).y += (rand()%5) * ((rand()%4));
      al_draw_bitmap((enemies[j][k]).ship, 
        (enemies[j][k]).x,
        (enemies[j][k]).y,
        ALLEGRO_FLIP_VERTICAL);
    }
  }
  //Cada vez que actualizo una pantalla disparo
  if(rand()%35 == 0){
    //who will shot?
    shot(&(enemies[rand()%5][rand()%3]));
  }else{
  }
}

void shot(enemy_t* shooter){  
  if(n_bullets<MAX_BULLETS){
      bullets[n_bullets] = (bullet_t*) malloc(sizeof(bullet_t));
      (bullets[n_bullets])->x = shooter->x + 10;
      (bullets[n_bullets])->y = shooter->y + 10;
      (bullets[n_bullets])->bullet_bmp = al_load_bitmap(BULLET_IMG);
      n_bullets++;
  }
  display_bullet();
}

void display_bullet(){
  if(n_bullets<MAX_BULLETS){
    for(int j = 0;j<n_bullets;j++){
      if(!((bullets[j])->y >= 600)){
        (bullets[j])->y+=10;
        al_draw_scaled_bitmap((bullets[j])->bullet_bmp,
        0,0,128,128,
        (bullets[j])->x,(bullets[j])->y,
        20,20,ALLEGRO_FLIP_VERTICAL); 
        //free(bullets[j])
        //bullets[j] = (bullet_t*) malloc(sizeof(bullet_t));;
        continue;
      }
      if(j < n_bullets-1){
        bullets[j] = bullets[j+1];
        j--;
        n_bullets--;
      }
    }
  }
}