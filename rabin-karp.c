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

void procurar(int m, int n, int q,/* int h,*/ char tex[],char pad[]/*, Rolling* r*/)
{
    int i=0,
        j=0;

    int h_pad = hash(m, 0, q, pad);
    printf ("hash pad: %d\n", h_pad);

    int h_tex = hash(m, 0, q, tex);
    printf ("hash tex: %d\n", h_tex);

    int h=pow(D,m-1);
    h=h%q;
    /*
    int h=1;
    for (i = 0; i < m - 1; i++)
        h = (h * D) % q;*/

    printf("H: %d\n", h);
    for(i = 0; i <= n-m; i++)
    {

        if(h_pad == h_tex)
        {
            j = 0;
           // printf ("j antes do while: %d\n",j );
            while(j < m && (tex[j+i] == pad[j]))
            {
                j++;
            }
           // printf ("j depois do while: %d\n",j );
            if(j == m)
            {
                printf("te achei, corno, haha! pos: %d\n", i);
            }
        }
        printf("%d | %d \n", i, (n-m));
        if(i < n-m)
        {
            h_tex = rehash(m, i, q, h_tex, h, tex);

            printf("i: %d rehash: %d\n",i, h_tex);
        }
    }

}

int hash(int m, int pos, int q, char* texto)
{
    int hash = 0;

    for(int i = pos; i < (pos+m); i++)
    {

        hash = (hash*D + texto[i])%q;
        //printf("char: %d\n", texto[i]);
    }

    return hash;
}

int rehash(int m, int pos, int q, int hash, int h, char* texto)
{
   // printf("rehash\n");
    int rehash = (D*((hash)-texto[pos]*h) + texto[pos+m])%q;
    if(rehash < 0)
        rehash = (rehash+q);

   /* printf("pos: %d\n", pos);
    printf("rehash: %d\n", rehash);
    printf("\n");*/
    return rehash;
}
