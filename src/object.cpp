#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

#include "globals.h"
#include "object.h"
#include "point.h"

Object::Object(int n, std::vector<Point> &vertices){
    this -> n = n;
    this -> vertices = vertices;
}

void Object::move(Point vec){
    for(int i = 0; i < this -> n; i++){
        this -> vertices[i] += vec;
    }
}

bool Object::check_collision(Object *p_obstacle){
    for(int k = 0; k < this -> n; k++){
        int x = this -> vertices[k].x, y = this -> vertices[k].y;
        int i, j = 0;
        bool oddNODES = false;
        for (i = 0; i < p_obstacle -> n; i++){
            j++;
            if (j == p_obstacle -> n){
                j = 0;
            }
            if (p_obstacle -> vertices[i].y < y && p_obstacle -> vertices[j].y >= y || p_obstacle -> vertices[j].y < y && p_obstacle -> vertices[i].y >= y){
                if (p_obstacle -> vertices[i].x + (y - p_obstacle -> vertices[i].y) / (p_obstacle -> vertices[j].y - p_obstacle -> vertices[i].y) * (p_obstacle -> vertices[j].x - p_obstacle -> vertices[i].x) < x){
                    oddNODES = !oddNODES;
                }
            }
        }
        if(oddNODES)
            return oddNODES;
    }
    return false;   
}

void Object::draw(){
    for(int i = 0; i < this -> n - 1; i++){
        al_draw_line(this -> vertices[i].x, this -> vertices[i].y, this -> vertices[i + 1].x, this -> vertices[i + 1].y, al_map_rgb(0, 200, 0), 4);
    }
    al_draw_line(this -> vertices[this -> n - 1].x, this -> vertices[this -> n - 1].y, this -> vertices[0].x, this -> vertices[0].y, al_map_rgb(0, 200, 0), 4);
}
