#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "Game.h"

int const gameWidth = 10;
int const gameHeight = 5;
ALLEGRO_FONT* font;
const int WIDTH = 1920;
const int HEIGHT = 985;


/*
0 - Branco
1 - Preto
2 - Borda
3 - Hover
4 - Flag
5 - Errado
*/

int coords[gameHeight][gameWidth] = {
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0, 1, 1, 1, 0}
};

int playerCoords[gameHeight][gameWidth];
int gameBlacks = 0;
int playerBlacks = 0;

int makeRowHints(int startX, int startY) {
    std::string hintRow;
    std::string hintCol;
    int conjuntoRow;
    for (int j = 0; j < gameHeight; j++) {
        conjuntoRow = 0;
        hintRow = "";

        for (int i = 0; i < gameWidth; i++) {
            if (coords[j][i] == 1) { conjuntoRow++; }
            if ((coords[j][i] == 0 or i + 1 == gameWidth) and conjuntoRow > 0) {
                hintRow += std::to_string(conjuntoRow) + "-";
                conjuntoRow = 0;
            }
            else if (hintRow == "" and i + 1 == gameWidth) {
                hintRow = "0";
            }
        }
        int x = startX;
        int y = 100 + j * 100 + startY;
        al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, hintRow.c_str());

    }
    return 0;
}

int makeColHints(int startX, int startY) {
    std::string hintCol;
    int conjuntoCol;
    for (int j = 0; j < gameWidth; j++) {
        conjuntoCol = 0;
        hintCol = "";

        for (int i = 0; i < gameHeight; i++) {
            if (coords[i][j] == 1) { conjuntoCol++; }
            if ((coords[i][j] == 0 or i + 1 == gameHeight) and conjuntoCol > 0) {
                hintCol += std::to_string(conjuntoCol) + "-";
                conjuntoCol = 0;
            }
            else if (hintCol == "" and i + 1 == gameHeight) {
                hintCol = "0";
            }

        }
        int x = 100 + j * 100 + startX;
        int y = startY;
        al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, hintCol.c_str());

    }
    return 0;
}

int gridLogic(int startX, int startY, int width, int height, ALLEGRO_BITMAP* boxes[], int mouseX, int mouseY, int mouse) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int x = i * 100 + startX;
            int y = j * 100 + startY;

            if (i > 0 && j > 0) {
                int corBox;
                int player = playerCoords[j - 1][i - 1];
                int gabarito = coords[j - 1][i - 1];

                if (mouseX >= x && x + 100 > mouseX && mouseY >= y && y + 100 > mouseY) {
                    if (player != 1 && player != 5) {
                        if (mouse == 1) {
                            if (gabarito == 1) {
                                playerCoords[j - 1][i - 1] = 1;
                                playerBlacks++;
                            }
                            else { playerCoords[j - 1][i - 1] = 5; }
                        }
                        else if (mouse == 2) {
                            if (player == 0) { playerCoords[j - 1][i - 1] = 4; }
                            else if (player == 4) { playerCoords[j - 1][i - 1] = 0; }
                        }
                    }

                    if (player == 0) { corBox = 3; }
                    else { corBox = player; }
                }
                else { corBox = player; }
                al_draw_bitmap(boxes[corBox], x, y, 0);
            }
            else {
                al_draw_bitmap(boxes[2], x, y, 0);
                makeRowHints(startX, startY);
                makeColHints(startX, startY);
            }

        }
    }
    return 0;
}

int gameLogic(ALLEGRO_DISPLAY* display) {

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_mouse();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_BITMAP* boxes[6] = {
        al_load_bitmap("./assets/img/whiteBox.png"),
        al_load_bitmap("./assets/img/blackBox.png"),
        al_load_bitmap("./assets/img/grayBox.png"),
        al_load_bitmap("./assets/img/hoverBox.png"),
        al_load_bitmap("./assets/img/flagBox.png"),
        al_load_bitmap("./assets/img/wrongBox.png")
    };

    al_set_window_position(display, 200, 30);
    al_set_window_title(display, "Artdeco Main Game");

    font = al_create_builtin_font();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    for (int i = 0; i < gameWidth; i++) {
        for (int j = 0; j < gameHeight; j++) {
            playerCoords[j][i] = 0;
            if (coords[j][i] == 1) { gameBlacks++; }
        }
    }

    while (true) {

        al_get_mouse_state(&state);
        int mouseX = state.x;
        int mouseY = state.y;
        int mouseB = state.buttons;

        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        al_clear_to_color(al_map_rgb(255, 255, 255));
        if (playerBlacks < gameBlacks) {
            gridLogic(25, 25, 11, 6, boxes, mouseX, mouseY, mouseB);
        }
        else { al_draw_text(font, al_map_rgb(0, 0, 0), 100, 100, 0, "Você venceu, Parabéns!"); }

        al_flip_display();


    }

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}

