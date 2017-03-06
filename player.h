#define PLAYER_SHIP "res/spacecraft.png"
#define PLAYER_EXPLODE "res/expl.png"
#define P_MAX_BULLET 10
typedef struct jugador {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *nave; //imagen a renderizar
} jugador_t;

typedef struct pbullet {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *bullet_bmp; //imagen a renderizar
} pbullet_t;
pbullet_t** p_bullets;
int pn_bullets = 0;
//Prototipo funciones jugador
void dibujarJugador(jugador_t *jugador);
void moverArriba(jugador_t *jugador);
void moverAbajo(jugador_t *jugador);
void moverDerecha(jugador_t *jugador);
void moverIzquierda(jugador_t *jugador);
void draw_p_shoot();
void p_shoot();
jugador_t* player;
jugador_t* init_player(){
  jugador_t* player = (jugador_t *)malloc(sizeof(jugador_t));
  player->nave = al_load_bitmap(PLAYER_SHIP);
  player->x = 500;
  player->y = 540;
  return player;
}

//int colision(){}
void dibujarJugador(jugador_t *jugador ) {
  al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
}

void dead(jugador_t *jugador ) {
  player->nave = al_load_bitmap(PLAYER_EXPLODE);
  al_draw_scaled_bitmap(player->nave,
    0,0,256,256,
    jugador->x - 30,jugador->y - 80,
    150,150,0);
    al_flip_display();
    al_rest(1.0); 
    free(player);
    init_player();
  //al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
}

void moverArriba(jugador_t *jugador) {
  if(jugador->y <= 0){
    jugador->y = 0;
  }else{
    jugador->y -= 15;    
  }
  dibujarJugador(jugador);
}
void moverAbajo(jugador_t *jugador) {
  if(jugador->y >= 540){
    jugador->y = 540;
  }else{
    jugador->y += 15;    
  }
  dibujarJugador(jugador);
}

void moverDerecha(jugador_t *jugador){
  if(jugador->x >= 950){
    jugador->x = 950;
  }else{
    jugador->x += 15;    
  }
  dibujarJugador(jugador);
}
void moverIzquierda(jugador_t *jugador) {
  if(jugador->x <= 0){
    jugador->x = 0;
  }else{
    jugador->x -= 15 ;    
  }
  dibujarJugador(jugador);
}
<<<<<<< HEAD

void p_shoot(){  
  if(pn_bullets<P_MAX_BULLET){
    p_bullets[pn_bullets] = (pbullet_t*) malloc(sizeof(pbullet_t));
    (p_bullets[pn_bullets])->x = player->x + 10;
    (p_bullets[pn_bullets])->y = player->y + 10;
    (p_bullets[pn_bullets])->bullet_bmp = al_load_bitmap(BULLET_IMG);
    pn_bullets++;
  }
  draw_p_shoot();
}

void draw_p_shoot(){
  if(pn_bullets<P_MAX_BULLET){
    for(int j = 0;j<pn_bullets;j++){
      if(!((p_bullets[j])->y >= 600)){
        (p_bullets[j])->y+=10;
        al_draw_scaled_bitmap((p_bullets[j])->bullet_bmp,
        0,0,128,128,
        (p_bullets[j])->x,(p_bullets[j])->y,
        20,20,ALLEGRO_FLIP_VERTICAL); 
        //free(p_bullets[j])
        //p_bullets[j] = (bullet_t*) malloc(sizeof(bullet_t));;
        continue;
      }
      if(j < pn_bullets-1){
        p_bullets[j] = p_bullets[j+1];
        j--;
        pn_bullets--;
      }
    }
  }
}
=======
>>>>>>> 8082c9617579cd345a84d1ddefae27f59f1477bf
