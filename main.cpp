#include <cstdio>
#include <allegro5/allegro.h>

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

    display = al_create_display(1200, 900);
    al_set_window_title(display, "Check Window");
    must_init(display, "display")

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);

    return 0;
}