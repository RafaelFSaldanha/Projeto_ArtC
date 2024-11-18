#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Options.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int opcoes(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* seta = al_load_bitmap("./assets/img/seta.png");
    ALLEGRO_BITMAP* back = al_load_bitmap("./assets/img/back.png");
    int novaTela = 0;

    int telaNova = 1;

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

        ALLEGRO_FONT* font_tittle = al_load_ttf_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70 * scale_y, ALLEGRO_TTF_NO_KERNING);
        ALLEGRO_FONT* font_options = al_load_ttf_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50 * scale_y, ALLEGRO_TTF_NO_KERNING);
        ALLEGRO_FONT* font_options2 = al_load_ttf_font("./assets/fonts/MontserratAlternates-Regular.ttf", 20 * scale_y, ALLEGRO_TTF_NO_KERNING);
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
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5 * scale_x, 205 * scale_y, ALLEGRO_ALIGN_CENTER, "Opções");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_y, ALLEGRO_ALIGN_CENTER, "Opções");

        al_draw_filled_rectangle(now_w / 2 - 325 * scale_x, 400 * scale_y, now_w / 2 - 160 * scale_x, 465 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 323 * scale_x, 402 * scale_y, now_w / 2 - 162 * scale_x, 463 * scale_y, al_map_rgb(57, 112, 170));
        al_draw_text(font_options, al_map_rgb(r, g, b), 650 * scale_x, 400 * scale_y, 0, "Som:");

        al_draw_filled_rectangle(now_w / 2 + 20 * scale_x, 430 * scale_y, now_w / 2 + 300 * scale_x, 435 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_circle(now_w / 2 + 100 * scale_x, 432.5 * scale_y, 15 * scale_y, al_map_rgb(228, 195, 78));


        al_draw_filled_rectangle(now_w / 2 - 325 * scale_x, 500 * scale_y, now_w / 2 - 90 * scale_x, 565 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 323 * scale_x, 502 * scale_y, now_w / 2 - 92 * scale_x, 563 * scale_y, al_map_rgb(47, 93, 133));
        al_draw_text(font_options, al_map_rgb(r, g, b), 650 * scale_x, 500 * scale_y, 0, "Música:");

        al_draw_filled_rectangle(now_w / 2 + 20 * scale_x, 530 * scale_y, now_w / 2 + 300 * scale_x, 535 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_circle(now_w / 2 + 100 * scale_x, 532.5 * scale_y, 15 * scale_y, al_map_rgb(228, 195, 78));


        al_draw_filled_rectangle(now_w / 2 - 325 * scale_x, 600 * scale_y, now_w / 2 - 10 * scale_x, 665 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 323 * scale_x, 602 * scale_y, now_w / 2 - 12 * scale_x, 663 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_options, al_map_rgb(r, g, b), 650 * scale_x, 600 * scale_y, 0, "Resolução:");

        al_draw_filled_rectangle(now_w / 2 + 20 * scale_x, 600 * scale_y, now_w / 2 + 220 * scale_x, 665 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 21 * scale_x, 601 * scale_y, now_w / 2 + 219 * scale_x, 664 * scale_y, al_map_rgb(47, 106, 166));
        al_draw_scaled_bitmap(seta, 0, 0, al_get_bitmap_width(seta), al_get_bitmap_height(seta), now_w / 2 + 190 * scale_x, 625 * scale_y, 20 * scale_x, 17 * scale_y, 0);


        al_draw_filled_rectangle(now_w / 2 - 325 * scale_x, 700 * scale_y, now_w / 2 - 140 * scale_x, 765 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 323 * scale_x, 702 * scale_y, now_w / 2 - 142 * scale_x, 763 * scale_y, al_map_rgb(45, 95, 157));
        al_draw_text(font_options, al_map_rgb(r, g, b), 650 * scale_x, 700 * scale_y, 0, "Dicas:");

        al_draw_filled_rectangle(now_w / 2 + 20 * scale_x, 700 * scale_y, now_w / 2 + 120 * scale_x, 765 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 21 * scale_x, 701 * scale_y, now_w / 2 + 121 * scale_x, 764 * scale_y, al_map_rgb(47, 106, 166));
        al_draw_text(font_options2, al_map_rgb(r, g, b), 1030 * scale_x, 720 * scale_y, ALLEGRO_ALIGN_CENTER, "Não");

        al_draw_filled_rectangle(now_w / 2 + 120 * scale_x, 700 * scale_y, now_w / 2 + 220 * scale_x, 765 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 121 * scale_x, 701 * scale_y, now_w / 2 + 219 * scale_x, 764 * scale_y, al_map_rgb(228, 195, 78));
        al_draw_text(font_options2, al_map_rgb(r, g, b), 1130 * scale_x, 720 * scale_y, ALLEGRO_ALIGN_CENTER, "Sim");


        if (mouseX > 270 * scale_x && mouseX < 330 * scale_x && mouseY > 170 * scale_y && mouseY < 230 * scale_y) {
            r = 228;
            g = 195;
            b = 78;
            if (mouseB == 1) {
                r = 196; g = 196; b = 196;
                novaTela = 1;
            }
        }
        else { r = 196; g = 196; b = 196; }

        al_draw_filled_circle(295 * scale_x, 205 * scale_y, 30 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(r, g, b));
        al_draw_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(0, 0, 0), 1.5);
        al_draw_scaled_bitmap(back, 0, 0, al_get_bitmap_width(back), al_get_bitmap_height(back), 278 * scale_x, 180 * scale_y, 40 * scale_x, 40 * scale_y, 0);

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_options);
        al_destroy_font(font_options2);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
