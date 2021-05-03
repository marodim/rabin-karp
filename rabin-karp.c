#include "rabin-karp.h"

void procurar(bool palavra_sozinha, int tamanho_pad, int tamanho_tex, int numero_primo, char tex[], char pad[])
{
    int i = 0,
        j = 0;
    int* posicoes = (int*)malloc(sizeof(int));
    int p = 0;
    int h_pad = hash(tamanho_pad, 0, numero_primo, pad);
    // printf ("hash pad: %d\n", h_pad);

    int h_tex = hash(tamanho_pad, 0, numero_primo, tex);
    //  printf ("hash tex: %d\n", h_tex);

    double hd = pow(D, tamanho_pad - 1);
    hd = fmod(hd, (double)numero_primo);
    int h = (int)hd;
    for (i = 0; i <= tamanho_tex - tamanho_pad; i++)
    {

        if (h_pad == h_tex)
        {
            j = 0;
            while (j < tamanho_pad && (tex[j + i] == pad[j]))
            {
                j++;
            }
            if (j == tamanho_pad)
            {
                posicoes[p] = i;
                p++;
                posicoes = (int*)realloc(posicoes, p * sizeof(int));
            }
            else
            {
                printf("vish, alarme falso :S pos: %d\n", i);
            }
        }
        if (i < tamanho_tex - tamanho_pad)
        {
            h_tex = rehash(tamanho_pad, i, numero_primo, h_tex, h, tex);
        }
    }
    /*for(int j=0;j<p;j++)
        printf("posicoes[%d]: %d\n", j, posicoes[j]);*/
    verifica_colisoes(palavra_sozinha, tamanho_pad, p, posicoes, tex, pad);
    printf("\n-------------------------------------------\n");
}

int hash(int tamanho_pad, int pos, int numero_primo, char* texto)
{
    int hash = 0;

    for (int i = pos; i < (pos + tamanho_pad); i++)
    {
        hash = (hash * D + texto[i]) % numero_primo;
    }

    return hash;
}

int rehash(int tamanho_pad, int posicao, int numero_primo, int hash, int h, char* texto)
{
    int rehash = (D * ((hash)-texto[posicao] * h) + texto[posicao + tamanho_pad]) % numero_primo;
    if (rehash < 0)
        rehash = (rehash + numero_primo);
    return rehash;
}

void recebe_de_arquivo(char* destino, char* nome_arquivo)
{
    FILE* p_arquivo;
    char str[MAXCHAR];
    p_arquivo = fopen(nome_arquivo, "r");
    if (p_arquivo == NULL)
    {
        printf("Nao eh possivel abrir o arquivo %s", nome_arquivo);
        exit(1);
    }
    char txt[MAXCHAR] = "";
    while (fgets(str, MAXCHAR, p_arquivo) != NULL)
    {
        if (str[strlen(str) - 1] == 10)
        {
            str[strlen(str) - 1] = '\0';
        }
        strcat(txt, str);
    }
    printf("Texto: \n%s\n", txt);
    fclose(p_arquivo);
    strcpy(destino, txt);
}

void percorre_padrao(char* nome_arquivo, char* txt)
{
    int tamanho_tex = strlen(txt);
    FILE* p_padrao;
    p_padrao = fopen(nome_arquivo, "r");

    if (p_padrao == NULL)
    {
        printf("Nao eh possivel abrir o arquivo %s", nome_arquivo);
        exit(1);
    }
    char* pad = (char*)malloc(MAXCHAR * sizeof(char));
    bool palavra_sozinha = false;
    while (fgets(pad, MAXCHAR, p_padrao) != NULL)
    {
        int tamanho_pad = strlen(pad) - 1;
        printf("pad[0]: %c\n", pad[0]);
        printf("pad[tamanho_pad-1]: %c\n", pad[tamanho_pad - 1]);
        if (pad[0] == 42 && pad[tamanho_pad - 1] == 42)
        {
            // printf("pos 0: %c | pos %d: %c\n",pad[0], tamanho_pad, pad[tamanho_pad-1]);
            palavra_sozinha = true;
            for (int i = 0; i < tamanho_pad; i++)
            {
                // printf("antes: %s\n", pad);
                pad[i] = pad[i + 1];
                //printf("depois: %s\n", pad);
            }
            tamanho_pad = tamanho_pad - 2;
            pad = (char*)realloc(pad, tamanho_pad * sizeof(char));

        }
        pad[tamanho_pad] = '\0';
        printf("\npadrao: %s\n", pad);
        procurar(palavra_sozinha, tamanho_pad, tamanho_tex, 599, txt, pad);
    }
    fclose(p_padrao);
}

void verifica_colisoes(bool palavra_sozinha, int tamanho_pad, int numero_pos, int* posicoes, char tex[], char pad[])
{
    int cont = 0;
    if (palavra_sozinha)
    {
        for (int i = 0; i < numero_pos; i++)
        {
            if ((tex[posicoes[i] - 1] == 32 || tex[posicoes[i] - 1] == 10) &&
                (tex[posicoes[i] + tamanho_pad] == 32 || tex[posicoes[i] + tamanho_pad] == 10))
            {
                printf("Palavra encontrada! Pos: %d\n", posicoes[i]);
                cont++;
            }
        }
        printf("\nA palavra \"%s\" foi encontrada %d vezes.\n", pad, cont);
    }
    else
    {
        for (int i = 0; i < numero_pos; i++)
        {
            printf("Padrao encontrado! Pos: %d\n", posicoes[i]);
            cont++;
        }
        printf("\nO padrao\"%s\" foi encontrado %d vezes.\n", pad, cont);
    }
    // return cont;
}