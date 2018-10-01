#include <allegro5/allegro_image.h>

#include "player.h"
#include "globals.h"
#include "point.h"

/*Player::Player(int n, std::vector<Point> &vertices){
    this -> n = n;
    this -> vertices = vertices;
}*/

bool Player::is_on_display(){
    for(int i = 0; i < this -> n; i++){
        if((this -> vertices[i].x < 0 || this -> vertices[i].y < 0) || this -> vertices[i].x > WIDTH || this -> vertices[i].y > HEIGHT){
            return false;
        }
    }
    return true;
}