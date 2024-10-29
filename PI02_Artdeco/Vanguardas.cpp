#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "Vanguardas.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

void draw_inverted_rectangle(ALLEGRO_BITMAP* background, int x, int y, int width, int height, float opacity) {
    ALLEGRO_BITMAP* temp_bitmap = al_create_bitmap(width, height);
    al_set_target_bitmap(temp_bitmap);
    al_draw_bitmap_region(background, x, y, width, height, 0, 0, 0);

    al_lock_bitmap(temp_bitmap, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READWRITE);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            ALLEGRO_COLOR original_color = al_get_pixel(temp_bitmap, i, j);
            float r, g, b, a;
            al_unmap_rgba_f(original_color, &r, &g, &b, &a);
            ALLEGRO_COLOR inverted_color = al_map_rgba_f(1 - r, 1 - g, 1 - b, opacity);
            al_put_pixel(i, j, inverted_color);
        }
    }
    al_unlock_bitmap(temp_bitmap);

    al_set_target_backbuffer(al_get_current_display());
    al_draw_bitmap(temp_bitmap, x, y, 0);
    al_destroy_bitmap(temp_bitmap);
}

int vanguardas(ALLEGRO_DISPLAY* display) {
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();

    al_set_window_position(display, 0, 35);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT* font_tittle = al_load_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70, ALLEGRO_TTF_NO_KERNING);
    ALLEGRO_FONT* font_options = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 30, ALLEGRO_TTF_NO_KERNING);
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

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 230, 125, 1500, 735, 0);
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -73, 2160, 1165, 0);
        al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 205, ALLEGRO_ALIGN_CENTER, "Vanguardas");
        al_draw_text(font_tittle, al_map_rgb(0, 0, 0), WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, "Vanguardas");

        float opacity = 0.5;
        int r = 0, g = 0, b = 0;

        // Renascentismo
        if (mouseX > WIDTH / 4 - 200 && mouseX < WIDTH / 4 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 4 - 200, 300, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 4, 400, ALLEGRO_ALIGN_CENTER, "Renascentismo");

        // Cubismo
        if (mouseX > WIDTH / 4 - 200 && mouseX < WIDTH / 4 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 4 - 200, 575, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 4, 675, ALLEGRO_ALIGN_CENTER, "Cubismo");

        // Impressionismo
        if (mouseX > WIDTH / 2 - 200 && mouseX < WIDTH / 2 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 2 - 200, 300, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2, 400, ALLEGRO_ALIGN_CENTER, "Impressionismo");

        // Futurismo
        if (mouseX > WIDTH / 2 - 200 && mouseX < WIDTH / 2 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 2 - 200, 575, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2, 675, ALLEGRO_ALIGN_CENTER, "Futurismo");

        // Surrealismo
        if (mouseX > WIDTH / 2 + WIDTH / 4 - 200 && mouseX < WIDTH / 2 + WIDTH / 4 + 200 && mouseY > 300 && mouseY < 525) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 2 + WIDTH / 4 - 200, 300, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2 + WIDTH / 4, 400, ALLEGRO_ALIGN_CENTER, "Surrealismo");

        // Expressionismo
        if (mouseX > WIDTH / 2 + WIDTH / 4 - 200 && mouseX < WIDTH / 2 + WIDTH / 4 + 200 && mouseY > 575 && mouseY < 800) {
            r = 225; g = 190; b = 0;
            if (mouseB == 1) { novaTela = 2; break; }
        }
        else { r = 0; g = 0; b = 0; }
        draw_inverted_rectangle(noite_estrelada, WIDTH / 2 + WIDTH / 4 - 200, 575, 400, 225, opacity);
        al_draw_text(font_options, al_map_rgb(r, g, b), WIDTH / 2 + WIDTH / 4, 675, ALLEGRO_ALIGN_CENTER, "Expressionismo");

        al_flip_display();
    }

    al_destroy_bitmap(moldura);
    al_destroy_font(font_tittle);
    al_destroy_font(font_options);
    al_destroy_event_queue(event_queue);
    al_destroy_mouse_cursor(cursor);
    al_destroy_bitmap(pincel_cursor);

    return novaTela;
}
