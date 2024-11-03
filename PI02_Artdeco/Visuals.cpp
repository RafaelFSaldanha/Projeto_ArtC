#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Visuals.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int personalizacao(ALLEGRO_DISPLAY* display) {

    int now_w = al_get_display_width(display);
    int now_h = al_get_display_height(display);

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    
    al_set_window_position(display, 0, 35);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
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

    while (true) {

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
            al_acknowledge_resize(display);
            now_w = al_get_display_width(display);
            now_h = al_get_display_height(display);
        }

        float scale_x = (float)now_w / WIDTH;
        float scale_y = (float)now_h / HEIGHT;

        ALLEGRO_FONT* font_tittle = al_load_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70 * scale_y, 0);
        ALLEGRO_FONT* font_options = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50 * scale_y, 0);

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130 * scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5 * scale_x, 205 * scale_y, ALLEGRO_ALIGN_CENTER, "Personaliza��o");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_y, ALLEGRO_ALIGN_CENTER, "Personaliza��o");

        if (mouseX > now_w / 2 - 140 * scale_x && mouseX < now_w / 2 + 140 * scale_x && mouseY > 400 * scale_y && mouseY < 440 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
            }
        }
        else { b = 0; }

        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 400 * scale_y, ALLEGRO_ALIGN_CENTER, "Tela inicial");

        if (mouseX > now_w / 2 - 150 * scale_x && mouseX < now_w / 2 + 150 * scale_x && mouseY > 500 * scale_y && mouseY < 540 * scale_y) { r = 225; g = 190; b = 0; }
        else { r = 0; g = 0; b = 0; }
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 500 * scale_y, ALLEGRO_ALIGN_CENTER, "Background");

        if (mouseX > now_w / 2 - 220 * scale_x && mouseX < now_w / 2 + 220 * scale_x && mouseY > 600 * scale_y && mouseY < 640 * scale_y) { r = 225; g = 190; b = 0; }
        else { r = 0; g = 0; b = 0; }
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 600 * scale_y, ALLEGRO_ALIGN_CENTER, "Layout das fases");

        if (mouseX > now_w / 2 - 80 * scale_x && mouseX < now_w / 2 + 80 * scale_x && mouseY > 700 * scale_y && mouseY < 740 * scale_y) { r = 225; g = 190; b = 0; }
        else { r = 0; g = 0; b = 0; }
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 700 * scale_y, ALLEGRO_ALIGN_CENTER, "Extras");

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_options);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
