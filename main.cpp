#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Obstacle {
    public:
        int x, y;
        void move(int vx, int vy){
            x += vx;
            y += vy;
        }
};

class SquareObstacle : public Obstacle {
    public:
        int length;
        SquareObstacle(int x, int y, int l){
            this -> x = x;
            this -> y = y;
            this -> length = l;
            al_draw_filled_rectangle(this -> x, this -> y, this -> x + this -> length, this -> y + this -> length, al_map_rgb(255, 255, 255));
        }

        void update(){
            al_draw_filled_rectangle(this -> x, this -> y, this -> x + this -> length, this -> y + this -> length, al_map_rgb(255, 255, 255));
        }
};

enum KEYS{UP, DOWN, LEFT, RIGHT};
bool keys[4];

class PLAYER{
        int pos_x;
        int pos_y;
        int size = 20;
        int speed = 5;
    public:
        PLAYER (int x, int y){
            pos_x = x;
            pos_y = y;
            al_draw_filled_rectangle(pos_x, pos_y, pos_x + size, pos_y + size, al_map_rgb(255, 255, 255));
        }
        void move_up(){
            pos_y -= speed;
        }
        void move_down(){
            pos_y += speed;
        }
        void move_left(){
            pos_x -= speed;
        }
        void move_right(){
            pos_x += speed;
        }
        void update(){
            al_draw_filled_rectangle(pos_x, pos_y, pos_x + size, pos_y + size, al_map_rgb(255, 255, 255));
        }
};

void must_init(bool test, const char *desc){
    if (test) return;
    
    printf("couldn't initialize %s\n", desc);
    exit(-1);
}

int main(int argc, char **argv){

    //initialize allegro
    must_init(al_init(), "allegro");

    //install keyboard
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_KEYBOARD_STATE keyboard;

    //create display
    ALLEGRO_DISPLAY* display = nullptr;

    display = al_create_display(960, 540);
    al_set_window_title(display, "Check Window");
    must_init(display, "display");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    must_init(al_init_primitives_addon(), "primitives");
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    PLAYER player(0,0);

    bool redraw = true;
    bool done = false;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    SquareObstacle * test = new SquareObstacle(600, 400, 30);
    

    while(!done){
        al_wait_for_event(queue, &event);
        switch(event.type){
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                if (keys[UP]){
                    player.move_up();
                }
                if (keys[DOWN]){
                    player.move_down();
                }
                if (keys[LEFT]){
                    player.move_left();
                }
                if (keys[RIGHT]){
                    player.move_right();
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
            player.update();
            al_flip_display();
            redraw = false;
        }
    }


    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}