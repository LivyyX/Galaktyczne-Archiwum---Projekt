#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char name[100];
    char origin[100];
    char creator[100];
    int danger_lvl;
    int disc_year;
    char status[20];
} Artifact;

void registery(int n){
    
}

int mainmenu(){
    int choice;
    printf("\n==========ARTIFACT MANAGEMENT=========\n");
    printf("1.Zarejestruj artefakt.\n");
    printf("2.Wyszukaj artefakt.\n");
    printf("3.Modyfikuj artefakt.\n");
    printf("4.Sortuj artefakty.\n");
    printf("5.Usuń artefakt.\n");
    printf("0.Zapisz i wyjdź.\n");
    printf("Wybierz opcję:");
    int sc=scanf("%d",&choice);
    while (sc!=1 || choice<0 || choice>5){
        printf("Podano nieprawidłową wartość!\n");
        printf("Wybierz opcję:");
        sc=scanf("%d",&choice);
    }
    return choice;
}

int main(){
    Artifact *records=NULL;
    mainmenu();
}

