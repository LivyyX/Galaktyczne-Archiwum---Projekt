#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "list.h"
#include "file.h"

int main(){
    Node *lista = NULL;
    lista=load_from_file("artefakty.txt");
    int choice;
    Artifact a1={"Alama7kota","aa","abab",3,2137,0};
    lista=add(lista,a1);
    find_a(lista,"Alamako33ta");
    display(lista);
    write_to_file(lista,"artefakty.txt");
    freelist(lista);
    return 0;
}

