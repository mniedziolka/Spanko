#include <allegro5/allegro_primitives.h>

#include "square_object.h"

SquareObstacle::SquareObstacle(int x, int y, int l){
    this -> x = x;
    this -> y = y;
    this -> length = l;
    al_draw_filled_rectangle(this -> x, this -> y, this -> x + this -> length, this -> y + this -> length, al_map_rgb(255, 255, 255));
}

void SquareObstacle::update(){
    al_draw_filled_rectangle(this -> x, this -> y, this -> x + this -> length, this -> y + this -> length, al_map_rgb(255, 255, 255));
}
