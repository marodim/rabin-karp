#include "rabin-karp.h"

void procurar(int m, int n, int q, char tex[],char pad[])
{
    int i=0,
        j=0;
    int *posicoes = (int*)malloc(sizeof(int));
    int p = 0;
    int h_pad = hash(m, 0, q, pad);
    printf ("hash pad: %d\n", h_pad);

    int h_tex = hash(m, 0, q, tex);
    printf ("hash tex: %d\n", h_tex);

    double hd=pow(D,m-1);
    hd=fmod(hd,(double)q);
    int h = (int)hd;
    for(i = 0; i <= n-m; i++)
    {

        if(h_pad == h_tex)
        {
            j = 0;
            while(j < m && (tex[j+i] == pad[j]))
            {
                j++;
            }
            if(j == m)
            {
		posicoes[p] = i;
		p++;
		posicoes =(int*)realloc(posicoes,p*sizeof(int));
            }else
	    {
		printf("vish, alarme falso :S pos: %d\n", i);	
	    }
        }
        if(i < n-m)
        {
            h_tex = rehash(m, i, q, h_tex, h, tex);
        }
    }
    for(int j=0;j<p;j++)
	printf("posicoes[%d]: %d\n", j, posicoes[j]);
    verifica_colisoes(m, p, posicoes, tex);
}

int hash(int m, int pos, int q, char* texto)
{
    int hash = 0;

    for(int i = pos; i < (pos+m); i++)
    {
        hash = (hash*D + texto[i])%q;
    }

    return hash;
}

int rehash(int m, int pos, int q, int hash, int h, char* texto)
{
    int rehash = (D*((hash)-texto[pos]*h) + texto[pos+m])%q;
    if(rehash < 0)
        rehash = (rehash+q);
    return rehash;
}

void recebe_de_arquivo(char* destino, char* nome_arquivo)
{
    FILE *p_arquivo; 
    char str[MAXCHAR];
    p_arquivo = fopen(nome_arquivo, "r");
    if(p_arquivo == NULL)
    {
        printf("Nao eh possivel abrir o arquivo %s", nome_arquivo);
        exit(1);
    } 
    char txt[MAXCHAR] = "";
    while(fgets(str, MAXCHAR, p_arquivo) != NULL)
        strcat(txt,str);
    printf("texto: %s\n", txt);
    fclose(p_arquivo);
    strcpy(destino, txt);
} 

void percorre_padrao(char* nome_arquivo, char* txt)
{
    int n = strlen(txt);
    FILE *p_padrao;  
    p_padrao = fopen(nome_arquivo, "r");
    if(p_padrao == NULL)
    {
        printf("Nao eh possivel abrir o arquivo %s", nome_arquivo);
        exit(1);
    } 
    char pad[MAXCHAR] = "";
    while(fgets(pad, MAXCHAR, p_padrao) != NULL)
    {
	int m = strlen(pad)-1;
        printf("padrao: %s\n", pad);
        procurar(m,n,599,txt,pad);
    }
        fclose(p_padrao);
}

void verifica_colisoes(int m, int p, int* posicoes, char tex[])
{
    for(int i = 0; i < p; i++)
    {
	if((tex[posicoes[i]-1] == 32 || tex[posicoes[i]-1] == 10) &&
	   (tex[posicoes[i]+m] == 32 || tex[posicoes[i]+m] == 10))
	{
            printf("te achei, corno, haha! pos: %d\n", posicoes[i]);
	}

    }
}
