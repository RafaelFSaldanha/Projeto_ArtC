#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Impressionismo.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int impressionismo(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* img1 = al_load_bitmap("./assets/img/Im_impressao_sol_nascente.png");
    ALLEGRO_BITMAP* img2 = al_load_bitmap("./assets/img/Im_mulheres_no_jardim.png");
    ALLEGRO_BITMAP* img3 = al_load_bitmap("./assets/img/Im_estacao_saint_lazare.png");
    ALLEGRO_BITMAP* img4 = al_load_bitmap("./assets/img/Im_campo_de_papoulas.png");
    ALLEGRO_BITMAP* img5 = al_load_bitmap("./assets/img/Im_almoco_remadores.png");
    int novaTela = 0;

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
        ALLEGRO_FONT* font_text = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 20 * scale_y, ALLEGRO_TTF_NO_KERNING);

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
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5, 185 * scale_x, ALLEGRO_ALIGN_CENTER, "Impressionismo");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 180 * scale_x, ALLEGRO_ALIGN_CENTER, "Impressionismo");

        al_draw_filled_rectangle(now_w / 4 - 240 * scale_x, 300 * scale_y, 1680 * scale_x, 450 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_rectangle(now_w / 4 - 235 * scale_x, 305 * scale_y, 1675 * scale_x, 445 * scale_y, al_map_rgba(228, 195, 78, 70));

        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 * scale_x, 320 * scale_y, ALLEGRO_ALIGN_CENTER, u8"Movimento art�stico do final do s�culo XIX que buscava captar a impress�o imediata da luz");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 * scale_x, 350 * scale_y, ALLEGRO_ALIGN_CENTER, "e do momento sobre os objetos. Caracterizado por pinceladas soltas, cores puras e temas");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 * scale_x, 380 * scale_y, ALLEGRO_ALIGN_CENTER, "do cotidiano, principalmente paisagens. Revolucionou a pintura ao ar livre. Principais");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 * scale_x, 410 * scale_y, ALLEGRO_ALIGN_CENTER, "artistas: Claude Monet e Pierre-Auguste�Renoir.");

        al_draw_filled_rectangle(now_w / 4 - 240 * scale_x, 790 * scale_y, 1680 * scale_x, 840 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 235 * scale_x, 795 * scale_y, 1675 * scale_x, 835 * scale_y, al_map_rgb(74, 130, 172));

        if (mouseX > 264 && mouseX < 504 && mouseY > 555 * scale_y && mouseY < 735 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 4 - 245 * scale_x, 465 * scale_y, now_w / 2 - 430 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 240 * scale_x, 470 * scale_y, now_w / 2 - 435 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 576 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"Impress�o, Sol Nascente");
        al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1), 264 * scale_x, 555 * scale_y, 240 * scale_x, 180 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 576 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 1");

        if (mouseX > 552 && mouseX < 792 && mouseY > 560 * scale_y && mouseY < 710 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 410 * scale_x, 465 * scale_y, now_w / 2 - 165 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 405 * scale_x, 470 * scale_y, now_w / 2 - 170 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 288 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Mulheres no Jardim");
        al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2), al_get_bitmap_height(img2), 552 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 288 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 2");

        if (mouseX > 840 && mouseX < 1080 && mouseY > 555 * scale_y && mouseY < 735 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 140 * scale_x, 465 * scale_y, now_w / 2 + 140 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 135 * scale_x, 470 * scale_y, now_w / 2 + 135 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"A Esta��o Saint Lazare");
        al_draw_scaled_bitmap(img3, 0, 0, al_get_bitmap_width(img3), al_get_bitmap_height(img3), now_w / 2 - 120 * scale_x, 555 * scale_y, 240 * scale_x, 180 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 3");

        if (mouseX > 1128 && mouseX < 1368 && mouseY > 555 * scale_y && mouseY < 735 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + 160 * scale_x, 465 * scale_y, now_w / 2 + 415 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 165 * scale_x, 470 * scale_y, now_w / 2 + 410 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 288 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Campo de Papoulas");
        al_draw_scaled_bitmap(img4, 0, 0, al_get_bitmap_width(img4), al_get_bitmap_height(img4), 1128 * scale_x, 555 * scale_y, 240 * scale_x, 180 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 288 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 4");

        if (mouseX > 1416 && mouseX < 1656 && mouseY > 555 * scale_y && mouseY < 735 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + 425 * scale_x, 465 * scale_y, now_w / 2 + 730 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 430 * scale_x, 470 * scale_y, now_w / 2 + 725 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 576 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"O Almo�o dos Remadores");
        al_draw_scaled_bitmap(img5, 0, 0, al_get_bitmap_width(img5), al_get_bitmap_height(img5), 1416 * scale_x, 555 * scale_y, 240 * scale_x, 180 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 576 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 5");

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_text);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 6;
}