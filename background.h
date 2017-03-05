#define BACK "res/wall.jpg"
typedef struct fondo {
  int x; // posicion x de la nave
  int y; // posicion y de la nave
  ALLEGRO_BITMAP *bg_image; //imagen a renderizar
} fondo_t;

fondo_t *fondo;
fondo_t* init_background(){
  fondo = (fondo_t *)malloc(sizeof(fondo_t));
  fondo->bg_image = al_load_bitmap(BACK);
  fondo->x = 0;
  fondo->y = 0;
  al_draw_bitmap(fondo->bg_image, 0, 0, 0);
  return fondo;
}

void dibujarFondo() {
  al_draw_bitmap(fondo->bg_image, fondo->x, fondo->y, 0);
}