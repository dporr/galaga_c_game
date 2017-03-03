#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#define FPS 60.0
#define CANTMOV 5
#define BACK "wall.png"

enum KEYS{UP, DOWN, LEFT, RIGHT };
int teclas[4] = {0, 0, 0, 0};


typedef struct jugador {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *nave; //imagen a renderizar
} jugador_t;

typedef struct fondo {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *fnave; //imagen a renderizar
} fondo_t;

// funciones
void dibujarJugador(jugador_t *jugador);
void dibujarFondo(fondo_t *fondo);
void moverArriba(jugador_t *jugador);
void moverAbajo(jugador_t *jugador);
void moverDerecha(jugador_t *jugador);
void moverIzquierda(jugador_t *jugador);

int main(int argc, char **argv) {

  //creacion de variables
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER *timer = NULL;
  //inicializacion del librerias
  if(!al_init()) { fprintf(stderr, "%s\n", "No se pudo inicializar allegro 5"); return -1;  }
  if(!al_init_image_addon()) { fprintf(stderr,"%s\n", "No se pudo inicializar el addon"); al_destroy_display(display); return -1; }
  display = al_create_display(1000, 600);
  if(!display) { fprintf(stderr, "%s\n", "No se pudo crear un display"); al_destroy_display(display);   return -1;  } 
  if(!al_install_keyboard()) {    fprintf(stderr, "%s\n", "No se pudo instalar el teclado");   al_destroy_display(display);    return -1; }
  
  al_inhibit_screensaver(1);//evitar suspencion de pc
  al_set_window_title(display, "Space"); //titulo de la ventana
  timer = al_create_timer(1.0 / FPS); //creamos el timer

  // Creamos los eventos del juego
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  //Inicializamos al jugador principal
  jugador_t *player = (jugador_t *)malloc(sizeof(jugador_t));
  player->nave = al_load_bitmap("spacecraft.png");
  player->x = 0;
  player->y = 480;

  fondo_t *fondo = (fondo_t *)malloc(sizeof(fondo_t));
  fondo->fnave = al_load_bitmap("wall.jpg");
  fondo->x = 0;
  fondo->y = 0;
  
  if(!player->nave) {    fprintf(stderr, "%s\n", "No se pudo crear un display");
    al_destroy_display(display); al_destroy_event_queue(event_queue); al_destroy_timer(timer);
    return -1;
  }
  srand(time(NULL));
  al_start_timer(timer);//comenzamos el timer
  int terminar = 0; //teclado para salir
  ALLEGRO_EVENT ev;//variable que recive evento

  dibujarFondo(fondo);
  
  while(!terminar) {//cuerpo del juego
    al_wait_for_event(event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_KEY_UP) {
      switch(ev.keyboard.keycode) {
      case ALLEGRO_KEY_ESCAPE:	terminar = 1;   break;
      case ALLEGRO_KEY_UP:      teclas[UP]=0;	break;
      case ALLEGRO_KEY_DOWN:	teclas[DOWN]=0;	break;
      case ALLEGRO_KEY_LEFT:	teclas[LEFT]=0;	break;
      case ALLEGRO_KEY_RIGHT:	teclas[RIGHT]=0;break;
      }
    } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch(ev.keyboard.keycode) {
      case ALLEGRO_KEY_UP:	teclas[UP]=1;	break;
      case ALLEGRO_KEY_DOWN:	teclas[DOWN]=1;	break;
      case ALLEGRO_KEY_LEFT:	teclas[LEFT]=1;	break;
      case ALLEGRO_KEY_RIGHT:	teclas[RIGHT]=1;break;
      }
    } else if(ev.type == ALLEGRO_EVENT_TIMER) {
            if(teclas[UP]){	moverArriba(player);
      }else if(teclas[DOWN]){	moverAbajo(player);
      }else if(teclas[LEFT]){	moverIzquierda(player);
      }else if(teclas[RIGHT]){	moverDerecha(player);
      }
    }
    // dibujamos al jugador
  
    dibujarJugador(player);
  }
  // siempre hay que limpiar memoria
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_bitmap(fondo->fnave);
  al_destroy_bitmap(player->nave);
  al_destroy_timer(timer);
  free(player);
  return 0;
}


void dibujarJugador(jugador_t *jugador ) {
 
  al_draw_bitmap(jugador->nave, jugador->x, jugador->y, 0);
  al_flip_display();
}


void dibujarFondo(fondo_t *fondo) {
  al_draw_bitmap(fondo->fnave, fondo->x, fondo->y, 0);
  al_flip_display();
}
void moverArriba(jugador_t *jugador) {
  if(jugador->y == 0){
    jugador->y = 0;
  }else{
    jugador->y -= 10;    
  }
}
void moverAbajo(jugador_t *jugador) {
  if(jugador->y == 540){
    jugador->y = 540;
  }else{
    jugador->y += 10;    
  }
}

void moverDerecha(jugador_t *jugador){
  if(jugador->x == 950){
    jugador->x = 950;
  }else{
    jugador->x += 10;    
  } 
}
void moverIzquierda(jugador_t *jugador) {
  if(jugador->x == 0){
    jugador->x = 0;
  }else{
    jugador->x -= 10;    
  }
}
