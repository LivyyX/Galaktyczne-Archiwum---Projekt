#include "validation.h"
#include <string.h>
#include <stdio.h>

int validate_name(const char *name,Node *head){
    if (!name || strlen(name)==0 || strlen(name)>MAX_NAME){
        printf("Niepoprawna nazwa!\n");
        return 0;
    }
    if (find_a(head,name)){
        printf("Artefakt o nazwie %s już istnieje!\n",name);
        return 0;
    }
    return 1;
}
int validate_text(const char *txt){
    if(!txt || strlen(txt)==0 || strlen(txt)>MAX_TXT){
        printf("Zostala wprowadzona zla wartosc!\n");
        return 0;
    }
    return 1;
}
int validate_danger(int lvl){
    if(lvl<0 || lvl>10){
        printf("Wprowadzono wartość poza zakresem 0-10!\n");
        return 0;
    }
    return 1;
}
int validate_year(int year){
    if (year>2471){
        printf("Nieprawidlowy rok odkrycia!\n");
        return 0;
    }
    return 1;
}
int validate_status(int status){
    if (status<BEZPIECZNY || status>W_TRAKCIE_BADAN){
        printf("Niepoprawny status!\n");
        return 0;
    }
    return 1;
}

int validate_artifact(Artifact *a,Node *head){
    return 
    validate_name(a->name,head) &&
    validate_text(a->origin) &&
    validate_text(a->creator) &&
    validate_danger(a->danger_lvl) &&
    validate_year(a->disc_year) &&
    validate_status(a->status);
}