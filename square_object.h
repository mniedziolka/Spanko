#ifndef SQUARE_OBJECT_H
#define SQUARE_OBJECT_H

#include "object.h"

class SquareObstacle : public Object {
    protected:
        int length;
    public:
        SquareObstacle(int x, int y, int l);
        void update();
};

#endif
