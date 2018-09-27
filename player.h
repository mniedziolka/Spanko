#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "point.h"

class Player{
    protected:
        Point nose;
    public:
        ALLEGRO_BITMAP* model = nullptr;
        int speed;
        Player(Point nose);
        Point get_lwing();
        Point get_rwing();
        Point get_rear();
        void update();
        void move(int vx, int vy);
};

#endif