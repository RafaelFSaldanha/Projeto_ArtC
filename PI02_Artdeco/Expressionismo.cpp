#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Expressionismo.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

int expressionismo(ALLEGRO_DISPLAY* display) {

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
    ALLEGRO_BITMAP* o_grito = al_load_bitmap("./assets/img/ex_o_grito.png");
    ALLEGRO_BITMAP* noite_estrelada = al_load_bitmap("./assets/img/ex_noite_estrelada.png");
    ALLEGRO_BITMAP* noite_estrelada_bg = al_load_bitmap("./assets/img/noite_estrelada.png");
    ALLEGRO_BITMAP* primeiros_animais = al_load_bitmap("./assets/img/ex_primeiros_animais.png");
    ALLEGRO_BITMAP* cinco_mulheres = al_load_bitmap("./assets/img/ex_cinco_mulheres.png");
    ALLEGRO_BITMAP* retirantes = al_load_bitmap("./assets/img/ex_retirantes.png");
    ALLEGRO_BITMAP* back = al_load_bitmap("./assets/img/back.png");

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
        al_draw_scaled_bitmap(noite_estrelada_bg, 0, 0, al_get_bitmap_width(noite_estrelada_bg), al_get_bitmap_height(noite_estrelada_bg), 230 * scale_x, 125 * scale_y, 1500 * scale_x, 735 * scale_y, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130 * scale_x, -73 * scale_y, 2160 * scale_x, 1165 * scale_y, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), now_w / 2 - 5, 205 * scale_x, ALLEGRO_ALIGN_CENTER, "Expressionismo");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), now_w / 2, 200 * scale_x, ALLEGRO_ALIGN_CENTER, "Expressionismo");

        //al_draw_text(font_text, al_map_rgb(0, 0, 0), now_w / 2, 300 * scale_x, ALLEGRO_ALIGN_CENTER, "Renascimento ou Renascença são os termos usados para identificar o período da história d...");

        al_draw_filled_rectangle(now_w / 4 - 200 * scale_x, 790 * scale_y, 1680 * scale_x, 840 * scale_y, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(now_w / 4 - 195 * scale_x, 795 * scale_y, 1675 * scale_x, 835 * scale_y, al_map_rgb(74, 130, 172));

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 400 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "O Grito");
        al_draw_scaled_bitmap(o_grito, 0, 0, al_get_bitmap_width(o_grito), al_get_bitmap_height(o_grito), 280 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 400 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 1");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 675 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "A Noite Estrelada");
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), now_w / 2 - 400 * scale_x, 560 * scale_y, 240 * scale_x, 150 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 675 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 2");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 955 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Os Primeiros Animais");
        al_draw_scaled_bitmap(primeiros_animais, 0, 0, al_get_bitmap_width(primeiros_animais), al_get_bitmap_height(primeiros_animais), now_w / 2 - 120 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 955 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 3");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1255 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Cinco Mulheres Na Rua");
        al_draw_scaled_bitmap(cinco_mulheres, 0, 0, al_get_bitmap_width(cinco_mulheres), al_get_bitmap_height(cinco_mulheres), now_w / 2 + 180 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1255 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 4");

        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1555 * scale_x, 475 * scale_y, ALLEGRO_ALIGN_CENTER, "Retirantes");
        al_draw_scaled_bitmap(retirantes, 0, 0, al_get_bitmap_width(retirantes), al_get_bitmap_height(retirantes), now_w / 2 + 480 * scale_x, 525 * scale_y, 240 * scale_x, 250 * scale_y, 0);
        al_draw_text(font_text, al_map_rgb(0, 0, 0), 1555 * scale_x, 800 * scale_y, ALLEGRO_ALIGN_CENTER, "Fase 5");

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
