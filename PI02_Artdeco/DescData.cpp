#include <iostream>
#include <vector>
#include "DescData.h"

void getTitulo(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Título: Mona Lisa"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Título: Name"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Título: Name"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Título: Name"); }
}

void getAutor(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Autor: Leonardo da Vinci"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Autor: Name"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Autor: Name"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Autor: Name"); }
}

void getLoc(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Localização: Louvre, Paris"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Localização: Name"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Localização: Name"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Localização: Name"); }
}

void getAno(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Ano: 1503"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Ano: Name"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Ano: Name"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Ano: Name"); }
}

void getQuadro(int level, char* buffer, size_t tamanho) {
	if (level == 0) { snprintf(buffer, tamanho, "./assets/img/monalisa_real.png"); }
	else if (level == 1) { snprintf(buffer, tamanho, "./assets/img/ex_o_grito.png"); }
	else if (level == 2) { snprintf(buffer, tamanho, "./assets/img/ex_cinco_mulheres.png"); }
	else if (level == 3) { snprintf(buffer, tamanho, "./assets/img/ex_primeiros_animais.png"); }
	else if (level == 4) { snprintf(buffer, tamanho, "./assets/img/ex_retirantes.png"); }
}

void getDesc(int level, int linha, char* buffer, size_t tamanho) {
	std::vector<std::string> desc;
	if (level == 0) {
		desc = { 
			"Mona Lisa tamb�m conhecida como A Gioconda",
			"ou ainda Mona Lisa del Giocondo � a mais",
			"not�vel e conhecida obra de Leonardo da Vinci,",
			"um dos mais eminentes homens do Renascimento",
			"italiano. Sua pintura foi iniciada em 1503 e �",
			"nesta obra que o artista melhor concebeu..."
		};
	}

	else if (level == 1) {
		desc = {
			"DESC L1",
			"DESC L2",
			"DESC L3",
			"DESC L4",
			"DESC L5",
			"DESC L6"
		};
	}

	snprintf(buffer, tamanho, desc[linha].c_str());
}