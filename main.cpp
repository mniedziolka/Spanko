#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "object.h"
#include "player.h"
#include "globals.h"
#include "point.h"

enum KEYS{UP, DOWN, LEFT, RIGHT};
bool keys[4];

int main(int argc, char **argv){

    if(!al_init()){
        fprintf(stderr, "Failed to initialize allegro!\n");
        exit(-1);
    }

    if(!al_install_keyboard()){
        fprintf(stderr, "Failed to initialize keyboard!\n");
        exit(-1);
    }

    ALLEGRO_KEYBOARD_STATE keyboard;

    ALLEGRO_DISPLAY* display = nullptr;

    display = al_create_display(WIDTH, HEIGHT);
    al_set_window_title(display, "Check Window");

    if(!display){
        fprintf(stderr, "Failed to create display!\n");
        exit(-1);
    }

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    if(!timer){
        fprintf(stderr, "Failed to initialize timer!\n");
        exit(-1);
    }

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if(!queue){
        fprintf(stderr, "Failed to create event queue!\n");
        exit(-1);
    }

    if(!al_init_primitives_addon()){
        fprintf(stderr, "Failed to initialize primitives!\n");
        exit(-1);
    }
    if(!al_init_image_addon()){
        fprintf(stderr, "Failed to initialize image_addon!\n");
        exit(-1);
    }
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    bool redraw = true;
    bool done = false;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    std::vector<Point> playertemp = {Point(0, 0), Point(50, 30), Point(0, 60)};
    Player * player = new Player(3, playertemp);

    std::vector<Point> t = {Point(50, 50), Point(100, 100), Point(200, 75)};
    std::vector<Point> t2 = {Point(250, 50), Point(300, 100), Point(400, 75)};
    Object * test = new Object(3, t);
    Object * test2 = new Object(3, t2);
    
    while(!done){
        al_wait_for_event(queue, &event);
        switch(event.type){
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                if (keys[UP]){
                    player -> move(Point(0, -(player -> speed)));
                }
                if (keys[DOWN]){
                    player -> move(Point(0, player -> speed));
                }
                if (keys[LEFT]){
                    player -> move(Point(-(player -> speed), 0));
                }
                if (keys[RIGHT]){
                    player -> move(Point(player -> speed, 0));
                }
                
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_UP:
                        keys[UP] = true;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        keys[DOWN] = true;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        keys[LEFT] = true;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        keys[RIGHT] = true;
                        break;
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_UP:
                        keys[UP] = false;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        keys[DOWN] = false;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        keys[LEFT] = false;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        keys[RIGHT] = false;
                        break;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    done = true;
                break;
        }
        if (done)
            break;
        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            player -> draw();
            //test -> move(Point(2, 0)); 
            test -> draw();
            test2 -> draw();
            printf("%d", test -> check_collision(test2));
            if(player -> check_collision(test2))
                sleep(2);
            al_flip_display();
            redraw = false;
        }
    }


    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}