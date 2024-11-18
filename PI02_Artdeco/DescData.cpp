#include <iostream>
#include <vector>
#include "DescData.h"

void getTitulo(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Título: Mona Lisa"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Título: A criação de Adão"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Título: Escola de Atenas"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Título: O Nascimento de Vênus"); }
	else if (level == 4) { snprintf(buffer, tamanho, "Título: A Última Ceia"); }

	else if (level == 5) { snprintf(buffer, tamanho, "Título: Impressão, Sol Nascente"); }
	else if (level == 6) { snprintf(buffer, tamanho, "Título: Mulheres no Jardim"); }
	else if (level == 7) { snprintf(buffer, tamanho, "Título: A Estação Saint-Lazare"); }
	else if (level == 8) { snprintf(buffer, tamanho, "Título: Campo de Papoulas"); }
	else if (level == 9) { snprintf(buffer, tamanho, "Título: O Almoço dos Remadores"); }

	else if (level == 10) { snprintf(buffer, tamanho, "Título: A Persistência da Memória"); }
	else if (level == 11) { snprintf(buffer, tamanho, "Título: O Filho do Homem"); }
	else if (level == 12) { snprintf(buffer, tamanho, "Título: O Grande Masturbador"); }
	else if (level == 13) { snprintf(buffer, tamanho, "Título: Os Amantes"); }
	else if (level == 14) { snprintf(buffer, tamanho, "Título: Os Elefantes"); }

	else if (level == 15) { snprintf(buffer, tamanho, "Título: Les Demoiselles d'Avignon"); }
	else if (level == 16) { snprintf(buffer, tamanho, "Título: Retrato de Ambroise Vollard"); }
	else if (level == 17) { snprintf(buffer, tamanho, "Título: Violinista"); }
	else if (level == 18) { snprintf(buffer, tamanho, "Título: Garrafa de Suze"); }
	else if (level == 19) { snprintf(buffer, tamanho, "Título: O Poeta"); }

	else if (level == 20) { snprintf(buffer, tamanho, "Título: Dinamismo de um Cão na Coleira"); }
	else if (level == 21) { snprintf(buffer, tamanho, "Título: A Cidade que Sobe"); }
	else if (level == 22) { snprintf(buffer, tamanho, "Título: Solidez da Névoa"); }
	else if (level == 23) { snprintf(buffer, tamanho, "Título: Dinamismo de um Carro"); }
	else if (level == 24) { snprintf(buffer, tamanho, "Título: Elasticidade"); }

	else if (level == 25) { snprintf(buffer, tamanho, "Título: O Grito"); }
	else if (level == 26) { snprintf(buffer, tamanho, "Título: Noite Estrelada"); }
	else if (level == 27) { snprintf(buffer, tamanho, "Título: Os Primeiros Animais"); }
	else if (level == 28) { snprintf(buffer, tamanho, "Título: Cinco Mulheres na Rua"); }
	else if (level == 29) { snprintf(buffer, tamanho, "Título: Retirantes"); }
}

