#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Carrossel.h"
#include "DescData.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int carrossel(ALLEGRO_DISPLAY* display, int quadrosDesb[]) {

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
    int meioCoord = -1;
    for (int i = 0; i < 30; i++) {
        if (quadrosDesb[i] == 1) {
            meioCoord = i;
            break;
        }
    }

    char buffer[50];
    ALLEGRO_BITMAP* quadroMeio = al_load_bitmap("");
    ALLEGRO_BITMAP* quadroEsquerda = al_load_bitmap("");
    ALLEGRO_BITMAP* quadroDireita = al_load_bitmap("");
  
    
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

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;

        
        if (meioCoord != -1) {
            getQuadro(meioCoord, buffer, sizeof(buffer));
            quadroMeio = al_load_bitmap(buffer);
        }
        
        if (meioCoord > 0) {
            int dirCoord = -1;
            for (int i = meioCoord-1; i >= 0; i--) {
                if (quadrosDesb[i] == 1) {
                    dirCoord = i;
                    break;
                }
            }

            if (dirCoord != -1) {
                getQuadro(dirCoord, buffer, sizeof(buffer));
                quadroEsquerda = al_load_bitmap(buffer);
            }
            
        }
        
        if (meioCoord > -1 && meioCoord < 29) {
            int esqCoord = -1;
            for (int i = meioCoord+1; i < 30; i++) {
                if (quadrosDesb[i] == 1) {
                    esqCoord = i;
                    break;
                }
            }

            if (esqCoord != -1) {
                getQuadro(esqCoord, buffer, sizeof(buffer));
                quadroDireita = al_load_bitmap(buffer);
            }

        }

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 230*scale_x, 125 * scale_y, 1500 * scale_x, 735 * scale_y, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130 * scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5, 205 * scale_y, ALLEGRO_ALIGN_CENTER, "Galeria");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_y, ALLEGRO_ALIGN_CENTER, "Galeria");

        al_draw_filled_circle(295 * scale_x, now_h / 2, 30 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(295 * scale_x, 205 * scale_y, 30 * scale_y, al_map_rgba(0, 0, 0, 70));

        if (quadroMeio) {
            al_draw_scaled_bitmap(quadroMeio, 0, 0, al_get_bitmap_width(quadroMeio), al_get_bitmap_height(quadroMeio), now_w / 2 - 150 * scale_x, 350 * scale_y, 300 * scale_x, 350 * scale_y, 0);
            al_draw_text(font_options, al_map_rgb(r, g, b), now_w / 2, 1000 * scale_y, ALLEGRO_ALIGN_CENTER, "TITULO QUADRO");
        }
        
        if (quadroEsquerda) {
            al_draw_scaled_bitmap(quadroEsquerda, 0, 0, al_get_bitmap_width(quadroEsquerda), al_get_bitmap_height(quadroEsquerda), now_w / 2 - 450 * scale_x, 400 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        }

        if (quadroDireita) {
            al_draw_scaled_bitmap(quadroDireita, 0, 0, al_get_bitmap_width(quadroDireita), al_get_bitmap_height(quadroDireita), now_w / 2 + 250 * scale_x, 400 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        }
        

        if (mouseX > 270 * scale_x && mouseX < 330 * scale_x && mouseY > 170 * scale_y && mouseY < 230 * scale_y) {
            r = 228;
            g = 195;
            b = 78;
            if (mouseB == 1) {
                r = 196; g = 196; b = 196;
            }
        }
        else { r = 196; g = 196; b = 196; }

        al_draw_filled_circle(295 * scale_x, 205 * scale_y, 30 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(r, g, b));
        al_draw_circle(300 * scale_x, 200 * scale_y, 30 * scale_y, al_map_rgb(0, 0, 0), 1.5);
        al_draw_text(font_options, al_map_rgba(0, 0, 0, 70), 297 * scale_x, 170 * scale_y, ALLEGRO_ALIGN_CENTER, "?");
        al_draw_text(font_options, al_map_rgb(0, 0, 0), 300 * scale_x, 167 * scale_y, ALLEGRO_ALIGN_CENTER, "?");

        al_flip_display();
        al_destroy_font(font_tittle);
        al_destroy_font(font_options);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);
    al_destroy_bitmap(quadroMeio);
    al_destroy_bitmap(quadroEsquerda);
    al_destroy_bitmap(quadroDireita);
    return 1;
}
