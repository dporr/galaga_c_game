#define MAX_ENEMIES 12

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
//Prototipo funciones
void dibujarEnemigo(enemy_t *jugador);
void level_generator(enemy_t** enemies_r);
//Manejaremos enemigos en 3 grupos diferentes
enemy_t** enemies_r,enemies_rand,enemies_l;
//Definimos animaciones de inicio del nivel para hacerlo llamativo
void cool_r_entrance(enemy_t** enemies_r){}
void cool_rand_entrance(enemy_t** enemies_rand){}
void cool_l_entrance(enemy_t** enemies_l){}
void dibujarEnemigo(enemy_t *jugador) {
  al_draw_bitmap(jugador->enemy_ship, jugador->x, jugador->y, 0);
  al_flip_display();
}


//generamos distintos niveles de dificultad
void level_generator(enemy_t** enemies_r){//,enemy_t** enemies_rand,enemy_t** enemies_l){
  for(int i=0;i<4;i++){
    enemies_r = (enemy_t** )malloc(sizeof(enemies_r));
    (enemies_r[i])->enemy_ship = al_load_bitmap("spacecraft.png");
    (enemies_r[i])->x = 200 + (100 * i);
    (enemies_r[i])->y = 200 + (100 * i);
    (enemies_r[i])->health = 1;
    (enemies_r[i])->alive = 1;
    dibujarEnemigo((enemies_r[i]));
  }
}