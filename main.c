#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "list.h"
#include "file.h"

int main(){
    Node *lista =load_from_file("artefakty.txt");
    
    mainmenu(&lista);

    write_to_file(lista,"artefakty.txt");
    freelist(lista);
    return 0;
}