void getAutor(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Autor: Leonardo da Vinci"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Autor: Michelangelo Buonarroti"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Autor: Rafael Sanzio"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Autor: Sandro Botticelli"); }
	else if (level == 4) { snprintf(buffer, tamanho, "Autor: Leonardo da Vinci"); }

	else if (level == 5) { snprintf(buffer, tamanho, "Autor: Claude Monet"); }
	else if (level == 6) { snprintf(buffer, tamanho, "Autor: Claude Monet"); }
	else if (level == 7) { snprintf(buffer, tamanho, "Autor: Claude Monet"); }
	else if (level == 8) { snprintf(buffer, tamanho, "Autor: Claude Monet"); }
	else if (level == 9) { snprintf(buffer, tamanho, "Autor: Pierre-Auguste Renoir"); }

	else if (level == 10) { snprintf(buffer, tamanho, "Autor: Salvador Dalí"); }
	else if (level == 11) { snprintf(buffer, tamanho, "Autor: René Magritte"); }
	else if (level == 12) { snprintf(buffer, tamanho, "Autor: Salvador Dalí"); }
	else if (level == 13) { snprintf(buffer, tamanho, "Autor: René Magritte"); }
	else if (level == 14) { snprintf(buffer, tamanho, "Autor: Salvador Dalí"); }

	else if (level == 15) { snprintf(buffer, tamanho, "Autor: Pablo Picasso"); }
	else if (level == 16) { snprintf(buffer, tamanho, "Autor: Pablo Picasso"); }
	else if (level == 17) { snprintf(buffer, tamanho, "Autor: Georges Braque"); }
	else if (level == 18) { snprintf(buffer, tamanho, "Autor: Pablo Picasso"); }
	else if (level == 19) { snprintf(buffer, tamanho, "Autor: Pablo Picasso"); }

	else if (level == 20) { snprintf(buffer, tamanho, "Autor: Giacomo Balla"); }
	else if (level == 21) { snprintf(buffer, tamanho, "Autor: Umberto Boccioni"); }
	else if (level == 22) { snprintf(buffer, tamanho, "Autor: Luigi Russolo"); }
	else if (level == 23) { snprintf(buffer, tamanho, "Autor: Luigi Russolo"); }
	else if (level == 24) { snprintf(buffer, tamanho, "Autor: Umberto Boccioni"); }

	else if (level == 25) { snprintf(buffer, tamanho, "Autor: Edvard Munch"); }
	else if (level == 26) { snprintf(buffer, tamanho, "Autor: Vincent van Gogh"); }
	else if (level == 27) { snprintf(buffer, tamanho, "Autor: Franz Marc"); }
	else if (level == 28) { snprintf(buffer, tamanho, "Autor: Ernst Ludwig Kirchner"); }
	else if (level == 29) { snprintf(buffer, tamanho, "Autor: Cândido Portinari"); }
}

void getLoc(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Localização: Museu do Louvre, Paris, França"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Localização: Capela Sistina, Cidade do Vaticano"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Localização: Palácio Apostólico, Vaticano"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Localização: Galeria Uffizi, Florença, Itália"); }
	else if (level == 4) { snprintf(buffer, tamanho, "Localização: Convento de Santa Maria delle Grazie, Milão, Itália"); }

	else if (level == 5) { snprintf(buffer, tamanho, "Localização: Museu Marmottan Monet, Paris, França"); }
	else if (level == 6) { snprintf(buffer, tamanho, "Localização: Museu d'Orsay, Paris, França"); }
	else if (level == 7) { snprintf(buffer, tamanho, "Localização: Museu d'Orsay, Paris, França"); }
	else if (level == 8) { snprintf(buffer, tamanho, "Localização: Museu d'Orsay, Paris, França"); }
	else if (level == 9) { snprintf(buffer, tamanho, "Localização: The Phillips Collection, Washington, D.C., EUA"); }

	else if (level == 10) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna (MoMA), Nova York, EUA"); }
	else if (level == 11) { snprintf(buffer, tamanho, "Localização: Coleção Privada"); }
	else if (level == 12) { snprintf(buffer, tamanho, "Localização: Museu Nacional Centro de Arte Reina Sofia, Madri, Espanha"); }
	else if (level == 13) { snprintf(buffer, tamanho, "Localização: Museu Nacional de Arte Moderna, Paris, França"); }
	else if (level == 14) { snprintf(buffer, tamanho, "Localização: Coleção Privada"); }

	else if (level == 15) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna (MoMA), Nova York, EUA"); }
	else if (level == 16) { snprintf(buffer, tamanho, "Localização: Museu Pushkin, Moscou, Rússia"); }
	else if (level == 17) { snprintf(buffer, tamanho, "Localização: Kunstmuseum Basel, Suíça"); }
	else if (level == 18) { snprintf(buffer, tamanho, "Localização: Museu de Arte de Chicago, EUA"); }
	else if (level == 19) { snprintf(buffer, tamanho, "Localização: Museu Guggenheim, Nova York, EUA"); }

	else if (level == 20) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna (MoMA), Nova York, EUA"); }
	else if (level == 21) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna, Nova York, EUA"); }
	else if (level == 22) { snprintf(buffer, tamanho, "Localização: Coleção Privada"); }
	else if (level == 23) { snprintf(buffer, tamanho, "Localização: Coleção Privada"); }
	else if (level == 24) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna, Milão, Itália"); }

	else if (level == 25) { snprintf(buffer, tamanho, "Localização: Museu Munch, Oslo, Noruega"); }
	else if (level == 26) { snprintf(buffer, tamanho, "Localização: Museu de Arte Moderna (MoMA), Nova York, EUA"); }
	else if (level == 27) { snprintf(buffer, tamanho, "Localização: Museu de Arte de Basileia, Suíça"); }
	else if (level == 28) { snprintf(buffer, tamanho, "Localização: Museu Ludwig, Colônia, Alemanha"); }
	else if (level == 29) { snprintf(buffer, tamanho, "Localização: Museu de Arte de São Paulo (MASP), São Paulo, Brasil"); }
}

