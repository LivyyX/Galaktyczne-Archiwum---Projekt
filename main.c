#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "list.h"

int main(){
    Node *lista = NULL;
    int choice;

    // do {
    //     mainmenu();
    //     int sc=scanf("%d",&choice);
    //     getchar();
    // }while (choice!=0);
    Artifact a1={"Alamakota","aa","abab",3,2137,0};
    lista=add(lista,a1);
    find_a(lista,"Alamakota");
    lista=delete_a(lista,"Alamakota");
    find_a(lista,"Alamakota");
    return 0;
}

