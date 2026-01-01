#include "menu.h"
#include "validation.h"
#include "file.h"
#include <stdio.h>
#include <string.h>

void print_menu(){
    printf("\n--- GALAKTYCZNE ARCHIWUM ARTEFAKTOW ---\n");
    printf("1. Wyswietl artefakty\n");
    printf("2. Dodaj artefakt\n");
    printf("3. Usun artefakt\n");
    printf("4. Wyszukaj artefakt\n");
    printf("5. Sortuj po nazwie\n");
    printf("6. Sortuj po poziomie zagrozenia\n");
    printf("7. Edytuj artefakt\n");
    printf("0.Zapisz i wyjdź.\n");
    printf("Wybierz opcję:");
}

static void menu_add(Node **head){
    Artifact a;
    do{
        printf("Nazwa: ");
        fgets(a.name,MAX_NAME,stdin);
        a.name[strcspn(a.name,"\n")]='\0';

        printf("Pochodzenie: ");
        fgets(a.origin,MAX_TXT,stdin);
        a.origin[strcspn(a.origin,"\n")]='\0';

        printf("Cywilizacja: ");
        fgets(a.creator,MAX_TXT,stdin);
        a.creator[strcspn(a.creator,"\n")]='\0';

        printf("Poziom zagrozenia (0-10): ");
        scanf("%d", &a.danger_lvl);

        printf("Rok odkrycia: ");
        scanf("%d", &a.disc_year);

        printf("Status (0-bezpieczny, 1-niestabilny, 2-zakazany, 3-kwarantanna, 4-badania): ");
        scanf("%d", (int*)&a.status);
        getchar();
    }while (!validate_artifact(&a,*head));
    *head=add(*head,a);
    printf("Dodano artefakt!\n");
}

static void menu_delete(Node **head){
    char name[MAX_NAME];

    printf("Podaj nazwe do usuniecia: ");
    fgets(name,MAX_NAME,stdin);
    name[strcspn(name,"\n")]=0;

    *head = delete_a(*head,name);
}

static void menu_find(Node *head){
    char name[MAX_NAME];

    printf("Podaj nazwe: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0;

    Node *f = find_a(head, name);
    if (f)
        display(f);
    else
        printf("Nie znaleziono artefaktu.\n");
}


int mainmenu(Node **head){
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // \n

        switch (choice) {
        case 1:
            display(*head);
            break;
        case 2:
            menu_add(head);
            break;
        case 3:
            menu_delete(head);
            break;
        case 4:
            menu_find(*head);
            break;
        case 5:
            *head = sort_by_name(*head);
            break;
        case 6:
            *head = sort_by_danger(*head);
            break;
        case 7:
            char name[MAX_NAME];
            printf("Podaj nazwe artefaktu do edycji: ");
            fgets(name,MAX_NAME,stdin);
            name[strcspn(name,"\n")]='\0';
            edit(*head,name);
            break;
        case 0:
            write_to_file(*head,"artefakty.txt");
            break;
        default:
            printf("Niepoprawny wybor!\n");
        }
    } while (choice != 0);
}