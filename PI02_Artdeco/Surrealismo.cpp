#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Surrealismo.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int surrealismo(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* monalisa_real = al_load_bitmap("./assets/img/monalisa_real.png");
    ALLEGRO_BITMAP* monalisa_blur = al_load_bitmap("./assets/img/monalisa_blur.png");

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
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130 * scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5, 205 * scale_x, ALLEGRO_ALIGN_CENTER, "Surrealismo");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_x, ALLEGRO_ALIGN_CENTER, "Surrealismo");

        //al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2, 300 * scale_x, ALLEGRO_ALIGN_CENTER, "Renascimento ou Renascença são os termos usados para identificar o período da história d...");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 400 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, u8"A Persistência da Memória");
        al_draw_scaled_bitmap(monalisa_real, 0, 0, al_get_bitmap_width(monalisa_real), al_get_bitmap_height(monalisa_real), 300 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 400 * scale_x, 775 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 1");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 675 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "O Filho do Homem");
        al_draw_scaled_bitmap(monalisa_blur, 0, 0, al_get_bitmap_width(monalisa_blur), al_get_bitmap_height(monalisa_blur), now_w / 2 - 380 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 675 * scale_x, 775 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 2");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 955 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "O Grande Masturbador");
        al_draw_scaled_bitmap(monalisa_blur, 0, 0, al_get_bitmap_width(monalisa_blur), al_get_bitmap_height(monalisa_blur), now_w / 2 - 100 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 955 * scale_x, 775 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 3");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1255 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "O Amante");
        al_draw_scaled_bitmap(monalisa_blur, 0, 0, al_get_bitmap_width(monalisa_blur), al_get_bitmap_height(monalisa_blur), now_w / 2 + 200 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1255 * scale_x, 775 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 4");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1555 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Os Elefantes");
        al_draw_scaled_bitmap(monalisa_blur, 0, 0, al_get_bitmap_width(monalisa_blur), al_get_bitmap_height(monalisa_blur), now_w / 2 + 500 * scale_x, 525 * scale_y, 200 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1555 * scale_x, 775 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 5");

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
