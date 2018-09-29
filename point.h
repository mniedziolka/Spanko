#ifndef POINT_H
#define POINT_H

class Point{
    public:
        float x, y;
        Point(float x, float y);
        Point();
        Point& operator+=(const Point& a){
            this -> x += a.x;
            this -> y += a.y;
            return *this;
        }
};

#endif