#ifndef DESCDATA_H
#define DESCDATA_H

#include <allegro5/allegro.h>

void getQuadro(int level, char* buffer, size_t tamanho);
void getTitulo(int level, char* buffer, size_t tamanho);
void getAutor(int level, char* buffer, size_t tamanho);
void getLoc(int level, char* buffer, size_t tamanho);
void getAno(int level, char* buffer, size_t tamanho);
void getDesc(int level, int linha, char* buffer, size_t tamanho);
#endif