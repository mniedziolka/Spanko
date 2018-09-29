#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "object.h"
#include "point.h"

class Player : public Object{
    public:
        float speed = 5.0;
        Player(int n, std::vector<Point> &vertices) : Object(n, vertices) {}
        bool is_on_display();
};

#endif