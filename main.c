#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "file.h"

int main(){
    Node *lista = NULL;
    int choice;

    do {
        mainmenu();
        int sc=scanf("%d",&choice);
        getchar();
    }while (choice!=0);

    writetofile(lista,"artifacts.txt");
    freelist(lista);
    return 0;
}

