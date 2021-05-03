#include "rabin-karp.h"

int main()
{
    char txt[MAXCHAR] = "";
    recebe_de_arquivo(txt, "./texto.txt");
    percorre_padrao("./padrao1.txt", txt);
    
    return 0;
}