void getAno(int level, char* buffer, size_t tamanho) {

	if (level == 0) { snprintf(buffer, tamanho, "Ano: 1503-1506"); }
	else if (level == 1) { snprintf(buffer, tamanho, "Ano: 1512"); }
	else if (level == 2) { snprintf(buffer, tamanho, "Ano: 1509-1511"); }
	else if (level == 3) { snprintf(buffer, tamanho, "Ano: 1485-1486"); }
	else if (level == 4) { snprintf(buffer, tamanho, "Ano: 1495-1498"); }

	else if (level == 5) { snprintf(buffer, tamanho, "Ano: 1872"); }
	else if (level == 6) { snprintf(buffer, tamanho, "Ano: 1866"); }
	else if (level == 7) { snprintf(buffer, tamanho, "Ano: 1877"); }
	else if (level == 8) { snprintf(buffer, tamanho, "Ano: 1873"); }
	else if (level == 9) { snprintf(buffer, tamanho, "Ano: 1881"); }

	else if (level == 10) { snprintf(buffer, tamanho, "Ano: 1931"); }
	else if (level == 11) { snprintf(buffer, tamanho, "Ano: 1964"); }
	else if (level == 12) { snprintf(buffer, tamanho, "Ano: 1929"); }
	else if (level == 13) { snprintf(buffer, tamanho, "Ano: 1928"); }
	else if (level == 14) { snprintf(buffer, tamanho, "Ano: 1948"); }

	else if (level == 15) { snprintf(buffer, tamanho, "Ano: 1907"); }
	else if (level == 16) { snprintf(buffer, tamanho, "Ano: 1910"); }
	else if (level == 17) { snprintf(buffer, tamanho, "Ano: 1912"); }
	else if (level == 18) { snprintf(buffer, tamanho, "Ano: 1912"); }
	else if (level == 19) { snprintf(buffer, tamanho, "Ano: 1911"); }

	else if (level == 20) { snprintf(buffer, tamanho, "Ano: 1912"); }
	else if (level == 21) { snprintf(buffer, tamanho, "Ano: 1910-1911"); }
	else if (level == 22) { snprintf(buffer, tamanho, "Ano: 1912"); }
	else if (level == 23) { snprintf(buffer, tamanho, "Ano: 1912"); }
	else if (level == 24) { snprintf(buffer, tamanho, "Ano: 1912"); }

	else if (level == 25) { snprintf(buffer, tamanho, "Ano: 1893"); }
	else if (level == 26) { snprintf(buffer, tamanho, "Ano: 1889"); }
	else if (level == 27) { snprintf(buffer, tamanho, "Ano: 1913"); }
	else if (level == 28) { snprintf(buffer, tamanho, "Ano: 1913"); }
	else if (level == 29) { snprintf(buffer, tamanho, "Ano: 1944"); }
}

