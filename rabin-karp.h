#ifndef _RABIN_KARP_H_
#define _RABIN_KARP_H_
#define D 256 
#define MAXCHAR 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void procurar(bool palavra_sozinha, int tamanho_pad, int, int numero_primo, char tex[], char pad[]);
int hash(int tamanho_pad, int pos, int numero_primo, char* texto);
int rehash(int tamanho_pad, int posicao, int numero_primo, int hash, int h, char* texto);

void recebe_de_arquivo(char* destino, char* nome_arquivo);
void percorre_padrao(char* nome_arquivo, char* txt);

void verifica_colisoes(bool palavra_sozinha, int tamanho_pad, int numero_pos, int* posicoes, char tex[], char pad[]);

#endif