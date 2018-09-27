#include <vector>

#include "object.h"
#include "point.h"

Object::Object(int n, std::vector<Point> &vertices){
    this -> n = n;
    this -> vertices = vertices;
}

void Object::move(Point vec){
    for(int i = 0; i < n; i++){
        this -> vertices[i] += vec;
    }
}

bool Object::check_collision(Object obstacle){
    
}
