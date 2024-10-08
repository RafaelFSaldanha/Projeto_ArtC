#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

const int WIDTH = 1910;
const int HEIGHT = 990;

int main() {

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();


    ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
    al_set_window_title(display, "ArtDeco");
    ALLEGRO_MOUSE_STATE state;
    ALLEGRO_FONT* fontTittle = al_load_font("./assets/fonts/Cinzel-Regular.ttf", 70, 0);
    ALLEGRO_FONT* fontoptions = al_load_font("./assets/fonts/MontserratSubrayada-Regular.ttf", 40, 0);
    ALLEGRO_FONT* fonttext = al_load_font("./assets/fonts/MontserratAlternates-Regular.ttf", 50, 0);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_BITMAP* moldura = al_load_bitmap("./assets/img/Moldura.png");

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

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
        int b = 0;

        al_clear_to_color(al_map_rgb(196, 196, 196));
        al_draw_scaled_bitmap(moldura, 0, 0, al_get_bitmap_width(moldura), al_get_bitmap_height(moldura), -130, -70, 2150, 1160, 0);
        al_draw_text(fontTittle, al_map_rgba(0, 0, 0, 70), WIDTH / 2 - 5, 205, ALLEGRO_ALIGN_CENTER, "ArtDeco");
        al_draw_text(fontTittle, al_map_rgb(0, 0, 0), WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, "ArtDeco");
        
        if (mouseX > WIDTH / 2 - 100 && mouseX < WIDTH / 2 + 100 && mouseY > 400 && mouseY < 440) { 
            b = 200; 
            if (mouseB == 1) { 
                b = 100;
                
            }
        }
        else { b = 0; }

        al_draw_text(fontoptions, al_map_rgb(0, 0, b), WIDTH / 2, 400, ALLEGRO_ALIGN_CENTER, "Jogar");

        if (mouseX > WIDTH / 2 - 100 && mouseX < WIDTH / 2 + 100 && mouseY > 500 && mouseY < 540) { b = 200; }
        else { b = 0; }
        al_draw_text(fontoptions, al_map_rgb(0, 0, b), WIDTH / 2, 500, ALLEGRO_ALIGN_CENTER, "Níveis");

        if (mouseX > WIDTH / 2 - 100 && mouseX < WIDTH / 2 + 100 && mouseY > 600 && mouseY < 640) { b = 200; }
        else { b = 0; }
        al_draw_text(fontoptions, al_map_rgb(0, 0, b), WIDTH / 2, 600, ALLEGRO_ALIGN_CENTER, "Galeria");

        if (mouseX > WIDTH / 2 - 100 && mouseX < WIDTH / 2 + 100 && mouseY > 700 && mouseY < 740) { b = 200; }
        else { b = 0; }
        al_draw_text(fontoptions, al_map_rgb(0, 0, b), WIDTH / 2, 700, ALLEGRO_ALIGN_CENTER, "Opções");

        al_draw_filled_circle(295, 205, 30, al_map_rgba(0, 0, 0, 70));
        al_draw_filled_circle(300, 200, 30, al_map_rgb(196, 196, 196));
        al_draw_circle(300, 200, 30, al_map_rgb(0, 0, 0), 1.5);
        al_draw_text(fonttext, al_map_rgba(0, 0, 0, 70), 297, 170, ALLEGRO_ALIGN_CENTER, "?");
        al_draw_text(fonttext, al_map_rgb(0, 0, 0), 300, 167, ALLEGRO_ALIGN_CENTER, "?");
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_bitmap(moldura);
    al_destroy_font(fontTittle);
    al_destroy_font(fontoptions);
    al_destroy_font(fonttext);
    al_destroy_event_queue(event_queue);

    return 0;
}