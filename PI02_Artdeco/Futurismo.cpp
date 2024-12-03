#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Futurismo.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int futurismo(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* img1 = al_load_bitmap("./assets/img/fu_dinamismo.png");
    ALLEGRO_BITMAP* img2 = al_load_bitmap("./assets/img/fu_a_cidade_sobe.png");
    ALLEGRO_BITMAP* img3 = al_load_bitmap("./assets/img/fu_solidez_da_nevoa.png");
    ALLEGRO_BITMAP* img4 = al_load_bitmap("./assets/img/fu_dinamismo_de_um_carro.png");
    ALLEGRO_BITMAP* img5 = al_load_bitmap("./assets/img/fu_elasticidade.png");
    ALLEGRO_BITMAP* back = al_load_bitmap("./assets/img/back.png");
    int novaTela = 4;

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
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5, 185 * scale_x, ALLEGRO_ALIGN_CENTER, "Futurismo");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 180 * scale_x, ALLEGRO_ALIGN_CENTER, "Futurismo");

        al_draw_filled_rectangle(now_w / 4 - 240 * scale_x, 300 * scale_y, 1680 * scale_x, 450 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_rectangle(now_w / 4 - 235 * scale_x, 305 * scale_y, 1675 * scale_x, 445 * scale_y, al_map_rgba(228, 195, 78, 70));

        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 , 320 * scale_y, ALLEGRO_ALIGN_CENTER, u8"Vanguarda italiana do in�cio do s�culo XX que celebrava a velocidade, tecnologia,");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 , 350 * scale_y, ALLEGRO_ALIGN_CENTER, u8"juventude e viol�ncia da era moderna. Rejeitava tradi��es art�sticas anteriores e buscava");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 , 380 * scale_y, ALLEGRO_ALIGN_CENTER, u8"representar o movimento e dinamismo em suas obras. Usava formas fragmentadas e linhas");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2 , 410 * scale_y, ALLEGRO_ALIGN_CENTER, u8"de for�a. Principais artistas: Marinetti e Boccioni.");

        al_draw_filled_rectangle(now_w / 4 - 240 * scale_x, 790 * scale_y, 1680 * scale_x, 840 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 235 * scale_x, 795 * scale_y, 1675 * scale_x, 835 * scale_y, al_map_rgb(74, 130, 172));

        if (mouseX > 264 * scale_x && mouseX < 504 * scale_x && mouseY > 550 * scale_y && mouseY < 750 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 32;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 4 - 270 * scale_x, 465 * scale_y, now_w / 2 - 400 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 265 * scale_x, 470 * scale_y, now_w / 2 - 405 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 576 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"Dinamismo de um C�o na Coleira");
        al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1), 264 * scale_x, 550 * scale_y, 240 * scale_x, 200 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 576 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 1");

        if (mouseX > 552 * scale_x && mouseX < 792 * scale_x && mouseY > 570 * scale_y && mouseY < 730 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 33;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 405 * scale_x, 465 * scale_y, now_w / 2 - 170 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 400 * scale_x, 470 * scale_y, now_w / 2 - 175 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 288 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "A Cidade que Sobe");
        al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2), al_get_bitmap_height(img2), 552 * scale_x, 570 * scale_y, 240 * scale_x, 160 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 - 288 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 2");

        if (mouseX > 860 * scale_x && mouseX < 1060 * scale_x && mouseY > 525 * scale_y && mouseY < 775 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 34;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 - 110 * scale_x, 465 * scale_y, now_w / 2 + 110 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 - 105 * scale_x, 470 * scale_y, now_w / 2 + 105 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 , 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"Solidez da N�voa");
        al_draw_scaled_bitmap(img3, 0, 0, al_get_bitmap_width(img3), al_get_bitmap_height(img3), now_w / 2 - 100 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 , 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 3");

        if (mouseX > 1128 * scale_x && mouseX < 1368 * scale_x && mouseY > 565 * scale_y && mouseY < 735 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 35;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + 145 * scale_x, 465 * scale_y, now_w / 2 + 435 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 150 * scale_x, 470 * scale_y, now_w / 2 + 430 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 288 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Dinamismo de um Carro");
        al_draw_scaled_bitmap(img4, 0, 0, al_get_bitmap_width(img4), al_get_bitmap_height(img4), 1128 * scale_x, 565 * scale_y, 240 * scale_x, 170 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 288 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 4");

        if (mouseX > 1416 * scale_x && mouseX < 1656 * scale_x && mouseY > 525 * scale_y && mouseY < 775 * scale_y) {
            r = 225;
            g = 190;
            b = 0;
            if (mouseB == 1) {
                r = 0; g = 0; b = 0;
                novaTela = 36;
                break;
            }
        }
        else { r = 0; g = 0; b = 0; }

        al_draw_filled_rectangle(now_w / 2 + 485 * scale_x, 465 * scale_y, now_w / 2 + 670 * scale_x, 510 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 2 + 490 * scale_x, 470 * scale_y, now_w / 2 + 665 * scale_x, 505 * scale_y, al_map_rgb(74, 130, 172));
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 576 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Elasticidade");
        al_draw_scaled_bitmap(img5, 0, 0, al_get_bitmap_width(img5), al_get_bitmap_height(img5), 1416 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(r, g, b), now_w / 2 + 576 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 5");

        if (mouseX > 270 * scale_x && mouseX < 330 * scale_x && mouseY > 170 * scale_y && mouseY < 230 * scale_y) {
            r = 228;
            g = 195;
            b = 78;
            if (mouseB == 1) {
                r = 196; g = 196; b = 196;
                novaTela = 4;
                break;
            }
        }
        else { r = 196; g = 196; b = 196; }

        al_draw_filled_circle(295 * scale_x, 205 * scale_y, 30 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(r, g, b));
        al_draw_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(0, 0, 0), 1.5);
        al_draw_scaled_bitmap(back, 0, 0, al_get_bitmap_width(back), al_get_bitmap_height(back), 278 * scale_x, 180 * scale_y, 40 * scale_x, 40 * scale_y, 0);

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_text);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return novaTela;
}