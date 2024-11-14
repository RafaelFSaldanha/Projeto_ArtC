#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Vanguardas.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int vanguardas(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* noite_estrelada = al_load_bitmap("./assets/img/noite_estrelada.png");

    int novaTela = 1;
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

        ALLEGRO_FONT* font_tittle = al_load_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70 * scale_y, ALLEGRO_TTF_NO_KERNING);
        ALLEGRO_FONT* font_options = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 30 * scale_y, ALLEGRO_TTF_NO_KERNING);

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 190 * scale_x, 125 * scale_y, 1540 * scale_x, 735 * scale_y, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -180 * scale_x, -73 * scale_y, 2220 * scale_x, 1165 * scale_y, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5 * scale_x, 205 * scale_y, ALLEGRO_ALIGN_CENTER, "Vanguardas");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_y, ALLEGRO_ALIGN_CENTER, "Vanguardas");

        if (mouseX > now_w / 4 - 200 * scale_x && mouseX < now_w / 4 + 200 * scale_x && mouseY > 300 * scale_y && mouseY < 525 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 5;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 300 * scale_y, now_w / 4 + 200 * scale_x, 525 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 302 * scale_y, now_w / 4 + 198 * scale_x, 523 * scale_y, al_map_rgb(50, 116, 177));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 4, 400 * scale_y, ALLEGRO_ALIGN_CENTER, "Renascentismo");

        if (mouseX > now_w / 4 - 200 * scale_x && mouseX < now_w / 4 + 200 * scale_x && mouseY > 575 * scale_y && mouseY < 800 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 9;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 575 * scale_y, now_w / 4 + 200 * scale_x, 800 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 577 * scale_y, now_w / 4 + 198 * scale_x, 798 * scale_y, al_map_rgb(44, 95, 146));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 4, 675 * scale_y, ALLEGRO_ALIGN_CENTER, "Cubismo");

        if (mouseX > now_w / 2 - 200 * scale_x && mouseX < now_w / 2 + 200 * scale_x && mouseY > 300 * scale_y && mouseY < 525 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 6;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 200 * scale_x, 300 * scale_y, now_w / 2 + 200 * scale_x, 525 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 198 * scale_x, 302 * scale_y, now_w / 2 + 198 * scale_x, 523 * scale_y, al_map_rgb(65, 108, 147));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 400 * scale_y, ALLEGRO_ALIGN_CENTER, "Impressionismo");

        if (mouseX > now_w / 2 - 200 * scale_x && mouseX < now_w / 2 + 200 * scale_x && mouseY > 575 * scale_y && mouseY < 800 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 10;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 200 * scale_x, 575 * scale_y, now_w / 2 + 200 * scale_x, 800 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 198 * scale_x, 577 * scale_y, now_w / 2 + 198 * scale_x, 798 * scale_y, al_map_rgb(38, 63, 106));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 675 * scale_y, ALLEGRO_ALIGN_CENTER, "Futurismo");

        if (mouseX > now_w / 2 + now_w / 4 - 200 * scale_x && mouseX < now_w / 2 + now_w / 4 + 200 * scale_x && mouseY > 300 * scale_y && mouseY < 525 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 7;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + now_w / 4 - 200 * scale_x, 300 * scale_y, now_w / 2 + now_w / 4 + 200 * scale_x, 525 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + now_w / 4 - 198 * scale_x, 302 * scale_y, now_w / 2 + now_w / 4 + 198 * scale_x, 523 * scale_y, al_map_rgb(47, 93, 133));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2 + now_w / 4, 400 * scale_y, ALLEGRO_ALIGN_CENTER, "Surrealismo");

        if (mouseX > now_w / 2 + now_w / 4 - 200 * scale_x && mouseX < now_w / 2 + now_w / 4 + 200 * scale_x && mouseY > 575 * scale_y && mouseY < 800 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 8;
                break;

            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + now_w / 4 - 200 * scale_x, 575 * scale_y, now_w / 2 + now_w / 4 + 200 * scale_x, 800 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + now_w / 4 - 198 * scale_x, 577 * scale_y, now_w / 2 + now_w / 4 + 198 * scale_x, 798 * scale_y, al_map_rgb(47, 85, 151));
        al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2 + now_w / 4, 675 * scale_y, ALLEGRO_ALIGN_CENTER, "Expressionismo");

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_options);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return novaTela;
}