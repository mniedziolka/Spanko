#include <cstdio>
#include <allegro5/allegro.h>
<<<<<<< HEAD
#include <allegro5/allegro_primitives.h>
=======
#include <allegro5/allegro_image.h>
>>>>>>> d759468662e5d478880ed7b4dbaba0a5561f211f

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

<<<<<<< HEAD
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");
=======

    //initialize image
    check_init(al_init_image_addon(), "image");
    ALLEGRO_BITMAP *spaceship = al_load_bitmap("pic/spaceship.png");
>>>>>>> d759468662e5d478880ed7b4dbaba0a5561f211f

    must_init(al_init_primitives_addon(), "primitives");
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    int pos_x = 0;
    int pos_y = 0;

    bool redraw = true;
    bool done = false;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
    while(!done){
        printf("gowno\n");
        al_wait_for_event(queue, &event);
        printf("gowno1\n");
        switch(event.type){
            case ALLEGRO_EVENT_TIMER:
                printf("gowno1\n");
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_UP:
                        printf("gowno1\n");
                        pos_y -= 5;
                        redraw = true;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        pos_y += 5;
                        redraw = true;
                        printf("gowno1\n");
                        break;
                    case ALLEGRO_KEY_LEFT:
                        pos_x -= 5;
                        redraw = true;
                        printf("gowno1\n");
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        pos_x += 5;
                        redraw = true;
                        printf("gowno1\n");
                        break;
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                printf("gowno2\n");
                done = true;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                printf("gowno1\n");
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    done = true;
                break;
        }
        
        if (done)
            break;
        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_filled_rectangle(pos_x, pos_y, pos_x + 20, pos_y + 20, al_map_rgb(255,255,255));
            al_flip_display();
            redraw = false;
        }
    }


    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}