#include <stdio.h>

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