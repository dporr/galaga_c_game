#define ENEMY_SHIP "res/spacecraft.png"
#define MAX_ENEMIES 15
#define ROWS 3
#define MAX_ROW 5
//Enemigos genericos
typedef struct enemy {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  int health;
  int alive;// esta viva
  ALLEGRO_BITMAP *ship; //imagen a renderizar
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
void display_enemies();
enemy_t** init_enemies();

enemy_t** enemies;
enemy_t** init_enemies(){
  enemies = (enemy_t**) malloc(sizeof(enemy_t*) * ROWS);
  if(enemies){
    for(int j = 0;j<MAX_ROW;j++){
      enemies[j] = (enemy_t*) malloc(sizeof(enemy_t) * MAX_ROW);
      for(int k = 0;k<ROWS;k++){
        (enemies[j][k]).ship = al_load_bitmap(ENEMY_SHIP);
        (enemies[j][k]).x = 40 + (j * 140);
        (enemies[j][k]).y = 10 + (k * 80);;
        al_draw_bitmap((enemies[j][k]).ship, (enemies[j][k]).x, (enemies[j][k]).y, ALLEGRO_FLIP_VERTICAL);
      }
    }
  }
  return enemies;
}

void display_enemies() {
  for(int j = 0;j<MAX_ROW;j++){
    for(int k = 0;k<ROWS;k++){
      al_draw_bitmap((enemies[j][k]).ship, (enemies[j][k]).x, (enemies[j][k]).y, ALLEGRO_FLIP_VERTICAL);
    }
  }
}
