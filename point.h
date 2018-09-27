#ifndef POINT_H
#define POINT_H

class Point{
    public:
        int x, y;
        Point(int x, int y);
        Point();
        Point& operator+=(const Point& a){
            this -> x += a.x;
            this -> y += a.y;
            return *this;
        }
};

#endif