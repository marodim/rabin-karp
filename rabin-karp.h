#ifndef _RABIN_KARP_H_
#define _RABIN_KARP_H_
#define D 256 
#define MAXCHAR 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void procurar(int m, int n, int q, char tex[], char pad[]);
int hash(int m, int pos, int q, char* texto);
int rehash(int m, int pos, int q, int hash, int h, char* texto);
void recebe_de_arquivo(char* destino, char* nome_arquivo);
void percorre_padrao(char* nome_arquivo, char* txt);
void verifica_colisoes(int m, int p, int* posicoes, char tex[]);

#endif