void getQuadro(int level, char* buffer, size_t tamanho) {
	if (level == 0) { snprintf(buffer, tamanho, "./assets/img/re_monalisa.png"); }
	else if (level == 1) { snprintf(buffer, tamanho, "./assets/img/re_criacao_de_adao.png"); }
	else if (level == 2) { snprintf(buffer, tamanho, "./assets/img/re_escola_de_atenas.png"); }
	else if (level == 3) { snprintf(buffer, tamanho, "./assets/img/re_nascimento_de_venus.png"); }
	else if (level == 4) { snprintf(buffer, tamanho, "./assets/img/re_ultima_ceia.png"); }

	else if (level == 5) { snprintf(buffer, tamanho, "./assets/img/Im_impressao_sol_nascente.png"); }
	else if (level == 6) { snprintf(buffer, tamanho, "./assets/img/Im_mulheres_no_jardim.png"); }
	else if (level == 7) { snprintf(buffer, tamanho, "./assets/img/Im_estacao_saint_lazare.png"); }
	else if (level == 8) { snprintf(buffer, tamanho, "./assets/img/Im_campo_de_papoulas.png"); }
	else if (level == 9) { snprintf(buffer, tamanho, "./assets/img/Im_almoco_remadores.png"); }

	else if (level == 10) { snprintf(buffer, tamanho, "./assets/img/su_persistencia_da_memoria.png"); }
	else if (level == 11) { snprintf(buffer, tamanho, "./assets/img/su_filho_do_homem.png"); }
	else if (level == 12) { snprintf(buffer, tamanho, "./assets/img/su_o_grande_masturbador.png"); }
	else if (level == 13) { snprintf(buffer, tamanho, "./assets/img/su_os_amantes.png"); }
	else if (level == 14) { snprintf(buffer, tamanho, "./assets/img/su_os_elefantes.png"); }

	else if (level == 15) { snprintf(buffer, tamanho, "./assets/img/cu_les_demoiselles.png"); }
	else if (level == 16) { snprintf(buffer, tamanho, "./assets/img/cu_retrato_de_ambroise.png"); }
	else if (level == 17) { snprintf(buffer, tamanho, "./assets/img/cu_violinista.png"); }
	else if (level == 18) { snprintf(buffer, tamanho, "./assets/img/cu_garrafa_de_suze.png"); }
	else if (level == 19) { snprintf(buffer, tamanho, "./assets/img/cu_o_poeta.png"); }

	else if (level == 20) { snprintf(buffer, tamanho, "./assets/img/fu_dinamismo.png"); }
	else if (level == 21) { snprintf(buffer, tamanho, "./assets/img/fu_a_cidade_sobe.png"); }
	else if (level == 22) { snprintf(buffer, tamanho, "./assets/img/fu_solidez_da_nevoa.png"); }
	else if (level == 23) { snprintf(buffer, tamanho, "./assets/img/fu_dinamismo_de_um_carro.png"); }
	else if (level == 24) { snprintf(buffer, tamanho, "./assets/img/fu_elasticidade.png"); }

	else if (level == 25) { snprintf(buffer, tamanho, "./assets/img/ex_o_grito.png"); }
	else if (level == 26) { snprintf(buffer, tamanho, "./assets/img/ex_noite_estrelada.png"); }
	else if (level == 27) { snprintf(buffer, tamanho, "./assets/img/ex_primeiros_animais.png"); }
	else if (level == 28) { snprintf(buffer, tamanho, "./assets/img/ex_cinco_mulheres.png"); }
	else if (level == 29) { snprintf(buffer, tamanho, "./assets/img/ex_retirantes.png"); }

}

