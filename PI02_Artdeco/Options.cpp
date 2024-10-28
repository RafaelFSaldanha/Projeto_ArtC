#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Options.h"

const int WIDTH = 1910;
const int HEIGHT = 990;

int opcoes() {

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
    ALLEGRO_FONT* font_options = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50, 0);
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
        al_draw_textf(font_tittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 205, ALLEGRO_ALIGN_CENTER, "Opções");
        al_draw_textf(font_tittle, al_map_rgb(0, 0, 0), WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, "Opções");

        al_draw_textf(font_options, al_map_rgb(r, g, b), 795, 400, ALLEGRO_ALIGN_CENTER, "Som:");
        al_draw_textf(font_options, al_map_rgb(r, g, b), 830, 500, ALLEGRO_ALIGN_CENTER, "Música:");
        al_draw_textf(font_options, al_map_rgb(r, g, b), 870, 600, ALLEGRO_ALIGN_CENTER, "Resolução:");
        al_draw_textf(font_options, al_map_rgb(r, g, b), 805, 700, ALLEGRO_ALIGN_CENTER, "Dicas:");

        al_draw_filled_circle(295, 205, 30, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300, 200, 30, al_map_rgb(196, 196, 196));
        al_draw_circle(300, 200, 30, al_map_rgb(0, 0, 0), 1.5);
        al_draw_text(font_options, al_map_rgba(0, 0, 0, 70), 297, 170, ALLEGRO_ALIGN_CENTER, "?");
        al_draw_text(font_options, al_map_rgb(0, 0, 0), 300, 167, ALLEGRO_ALIGN_CENTER, "?");
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_bitmap(moldura);
    al_destroy_font(font_tittle);
    al_destroy_font(font_options);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
