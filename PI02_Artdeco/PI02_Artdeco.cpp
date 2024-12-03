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

#include "Renascentismo.h"
#include "Impressionismo.h"
#include "Surrealismo.h"
#include "Expressionismo.h"
#include "Cubismo.h"
#include "Futurismo.h"

#include "ReFase1.h"

#include "DetalheReF1.h"

#include "DetalheImF1.h"

const int WIDTH = 1920;
const int HEIGHT = 985;

enum TelaAtiva {DEBUG, PRINCIPAL, OPTIONS, OBRA, VANGUARDAS, VISUALS, CARROSSEL, RENASCENTISMO, IMPRESSIONISMO, SURREALISMO, EXPRESSIONISMO, CUBISMO, FUTURISMO, DETALHEREF1, DETALHEIMF1, REFASE1};
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
        if (telaAtual == 1) {
            telaAtual = telaInicial(display, fasesDesbloqueadas);
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
            telaAtual = futurismo(display);
        }

        if (telaAtual == 11) {
            telaAtual = carrossel(display, fasesDesbloqueadas);
        }

        //IDS DE 12 Á 41
        if (telaAtual >= 12 && telaAtual <= 41) {
            if(telaAtual-12 == 0){ telaAtual = fase(display, &fasesDesbloqueadas[telaAtual - 12], telaAtual - 12, 1); }
            else if (fasesDesbloqueadas[telaAtual - 13] == 1) {
                telaAtual = fase(display, &fasesDesbloqueadas[telaAtual - 12], telaAtual - 12, 1);
            }
            else { telaAtual = (telaAtual - 12) / 5 + 5; }

            
        }

        //IDS DE 42 Á 71
        if (telaAtual >= 42) {
            telaAtual = detalheReF1(display, telaAtual - 42);
        }
    }

    al_destroy_display(display);
    return 0;
}