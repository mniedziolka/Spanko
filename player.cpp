#include <allegro5/allegro_image.h>

#include "player.h"
#include "globals.h"

Player::Player(int nose_x, int nose_y){
    this -> nose_x = nose_x;
    this -> nose_y = nose_y;
    this -> lwing_x = nose_x - 45;
    this -> lwing_y = nose_y - 21;
    this -> rwing_x = nose_x - 45;
    this -> rwing_y = nose_y + 21;
    this -> rear_x = nose_x - 61;
    this -> speed = 5;
    this -> model = al_load_bitmap("pic/spaceship.png");
}

void Player::update(){
    al_draw_bitmap(this -> model, this -> rear_x, this -> lwing_y, 0);
}

void Player::move(int vx, int vy){
    if (nose_x + vx <= WIDTH && rear_x + vx >= 0){
        this -> nose_x += vx;
        this -> lwing_x += vx;
        this -> rwing_x += vx;
        this -> rear_x += vx;
    }
    if (lwing_y + vy >= 0 && rwing_y + vy <= HEIGHT){
        this -> nose_y += vy;
        this -> lwing_y += vy;
        this -> rwing_y += vy;
    }
}
