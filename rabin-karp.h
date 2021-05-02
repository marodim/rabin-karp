#ifndef _RABIN_KARP_H_
#define _RABIN_KARP_H_
#define D 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
typedef struct Rolling
{
    int m;
    int n;
    int q;
    int h;
    char* tex;
    char* pad;
}Rolling;
*/

//void inicializar(int m, int n, int q, char* tex, char* pad/*, Rolling* r*/);
int procurar(int m, int n, int q, int h, char tex[],char pad[]/*, Rolling* r*/);
int hash(int m, int pos, int q, char* texto);
int rehash(int m, int pos, int q, int hash, int h, char* texto);

#endif 
