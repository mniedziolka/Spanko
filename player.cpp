#include <allegro5/allegro_image.h>

#include "player.h"
#include "globals.h"
#include "point.h"

Player::Player(Point nose){
    this -> nose = nose;
    this -> speed = 5;
    this -> model = al_load_bitmap("pic/spaceship.png");
}

Point Player::get_lwing(){
    return Point(-45, -21) += nose;
}

Point Player::get_rwing(){
    return Point(-45, 21) += nose;
}

Point Player::get_rear(){
    return Point(-61, 0) += nose;
}

void Player::update(){
    al_draw_bitmap(this -> model, this -> get_rear().x, this -> get_lwing().y, 0);
}

void Player::move(int vx, int vy){
    if ((this -> nose).x + vx <= WIDTH && this -> get_rear().x + vx >= 0)
        this -> nose.x += vx;
    if (this -> get_lwing().y + vy >= 0 && this -> get_rwing().y + vy <= HEIGHT)
        this -> nose.y += vy;
}
