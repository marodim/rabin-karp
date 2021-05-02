#include "rabin-karp.h"

int main()
{
    char txt[MAXCHAR] = "";
    recebe_de_arquivo(txt, "./teste.txt");
    percorre_padrao("./padrao.txt", txt);
    
    return 0;
}

