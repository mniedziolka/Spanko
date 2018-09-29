#include <random>
#include <cstdio>

#include "obstacle.h"

inline float rand_range(int a, int b){return (rand() % (b-a+1) ) + a; }

void Obstacle::randomise(){
    srand(0xDEADBEEF);
    Point begin = this -> vertices[0];
    int n_old = this -> n;
    this -> n = rand_range(3, 10);
    printf("%d", this -> n);
    for(int i = 1; i < this -> n; i++){
        if(i > n_old - 1){
            this -> vertices.push_back(Point(rand_range(begin.x - 50, begin.x + 50), rand_range(begin.y - 50, begin.y + 50)));
        } else {
            this -> vertices[i] = Point(rand_range(begin.x - 50, begin.x + 50), rand_range(begin.y - 50, begin.y + 50));
        }
    }
}