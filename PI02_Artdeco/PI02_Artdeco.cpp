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

const int WIDTH = 1910;
const int HEIGHT = 990;

enum TelaAtiva {DEBUG, PRINCIPAL, FASES, GAME, OPTIONS, OBRA, VANGUARDAS, VISUALS };
TelaAtiva telaAtual = DEBUG;


int main() {

    if (telaAtual == DEBUG) {
        telaInicial();
        fases();
        gameLogic();
        gameView();
        opcoes();
        detalheObra();
        vanguardas();
        personalizacao();
    }

    if (telaAtual == PRINCIPAL) {
        telaInicial();
    }

    if (telaAtual == FASES) {
        fases();
    }

    if (telaAtual == GAME) {
        gameLogic();
        gameView();
    }

    if (telaAtual == OPTIONS) {
        opcoes();
    }

    if (telaAtual == OBRA) {
        detalheObra();
    }

    if (telaAtual == VANGUARDAS) {
        vanguardas();
    }

    if (telaAtual == VISUALS) {
        personalizacao();
    }
    return 0;
}