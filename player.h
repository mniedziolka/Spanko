#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Player{
    protected:
        int nose_x, nose_y;
        int lwing_x, lwing_y;
        int rwing_x, rwing_y;
        int rear_x;
    public:
        ALLEGRO_BITMAP* model = nullptr;
        int speed;
        Player(int nose_x, int nose_y);
        void update();
        void move(int vx, int vy);
};

#endif