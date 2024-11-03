#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "DetalhesObra.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int detalheObra(ALLEGRO_DISPLAY* display) {

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

        ALLEGRO_FONT* font_text = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 30 * scale_y, ALLEGRO_TTF_NO_KERNING);

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130*scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);

        al_draw_scaled_bitmap(monalisa_real, 0, 0, al_get_bitmap_width(monalisa_real), al_get_bitmap_height(monalisa_real), 300 * scale_x, 200 * scale_y, 300 * scale_x, 350 * scale_y, 0);

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300 * scale_x, 600 * scale_y, 0, "Título: A Mona Lisa");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300 * scale_x, 650 * scale_y, 0, "Autor: Leonardo da Vinci");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300 * scale_x, 700 * scale_y, 0, "Localização: Louvre, Paris");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300 * scale_x, 750 * scale_y, 0, "Ano: 1503");


        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 200 * scale_y, 0, "Mona Lisa também conhecida como A Gioconda");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 230 * scale_y, 0, "ou ainda Mona Lisa del Giocondo é a mais");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 260 * scale_y, 0, "notável e conhecida obra de Leonardo da Vinci,");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 290 * scale_y, 0, "um dos mais eminentes homens do Renascimento");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 320 * scale_y, 0, "italiano. Sua pintura foi iniciada em 1503 e é");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800 * scale_x, 350 * scale_y, 0, "nesta obra que o artista melhor concebeu...");

        al_flip_display();
        al_destroy_font(font_text);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
