#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Vanguardas.h"

const int WIDTH = 1910;
const int HEIGHT = 990;

int vanguardas() {

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();

    ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
    al_set_window_position(display, 10, 30);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT* font_tittle = al_load_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70, 0);
    ALLEGRO_FONT* font_options = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 30, 0);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    ALLEGRO_BITMAP* pincel_cursor = al_load_bitmap("./assets/img/cursor.png");
    ALLEGRO_MOUSE_CURSOR* cursor = al_create_mouse_cursor(pincel_cursor, 0, 0);
    al_set_mouse_cursor(display, cursor);
    al_show_mouse_cursor(display);
    ALLEGRO_BITMAP* moldura = al_load_bitmap("./assets/img/Moldura.png");
    int novaTela = 1;
    while (true) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;
        

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -70, 2150, 1160, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 205, ALLEGRO_ALIGN_CENTER, "Vanguardas");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, "Vanguardas");

        if (mouseX > WIDTH / 4 - 200 && mouseX < WIDTH / 4 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 4 - 200, 300, WIDTH / 4 + 200, 525, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 4, 400, ALLEGRO_ALIGN_CENTER, "Renascentismo");

        if (mouseX > WIDTH / 4 - 200 && mouseX < WIDTH / 4 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 4 - 200, 575, WIDTH / 4 + 200, 800, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 4, 675, ALLEGRO_ALIGN_CENTER, "Cubismo");

        if (mouseX > WIDTH / 2 - 200 && mouseX < WIDTH / 2 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 2 - 200, 300, WIDTH / 2 + 200, 525, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2, 400, ALLEGRO_ALIGN_CENTER, "Impressionismo");

        if (mouseX > WIDTH / 2 - 200 && mouseX < WIDTH / 2 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 2 - 200, 575, WIDTH / 2 + 200, 800, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2, 675, ALLEGRO_ALIGN_CENTER, "Futurismo");

        if (mouseX > WIDTH / 2 + WIDTH / 4 - 200 && mouseX < WIDTH / 2 + WIDTH / 4 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 2 + WIDTH / 4 - 200, 300, WIDTH / 2 + WIDTH / 4 + 200, 525, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2 + WIDTH / 4, 400, ALLEGRO_ALIGN_CENTER, "Surrealismo");

        if (mouseX > WIDTH / 2 + WIDTH / 4 - 200 && mouseX < WIDTH / 2 + WIDTH / 4 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 2;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(WIDTH / 2 + WIDTH / 4 - 200, 575, WIDTH / 2 + WIDTH / 4 + 200, 800, al_map_rgb(255, 255, 255));
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2 + WIDTH / 4, 675, ALLEGRO_ALIGN_CENTER, "Expressionismo");

        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_bitmap(moldura);
    al_destroy_font(font_tittle);
    al_destroy_font(font_options);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return novaTela;
}
