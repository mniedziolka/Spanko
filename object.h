#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "point.h"

class Object {
    protected:
        int n;
        std::vector<Point> vertices;
    public:
        Object(int n, std::vector<Point> &vertices);
        void move(Point vec);
        bool check_collision(Object obstacle);
};

#endif
