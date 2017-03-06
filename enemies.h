#include <stdlib.h>
#define ENEMY_SHIP "res/enem.png"
#define BULLET_IMG "res/bullet.png"
#define MAX_BULLETS 15
#define ROWS 3
#define MAX_ROW 5
#define MAX_ENEMIES 25
int c_enemies=0;
int n_bullets=0;
int r_x  = 1;
int r_y  = 1;
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
void move_rand(enemy_t* shooter);
void display_bullet();
enemy_t** enemies;
enemy_t** init_enemies(){
  bullets =(bullet_t**) malloc(sizeof(bullet_t*) * MAX_BULLETS);
  enemies = (enemy_t**) malloc(sizeof(enemy_t*) * MAX_ENEMIES);
  int update_y_pos = 0;
  int update_x_pos = 0;
  if(enemies){
    for(int j = 0;j<MAX_ENEMIES;j++){
      enemies[j] = (enemy_t*) malloc(sizeof(enemy_t) * MAX_ROW);
      (enemies[j])->ship = al_load_bitmap(ENEMY_SHIP);
      (enemies[j])->x = 40 + update_x_pos ;
      (enemies[j])->y = 40 + update_y_pos;
       update_x_pos += ((rand()% 135) + 110);
      if(!(j%5)) {
        update_y_pos = (j * 10);
        update_x_pos = (rand() % 35) + 12;
      }
      }
    }
  return enemies;
}

void display_enemies() {
  //Move up to 5 enemies randonmly per timer ticki
   int move = rand() % 6;
  if(rand()%20 == 0){
    for(int i =0;i<move;i++){
      //randomly move
      move_rand((enemies[rand()%(MAX_ENEMIES)]));
    }
}

  for(int j = 0;j<MAX_ENEMIES;j++){
        al_draw_scaled_bitmap((enemies[j])->ship,
        0,0,50,56,
        (enemies[j])->x,
        (enemies[j])->y,
        30,30,ALLEGRO_FLIP_VERTICAL);
  }
  //Cada vez que actualizo una pantalla disparo
  if(rand()%35 == 0){
    //who will shot?
    shot((enemies[rand()%MAX_ENEMIES]));
  }else{
  }
}

void move_rand(enemy_t* shooter){  
  enemy_t* m = shooter;
  if(m->x>=500)  r_x=-1;
  if(m->y>=300)  r_y=-1;
  if(m->x <= 0)  r_x=1;
  if(m->y <= 0)  r_y=1;
  m->x = m->x + (r_x * (rand() % 80)+ 20);
  m->y = m->y + (r_y * (rand() % 40) + 20);
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