void getDesc(int level, int linha, char* buffer, size_t tamanho) {
	std::vector<std::string> desc;
	if (level == 0) {
		desc = { 
			"Retrato icônico de uma mulher com um leve sorriso",
			"enigmático.Da Vinci explora a técnica do",
			"sfumato para criar transições suaves e dar",
			"profundidade à expressão de Mona Lisa.",
		};
	}

	else if (level == 1) {
		desc = {
			"Parte do teto da Capela Sistina, essa obra",
			"monumental mostra o momento bíblico em que",
			"Deus dá vida a Adão.Michelangelo exalta a",
			"anatomia humana, capturando detalhes",
			"precisos e a grandiosidade da figura humana.",
		};
	}

	else if (level == 2) {
		desc = {
			"Uma representação de grandes pensadores da",
			"Antiguidade, incluindo Platão e Aristóteles.",
			"Rafael combina perspectiva e proporção para",
			"criar uma composição equilibrada e harmônica.",
		};
	}

	else if (level == 3) {
		desc = {
			"Esta obra mostra a deusa Vênus emergindo do",
			"mar sobre uma concha.Botticelli usa linhas",
			"delicadas e cores suaves para criar uma imagem",
			"etérea e idealizada da beleza feminina.",
		};
	}

	else if (level == 4) {
		desc = {
			"Cena bíblica que representa a última refeição",
			"de Jesus com seus apóstolos.Da Vinci aplica",
			"perspectiva e simetria, além de expressões",
			"detalhadas nos rostos, para intensificar o",
			"drama da cena."
		};
	}


	else if (level == 5) {
		desc = {
			"Considerada a obra que deu nome ao movimento",
			"impressionista, esta pintura mostra o porto",
			"de Le Havre ao amanhecer.Monet utiliza",
			"pinceladas rápidas e soltas para capturar a",
			"luz e o movimento, em vez de detalhes."
		};
	}

	else if (level == 6) {
		desc = {
			"Pintura que mostra quatro mulheres em um",
			"jardim.Monet foi revolucionário em sua",
			"abordagem de luz e sombras, representando",
			"as figuras sob a luz solar."			
		};
	}

	else if (level == 7) {
		desc = {
			"Uma das várias representações da estação",
			"ferroviária Saint - Lazare.Monet captura a",
			"movimentação e a fumaça da estação, usando",
			"pinceladas que sugerem o dinamismo da cena."
		};
	}

	else if (level == 8) {
		desc = {
			"Esta obra exibe um campo de papoulas em",
			"Argenteuil.Monet utiliza cores vibrantes e",
			"pinceladas rápidas para capturar a sensação",
			"de estar ao ar livre."
		};
	}

	else if (level == 9) {
		desc = {
			"Uma cena de confraternização entre amigos à",
			"beira de um rio.Renoir destaca a atmosfera",
			"leve e despreocupada, usando cores vivas e",
			"uma luz suave."
		};
	}


	else if (level == 10) {
		desc = {
			"Mostra relógios derretendo em uma paisagem",
			"surreal, refletindo a noção de tempo fluido e",
			"distorcido."
		};
	}

	else if (level == 11) {
		desc = {
			"Uma figura com uma maçã flutuante cobrindo o",
			"rosto, simbolizando mistério e identidade."
		};
	}

	else if (level == 12) {
		desc = {
			"Uma obra enigmática que explora os desejos e",
			"temáticas psicológicas de Dalí através de",
			"imagens simbólicas."
		};
	}

	else if (level == 13) {
		desc = {
			"Retrata um casal com rostos cobertos por tecido,",
			"um tema enigmático que explora a ocultação e o",
			"desconhecido."
		};
	}

	else if (level == 14) {
		desc = {
			"Mostra elefantes com pernas longas e finas,",
			"uma cena surreal que representa força e",
			"fragilidade."
		};
	}


	else if (level == 15) {
		desc = {
			"Obra pioneira do Cubismo, mostra cinco mulheres",
			"em uma forma angular e fragmentada, explorando",
			"a desconstrução do corpo humano."
		};
	}

	else if (level == 16) {
		desc = {
			"Um retrato em estilo cubista de um dos patronos",
			"de Picasso, onde a figura é decomposta em planos",
			"geométricos."
		};
	}

	else if (level == 17) {
		desc = {
			"Braque desconstrói a figura de um violinista,",
			"explorando diferentes ângulos em uma única superfície."
		};
	}

	else if (level == 18) {
		desc = {
			"Uma colagem cubista que usa recortes de jornal",
			"e papel de parede para criar uma composição abstrata."
		};
	}

	else if (level == 19) {
		desc = {
			"Representa um poeta em uma composição fragmentada",
			"e complexa, revelando vários ângulos de forma",
			"simultânea."
		};
	}


	else if (level == 20) {
		desc = {
			"Balla usa sobreposição e repetição para capturar",
			"o movimento de um cão andando com sua dona.A obra",
			"mostra o interesse futurista pela velocidade e dinamismo."
		};
	}

	else if (level == 21) {
		desc = {
			"Esta obra representa a construção de uma cidade,",
			"com figuras e cavalos em movimento frenético.",
			"Boccioni busca mostrar a energia caótica da",
			"urbanização e do progresso."
		};
	}

	else if (level == 22) {
		desc = {
			"A pintura abstrata de Russolo, do movimento",
			"futurista, busca representar a dinâmica da",
			"modernidade e a experiência da névoa, usando",
			"formas vibrantes e cores turvas para explorar",
			"a transição entre o sólido e o fluido.A obra",
			"reflete a tensão entre a solidez e a efemeridade.",		 
		};
	}

	else if (level == 23) {
		desc = {
			"Russolo retrata a velocidade de um carro em movimento,",
			"com linhas agressivas e formas que se desintegram,",
			"ressaltando o poder e a energia do veículo."
		};
	}

	else if (level == 24) {
		desc = {
			"Uma pintura que captura a energia vibrante do movimento,",
			"com formas distorcidas e cores intensas.Boccioni explora",
			"a força bruta e a sensação de movimento em um corpo em ação."
		};
	}


	else if (level == 25) {
		desc = {
			"Esta pintura icônica expressa a angústia e o desespero",
			"humano.A figura central, com uma expressão de horror,",
			"reflete a ansiedade existencial, enquanto o fundo",
			"distorcido e as cores vibrantes intensificam o clima de tensão."
		};
	}

	else if (level == 26) {
		desc = {
			"Embora Van Gogh não seja tradicionalmente um expressionista,",
			"esta obra foi influente para o movimento.Mostra uma paisagem",
			"noturna vista da janela do asilo onde ele estava internado.",
			"As linhas curvas e as cores intensas expressam as emoções",
			"turbulentas do artista."
		};
	}

	else if (level == 27) {
		desc = {
			"Franz Marc representa animais com formas simplificadas",
			"e cores vibrantes, numa tentativa de expressar a",
			"espiritualidade e a pureza da natureza.A obra destaca",
			"a influência do Expressionismo em evocar emoção e",
			"simbolismo por meio da cor."
		};
	}

	else if (level == 28) {
		desc = {
			"Esta obra retrata cinco mulheres com expressões de",
			"isolamento e alienação.Kirchner utiliza figuras",
			"alongadas e distorcidas, enfatizando a angústia e a",
			"frieza da vida urbana, tema comum no Expressionismo."
		};
	}

	else if (level == 29) {
		desc = {
			"Inspirado pela situação dos migrantes nordestinos",
			"brasileiros, Portinari retrata figuras sofridas e",
			"magras que refletem a miséria e a fome.O uso de",
			"cores escuras e as expressões de desespero capturam",
			"o drama social, fazendo deste um exemplo único de",
			"Expressionismo no contexto brasileiro."
		};
	}

	snprintf(buffer, tamanho, desc[linha].c_str());
}