#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <string>

int const gameWidth = 10;
int const gameHeight = 5;
ALLEGRO_FONT* font;

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

int logic() {

    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_install_mouse();

    ALLEGRO_DISPLAY* display = al_create_display(1150, 650);
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