int gameView() {


        al_init();
        al_init_font_addon();
        al_init_ttf_addon();
        al_init_image_addon();
        al_init_primitives_addon();
        al_install_mouse();

        ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
        al_set_window_position(display, 0, 35);
        al_set_window_title(display, "ArtDeco");
        ALLEGRO_MOUSE_STATE state;
        ALLEGRO_FONT* font_tittle = al_load_font("./assets/fonts/CinzelDecorative-Regular.ttf", 70, 0);
        ALLEGRO_FONT* font_text = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50, 0);
        ALLEGRO_FONT* font_text2 = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 40, 0);
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
        ALLEGRO_BITMAP* pausa = al_load_bitmap("./assets/img/pausa.png");
        ALLEGRO_BITMAP* relogio = al_load_bitmap("./assets/img/relogio.png");
        ALLEGRO_BITMAP* noite_estrelada = al_load_bitmap("./assets/img/noite_estrelada.png");

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
            al_draw_scaled_bitmap(noite_estrelada, 0, 0, al_get_bitmap_width(noite_estrelada), al_get_bitmap_height(noite_estrelada), 230, 125, 1500, 735, 0);
            al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -73, 2160, 1165, 0);
            al_draw_text(font_tittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 155, ALLEGRO_ALIGN_CENTER, "Fase 4");
            al_draw_text(font_tittle, al_map_rgb(0, 0, 0), WIDTH / 2, 150, ALLEGRO_ALIGN_CENTER, "Fase 4");

            if (mouseX > 270 && mouseX < 330 && mouseY > 170 && mouseY < 230) {
                r = 228;
                g = 195;
                b = 78;
                if (mouseB == 1) {
                    r = 196; g = 196; b = 196;
                }
            }
            else { r = 196; g = 196; b = 196; }

            al_draw_filled_circle(295, 205, 30, al_map_rgba(0, 0, 0, 70));
            al_draw_filled_circle(300, 200, 30, al_map_rgb(r, g, b));
            al_draw_circle(300, 200, 30, al_map_rgb(0, 0, 0), 1.5);
            al_draw_text(font_text, al_map_rgba(0, 0, 0, 70), 297, 170, ALLEGRO_ALIGN_CENTER, "?");
            al_draw_text(font_text, al_map_rgb(0, 0, 0), 300, 167, ALLEGRO_ALIGN_CENTER, "?");

            if (mouseX > 1620 && mouseX < 1680 && mouseY > 170 && mouseY < 230) {
                r = 228;
                g = 195;
                b = 78;
                if (mouseB == 1) {
                    r = 196; g = 196; b = 196;
                }
            }
            else { r = 196; g = 196; b = 196; }

            al_draw_filled_circle(1645, 205, 30, al_map_rgba(0, 0, 0, 70));
            al_draw_filled_circle(1650, 200, 30, al_map_rgb(r, g, b));
            al_draw_circle(1650, 200, 30, al_map_rgb(0, 0, 0), 1.5);
            al_draw_scaled_bitmap(pausa, 0, 0, al_get_bitmap_width(pausa), al_get_bitmap_height(pausa), 1625, 175, 50, 50, 0);

            al_draw_filled_rectangle(WIDTH / 4 - 150, 350, WIDTH / 4 + 150, 575, al_map_rgba(240, 209, 86, 70));
            al_draw_rectangle(WIDTH / 4 - 150, 350, WIDTH / 4 + 150, 575, al_map_rgb(0, 0, 0), 1);
            al_draw_text(font_text2, al_map_rgb(0, 0, 0), 475, 360, ALLEGRO_ALIGN_CENTER, "Progresso");
            al_draw_text(font_text2, al_map_rgb(0, 0, 0), 475, 450, ALLEGRO_ALIGN_CENTER, "99,9%");

            al_draw_filled_rectangle(WIDTH / 4 - 150, 575, WIDTH / 4 + 150, 800, al_map_rgba(240, 209, 86, 70));
            al_draw_rectangle(WIDTH / 4 - 150, 575, WIDTH / 4 + 150, 800, al_map_rgb(0, 0, 0), 1);
            al_draw_text(font_text2, al_map_rgb(0, 0, 0), 475, 590, ALLEGRO_ALIGN_CENTER, "Erros");
            al_draw_text(font_text2, al_map_rgb(0, 0, 0), 475, 680, ALLEGRO_ALIGN_CENTER, "4");

            al_draw_filled_rectangle(WIDTH / 2 - 225, 350, WIDTH / 2 + 225, 800, al_map_rgb(255, 255, 255));
            al_draw_rectangle(WIDTH / 2 - 225, 350, WIDTH / 2 + 225, 800, al_map_rgb(0, 0, 0), 1);

            al_draw_scaled_bitmap(relogio, 0, 0, al_get_bitmap_width(relogio), al_get_bitmap_height(relogio), 1325, 360, 50, 50, 0);
            al_draw_filled_rectangle(WIDTH / 2 + 427.5, 350, WIDTH / 2 + 577.5, 420, al_map_rgba(240, 209, 86, 70));
            al_draw_rectangle(WIDTH / 4 - 150, 350, WIDTH / 4 + 150, 575, al_map_rgb(0, 0, 0), 1);
            al_draw_text(font_text2, al_map_rgb(0, 0, 0), 1460, 360, ALLEGRO_ALIGN_CENTER, "7:21");

            al_flip_display();
        }

        al_destroy_display(display);
        al_destroy_bitmap(moldura);
        al_destroy_font(font_tittle);
        al_destroy_font(font_text);
        al_destroy_font(font_text2);
        al_destroy_event_queue(event_queue);
        al_destroy_mouse_cursor(cursor);
        al_destroy_bitmap(pincel_cursor);

        return 1;
    }