#include <random>
#include <cstdio>

#include "obstacle.h"

inline float rand_range(int a, int b){return (rand() % (b-a+1) ) + a; }

void Obstacle::randomise(unsigned int seed){
    srand(seed);
    Point begin = Point(rand_range(900, 1300), rand_range(100, 400));
    vertices[0] = begin;
    int n_old = this -> n;
    this -> n = rand_range(3, 10);
    for(int i = 1; i < this -> n; i++){
        if(i > n_old - 1){
            this -> vertices.push_back(Point(rand_range(begin.x - 50, begin.x + 50), rand_range(begin.y - 50, begin.y + 50)));
        } else {
            this -> vertices[i] = Point(rand_range(begin.x - 50, begin.x + 50), rand_range(begin.y - 50, begin.y + 50));
        }
    }
}

bool Obstacle::is_on_display(){
    for(int i = 0; i < this -> n; i++){
        if((this -> vertices[i].x > 0 && this -> vertices[i].y > 0) /*&& this -> vertices[i].x < WIDTH &&  this -> vertices[i].y < HEIGHT*/){
            return true;
        }
    }
    return false;
}