#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "TelaPrincipal.h"
#include "Options.h"
#include "DetalhesObra.h"
#include "Vanguardas.h"
#include "Visuals.h"
#include "Carrossel.h"
#include "Pause.h"

#include "Renascentismo.h"
#include "Impressionismo.h"
#include "Surrealismo.h"
#include "Expressionismo.h"
#include "Cubismo.h"

#include "ReFase1.h"

#include "DetalheReF1.h"

#include "DetalheImF1.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

enum TelaAtiva {DEBUG, PRINCIPAL, OPTIONS, OBRA, VANGUARDAS, VISUALS, CARROSSEL, RENASCENTISMO, IMPRESSIONISMO, SURREALISMO, EXPRESSIONISMO, CUBISMO, DETALHEREF1, DETALHEIMF1, REFASE1, PAUSE};
int telaAtual = 1;
int fasesDesbloqueadas[30];
int quadrosDesb[30] = {1, 1, 1, 1, 1};


int main() {
    
    for (int i = 0; i < 30; i++) { fasesDesbloqueadas[i] = 0; }

    al_init();
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
    al_acknowledge_resize(display);

    while (telaAtual != 0) {
        if (telaAtual == -1) {
            telaInicial(display);
            renascentismo(display);
            fase(display, &fasesDesbloqueadas[0], 0, 1);
            opcoes(display);
            detalheObra(display);
            vanguardas(display);
            personalizacao(display);
        }

        if (telaAtual == 1) {
            telaAtual = telaInicial(display);
        }

        if (telaAtual == 2) {
            telaAtual = personalizacao(display);
        }

        if (telaAtual == 3) {
            telaAtual = opcoes(display);
        }

        if (telaAtual == 4) {
            telaAtual = vanguardas(display);
        }

        if (telaAtual == 5) {
            telaAtual = renascentismo(display);
        }

        if (telaAtual == 6) {
            telaAtual = impressionismo(display);
        }

        if (telaAtual == 7) {
            telaAtual = surrealismo(display);
        }

        if (telaAtual == 8) {
            telaAtual = expressionismo(display);
        }

        if (telaAtual == 9) {
            telaAtual = cubismo(display);
        }

        if (telaAtual == 10) {
            //FUTURISMO
        }

        if (telaAtual == 11) {
            telaAtual = carrossel(display, quadrosDesb);
        }

        //IDS DE 12 Á 41
        if (telaAtual >= 12 && telaAtual <= 41) {
            //COMO É A PRIMEIRA FASE N TEM IF, NAS SEGUINTES FAZER 
            //if(fasesDesbloqueadas[I - 1] == 1)
            //else{ telaAtual = SELEÇÃO DE TELA BASEADA NA VANGUARDA (RENASCENTISMO = 2)}

            telaAtual = fase(display, &fasesDesbloqueadas[telaAtual-12], telaAtual-12, 4);
        }

        //IDS DE 42 Á 71
        if (telaAtual >= 42) {
            telaAtual = detalheReF1(display, telaAtual - 42, 6);
        }

    }

    al_destroy_display(display);
    return 0;
}