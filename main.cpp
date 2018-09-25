#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void check_init(bool test, const char *desc){
    if (test) return;
    
    fprintf(stderr, "couldn't initialize %s\n", desc);
    exit(-1);
}

int main(int argc, char **argv){

    //initialize allegro
    check_init(al_init(), "allegro");

    //install keyboard
    check_init(al_install_keyboard(), "keyboard");

    ALLEGRO_KEYBOARD_STATE keyboard;

    //create display
    ALLEGRO_DISPLAY* display = nullptr;

    display = al_create_display(960, 540);
    al_set_window_title(display, "Check Window");
    check_init(display, "display");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    check_init(timer, "timer");


    //initialize image
    check_init(al_init_image_addon(), "image");
    ALLEGRO_BITMAP *spaceship = al_load_bitmap("pic/spaceship.png");

    check_init(spaceship, "spaceship");
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap (spaceship,0,0,0);
    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);
    al_destroy_bitmap(spaceship);
    return 0;
}