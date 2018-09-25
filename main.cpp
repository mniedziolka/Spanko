#include <cstdio>
#include <allegro5/allegro.h>

int main(int argc, char **argv){

    //initialize allegro
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    //install keyboard
    if(!al_install_keyboard()){
        fprintf(stderr, "failed to install keyboard\n");
        return -1;
    }
    ALLEGRO_KEYBOARD_STATE keyboard;

    //create display
    ALLEGRO_DISPLAY *display = nullptr;

    display = al_create_display(1200, 900);
    al_set_window_title( display,"Check Window");
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);

    return 0;
}