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

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();

    al_set_window_position(display, 0, 35);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT* font_text = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 30, ALLEGRO_TTF_NO_KERNING);
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

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;
        int r = 0;
        int g = 0;
        int b = 0;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -73, 2160, 1165, 0);

        al_draw_scaled_bitmap(monalisa_real, 0, 0, al_get_bitmap_width(monalisa_real), al_get_bitmap_height(monalisa_real), 300, 200, 300, 350, 0);

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300, 600, 0, "Título: A Mona Lisa");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300, 650, 0, "Autor: Leonardo da Vinci");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300, 700, 0, "Localização: Louvre, Paris");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 300, 750, 0, "Ano: 1503");


        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 200, 0, "Mona Lisa também conhecida como A Gioconda");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 230, 0, "ou ainda Mona Lisa del Giocondo é a mais");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 260, 0, "notável e conhecida obra de Leonardo da Vinci,");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 290, 0, "um dos mais eminentes homens do Renascimento");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 320, 0, "italiano. Sua pintura foi iniciada em 1503 e é");
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 800, 350, 0, "nesta obra que o artista melhor concebeu...");

        al_flip_display();
    }

    al_destroy_bitmap(moldura);
    al_destroy_font(font_text);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 1;
}
