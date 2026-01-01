#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "list.h"
#include "file.h"

int main(int argc,char *argv[]){
    if (argc<2){
        printf("Uzycie programu:\n");
        printf("%s <plik_z_danymi>\n",argv[0]);
        return 1;
    }
    const char *filename=argv[1];
    Node *lista =load_from_file(filename);
    
    mainmenu(&lista);

    write_to_file(lista,filename);
    freelist(lista);
    return 0;
}

