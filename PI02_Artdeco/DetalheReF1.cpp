#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "DetalheReF1.h"
#include "DescData.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int detalheReF1(ALLEGRO_DISPLAY* display, int level, int descLinhas) {

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
  
    char buffer[50];
    getQuadro(level, buffer, sizeof(buffer));
    ALLEGRO_BITMAP* monalisa_real = al_load_bitmap(buffer);
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
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 230 * scale_x, 125 * scale_y, 1500 * scale_x, 735 * scale_y, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130 * scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);

        al_draw_scaled_bitmap(monalisa_real, 0, 0, al_get_bitmap_width(monalisa_real), al_get_bitmap_height(monalisa_real), 300 * scale_x, 200 * scale_y, 300 * scale_x, 350 * scale_y, 0);


        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 600 * scale_y, now_w / 4 + 275 * scale_x, 640 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 602 * scale_y, now_w / 4 + 273 * scale_x, 638 * scale_y, al_map_rgb(78, 110, 141));
        
        getTitulo(level, buffer, sizeof(buffer));
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 515 * scale_x, 600 * scale_y, ALLEGRO_ALIGN_CENTER, buffer);

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 660 * scale_y, now_w / 4 + 275 * scale_x, 700 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 662 * scale_y, now_w / 4 + 273 * scale_x, 698 * scale_y, al_map_rgb(47, 106, 166));
        
        getAutor(level, buffer, sizeof(buffer));
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 515 * scale_x, 660 * scale_y, ALLEGRO_ALIGN_CENTER, buffer);

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 720 * scale_y, now_w / 4 + 275 * scale_x, 760 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 722 * scale_y, now_w / 4 + 273 * scale_x, 758 * scale_y, al_map_rgb(94, 141, 150));
        
        getLoc(level, buffer, sizeof(buffer));
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 515 * scale_x, 720 * scale_y, ALLEGRO_ALIGN_CENTER, buffer);

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 780 * scale_y, now_w / 4 + 275 * scale_x, 820 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 198 * scale_x, 782 * scale_y, now_w / 4 + 273 * scale_x, 818 * scale_y, al_map_rgb(102, 165, 184));
        
        getAno(level, buffer, sizeof(buffer));
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 515 * scale_x, 780 * scale_y, ALLEGRO_ALIGN_CENTER, buffer);

        al_draw_filled_rectangle(now_w / 2 - 163 * scale_x, 197 * scale_y, now_w / 2 + 623 * scale_x, 823 * scale_y, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_rectangle(now_w / 2 - 160 * scale_x, 200 * scale_y, now_w / 2 + 620 * scale_x, 820 * scale_y, al_map_rgba(228, 195, 78, 70));

        for (int i = 0; i < descLinhas; i++) {
            getDesc(level, i, buffer, sizeof(buffer));
            al_draw_text(font_text, al_map_rgb(0, 0, 0), 810 * scale_x, (200 + 40 * i) * scale_y, 0, buffer);
        }
       

        al_flip_display();
        al_destroy_font(font_text);
    }

    al_destroy_bitmap(moldura);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return 11;
}
