#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "TelaPrincipal.h"
#include "Fases.h"
#include "Game.h"
#include "Options.h"
#include "DetalhesObra.h"
#include "Vanguardas.h"
#include "Visuals.h"
#include "Carrossel.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

enum TelaAtiva {DEBUG, PRINCIPAL, FASES, GAME, OPTIONS, OBRA, VANGUARDAS, VISUALS, CARROSSEL };
int telaAtual = 1;

int main() {
    al_init();
    ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);

    while (telaAtual != 0) {
        if (telaAtual == -1) {
            telaInicial(display);
            fases(display);
            gameLogic(display);
            gameView(display);
            opcoes(display);
            detalheObra(display);
            vanguardas(display);
            personalizacao(display);
        }

        if (telaAtual == 1) {
            telaAtual = telaInicial(display);
        }

        if (telaAtual == 2) {
            telaAtual = fases(display);
        }

        if (telaAtual == 3) {
            telaAtual = gameView(display);
            //gameLogic();
        }

        if (telaAtual == 4) {
            telaAtual = opcoes(display);
        }

        if (telaAtual == 5) {
            telaAtual = detalheObra(display);
        }

        if (telaAtual == 6) {
            telaAtual = vanguardas(display);
        }

        if (telaAtual == 7) {
            telaAtual = personalizacao(display);
        }

        if (telaAtual == 8) {
            telaAtual = carrossel(display);
        }
    }

    al_destroy_display(display);
    return 0;
}