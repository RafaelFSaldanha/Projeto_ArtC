#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Carrossel.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int carrossel(ALLEGRO_DISPLAY* display) {

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();

    al_set_window_position(display, 0, 35);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT* font_tittle = al_load_ttf_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70, ALLEGRO_TTF_NO_KERNING);
    ALLEGRO_FONT* font_options = al_load_ttf_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50, ALLEGRO_TTF_NO_KERNING);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    ALLEGRO_BITMAP* pincel_cursor = al_load_bitmap("./assets/img/cursor.png");
    ALLEGRO_MOUSE_CURSOR* cursor = al_create_mouse_cursor(pincel_cursor, 0, 0);
    al_set_mouse_cursor(display, cursor);
    al_show_mouse_cursor(display);
    ALLEGRO_BITMAP* moldura = al_load_bitmap("./assets/img/moldura2.png");
    ALLEGRO_BITMAP* noite_estrelada = al_load_bitmap("./assets/img/noite_estrelada.png");

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
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 230, 125, 1500, 735, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -73, 2160, 1165, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 205, ALLEGRO_ALIGN_CENTER, u8"Opções");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, u8"Opções");

        al_draw_text(font_options, al_map_rgb(r, g, b), 795, 400, ALLEGRO_ALIGN_CENTER, u8"Som:");
        al_draw_text(font_options, al_map_rgb(r, g, b), 830, 500, ALLEGRO_ALIGN_CENTER, u8"Música:");
        al_draw_text(font_options, al_map_rgb(r, g, b), 870, 600, ALLEGRO_ALIGN_CENTER, u8"Resolução:");
        al_draw_text(font_options, al_map_rgb(r, g, b), 805, 700, ALLEGRO_ALIGN_CENTER, u8"Dicas:");

        if (mouseX > 270 && mouseX < 330 && mouseY > 170 && mouseY < 230) {
            r = 228;
            g = 195;
            b = 78;
            if (mouseB == 1) {
                r = 196; g = 196; b = 196;
            }
        }
        else { r = 196; g = 196; b = 196; }

        al_draw_filled_circle(295, 205, 30, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300, 200, 30, al_map_rgb(r, g, b));
        al_draw_circle(300, 200, 30, al_map_rgb(0, 0, 0), 1.5);
        al_draw_text(font_options, al_map_rgba(0, 0, 0, 70), 297, 170, ALLEGRO_ALIGN_CENTER, "?");
        al_draw_text(font_options, al_map_rgb(0, 0, 0), 300, 167, ALLEGRO_ALIGN_CENTER, "?");

        al_flip_display();
    }

    al_destroy_bitmap(moldura);
    al_destroy_font(font_tittle);
    al_destroy_font(font_options);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
