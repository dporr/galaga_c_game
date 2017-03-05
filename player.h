#define PLAYER_SHIP "res/spacecraft.png"

typedef struct jugador {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *nave; //imagen a renderizar
} jugador_t;
//Prototipo funciones jugador
void dibujarJugador(jugador_t *jugador);
void moverArriba(jugador_t *jugador);
void moverAbajo(jugador_t *jugador);
void moverDerecha(jugador_t *jugador);
void moverIzquierda(jugador_t *jugador);

jugador_t* player;
jugador_t* init_player(){
  jugador_t* player = (jugador_t *)malloc(sizeof(jugador_t));
  player->nave = al_load_bitmap(PLAYER_SHIP);
  player->x = 0;
  player->y = 480;
  return player;
}
void dibujarJugador(jugador_t *jugador ) {
  al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
  al_flip_display();
}

void moverArriba(jugador_t *jugador) {
  if(jugador->y == 0){
    jugador->y = 0;
  }else{
    jugador->y -= 10;    
  }
  dibujarJugador(jugador);
}
void moverAbajo(jugador_t *jugador) {
  if(jugador->y == 540){
    jugador->y = 540;
  }else{
    jugador->y += 10;    
  }
  dibujarJugador(jugador);
}

void moverDerecha(jugador_t *jugador){
  if(jugador->x == 950){
    jugador->x = 950;
  }else{
    jugador->x += 10;    
  }
  dibujarJugador(jugador);
}
void moverIzquierda(jugador_t *jugador) {
  if(jugador->x == 0){
    jugador->x = 0;
  }else{
    jugador->x -= 10;    
  }
  dibujarJugador(jugador);
}