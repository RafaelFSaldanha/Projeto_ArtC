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

const int WIDTH = 1920;
const int HEIGHT = 985;

enum TelaAtiva {DEBUG, PRINCIPAL, FASES, GAME, OPTIONS, OBRA, VANGUARDAS, VISUALS };
int telaAtual = 1;


int main() {
    while (telaAtual != 0) {
        if (telaAtual == -1) {
            telaInicial();
            fases();
            gameLogic();
            gameView();
            opcoes();
            detalheObra();
            vanguardas();
            personalizacao();
        }

        if (telaAtual == 1) {
            telaAtual = telaInicial();
        }

        if (telaAtual == 2) {
            telaAtual = fases();
        }

        if (telaAtual == 3) {
            telaAtual = gameView();
            //gameLogic();
        }

        if (telaAtual == 4) {
            telaAtual = opcoes();
        }

        if (telaAtual == 5) {
            telaAtual = detalheObra();
        }

        if (telaAtual == 6) {
            telaAtual = vanguardas();
        }

        if (telaAtual == 7) {
            telaAtual = personalizacao();
        }
    }

    
    return 0;
}