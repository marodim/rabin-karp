#include "rabin-karp.h"

int main()
{
    FILE *p_arquivo;
    char str[MAXCHAR];
    char* nome_arquivo = "./teste.txt";
    p_arquivo = fopen(nome_arquivo, "r");
    if(p_arquivo == NULL)
    {
	printf("Nao eh possivel abrir o arquivo %s", nome_arquivo);
	return 1;
    }	
    //strcpy(str, "234");
    //int h = hash(strlen(str), 0, 23, str);
    //Rolling* r = NULL;
    
    char txt[MAXCHAR] = "";
    while(fgets(str, MAXCHAR, p_arquivo) != NULL)
        strcat(txt,str); 
    printf("%s", txt);
    char pat[]="794";
    int n=strlen(txt);
    int m=strlen(pat);
    procurar(m,n,101,/*100*/txt,pat);
    //printf("%d\n", r->h);
    fclose(p_arquivo);
    return 0;
}
/*
hash 567 : 37
*/
