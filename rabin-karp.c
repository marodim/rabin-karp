#include "rabin-karp.h"
/*
void inicializar(int m, int n, int q, char* tex, char* pad, Rolling* r)
{
    
    r = (Rolling*)malloc(sizeof(Rolling));
    r->m = m;
    r->n = n;
    r->q = q;
    for (int i = 0; i < (r->m)-1; i++)
        r->h = (r->h*D)%(r->q);
    r->tex = (char*)malloc((n+1)*sizeof(char));
    r->pad = (char*)malloc((m+1)*sizeof(char));
    strcpy(r->tex, tex);
    strcpy(r->pad, pad);
    //printf("oi\n");

}*/

int procurar(int m, int n, int q, int h, char tex[],char pad[]/*, Rolling* r*/)
{
    //inicializar(m, n, q, tex, pad, r);
    //printf("h: %d\n", r->h);
    int i=0,
        j=0;
    int h_pad = hash(m, 0, q, pad);
    int h_tex = hash(m, 0, q, tex);

    for(i = 0; i <= n-m; i++)
    {
        
        if(h_pad == h_tex)
        {
            //printf("oi for if\n");
            //compara um por um
            j = 0;
            while(j < m && pad[j+i] == tex[j])
            {
                j++;
                printf("oi\n");
            }
            if(j == m)
            {
                printf("te achei, corno, haha! pos: %d\n", i);
            }
        }
        if(i < n-m)
        {
            printf("oloco\n");
            h_tex = rehash(m, i, q, h_tex, h, tex);
        }
        printf("fim do for\n");
    }

}

int hash(int m, int pos, int q, char* texto)
{
    int hash = 0;
    
    for(int i = pos; i < (pos+m); i++)
    {
       
        hash = ((hash*D + texto[i]) % q);
        //printf("char: %d\n", texto[i]);
        
    }
    printf("pos: %d\n", pos);
    printf("hash: %d\n", hash);
    printf("\n");
    return hash;
}

int rehash(int m, int pos, int q, int hash, int h, char* texto)
{
    printf("rehash\n");
  
    int rehash = (((D*(hash)-texto[pos]*h) + texto[pos+m]) % q);
    if(rehash < 0)
        rehash = rehash+q;

    printf("pos: %d\n", pos);
    printf("rehash: %d\n", rehash);
    printf("\n");
    return rehash;
}