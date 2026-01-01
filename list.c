#include "list.h"
#include "validation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* add(Node *head,Artifact new_a){
    if(find_a(head,new_a.name)!=NULL){
        printf("Artefakt o nazwie %s juz istnieje!\n",new_a.name);
        return head;
    }
    Node *node = malloc(sizeof(Node));
    if (!node){
        printf("Błąd alokacji pamięci!\n");
        return head;
    }
    node ->artifact=new_a;
    node->next=NULL;
    
    if (head==NULL){
        return node;
    }

    Node *tmp=head;
    while (tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=node;
    return head;
    
}
Node* delete_a(Node *head, const char *name)
{
    if (head == NULL || name == NULL) {
        return head;
    }

    /* usuwanie pierwszego elementu */
    if (head->artifact.name != NULL &&
        stricmp(head->artifact.name, name) == 0)
    {
        if (head->artifact.danger_lvl >= 8) {
            printf("Odmowa usuniecia: artefakt zbyt niebezpieczny!\n");
            return head;
        }

        Node *next = head->next;
        free(head);
        return next;
    }

    /* szukanie dalej */
    Node *p = head;
    while (p->next != NULL) {
        if (p->next->artifact.name != NULL &&
            stricmp(p->next->artifact.name, name) == 0)
        {
            if (p->next->artifact.danger_lvl >= 8) {
                printf("Odmowa usuniecia: artefakt zbyt niebezpieczny!\n");
                return head;
            }

            Node *to_delete = p->next;
            p->next = to_delete->next;
            free(to_delete);
            return head;
        }
        p = p->next;
    }

    printf("Nie znaleziono artefaktu o nazwie: %s\n", name);
    return head;
}
    // if (artifact.danger_lvl>=8){
    //     printf("Odmowa wykonania polecenia!\n");
    //     return head;

Node* find_a(Node *head, const char *name){
    while (head != NULL) {
        if (strcmp(head->artifact.name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void display(Node *head){
    Node *tmp=head;
    while (tmp!=NULL){
        printf("\nNazwa: %s\nPochodzenie: %s\nCywilizacja: %s\nPoziom zagrozenia: %d\nRok odkrycia: %d\nStatus: %s\n",
            tmp->artifact.name,
            tmp->artifact.origin,
            tmp->artifact.creator,
            tmp->artifact.danger_lvl,
            tmp->artifact.disc_year,
            status_to_string(tmp->artifact.status));

        tmp=tmp->next;
    }
}

void display_single(Node *node){
    printf("\nNazwa: %s\nPochodzenie: %s\nCywilizacja: %s\nPoziom zagrozenia: %d\nRok odkrycia: %d\nStatus: %s\n",
            node->artifact.name,
            node->artifact.origin,
            node->artifact.creator,
            node->artifact.danger_lvl,
            node->artifact.disc_year,
            status_to_string(node->artifact.status));
}
    
void freelist(Node *head){
    while (head!=NULL){
        Node *tmp=head;
        head=head->next;
        free(tmp);
    }
    
}

Node* sort_by_name(Node *head){
    if (!head) return head;

    for (Node *i = head; i->next != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (stricmp(i->artifact.name, j->artifact.name) > 0) {
                Artifact tmp = i->artifact;
                i->artifact = j->artifact;
                j->artifact = tmp;
            }
        }
    }
    return head;
}
Node* sort_by_danger(Node *head){
    if (!head) return head;

    for (Node *i = head; i->next != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->artifact.danger_lvl > j->artifact.danger_lvl) {
                Artifact tmp = i->artifact;
                i->artifact = j->artifact;
                j->artifact = tmp;
            }
        }
    }
    return head;
}

int edit(Node *head,const char *name){
    Node *node=find_a(head,name);
    if (!node){
        printf("Nie znaleziono artefaktu o nazwie %s\n",name);
        return 0;
    }
    Artifact *a=&node->artifact;
    printf("Edycja artefaktu: %s\n",a->name);
    printf("Aby anulowac wcisnij Enter\n");

    char buffer[MAX_TXT];

    printf("Nowe pochodzenie [%s]:",a->origin);
    fgets(buffer,MAX_TXT,stdin);
    buffer[strcspn(buffer,"\n")]='\0';
    if (strlen(buffer)>0){
        strcpy(a->origin,buffer);
    }

    printf("Nowa cywilizacja [%s]:",a->creator);
    fgets(buffer,MAX_TXT,stdin);
    buffer[strcspn(buffer,"\n")]='\0';
    if (strlen(buffer)>0){
        strcpy(a->creator,buffer);
    }

    int lvl;
    do{
        printf("Nowy poziom zagrozenia [%d]:",a->danger_lvl);
        fgets(buffer,MAX_TXT,stdin);
        
        if (buffer[0]=='\n'){//brak zmiany
            break;
        }
        lvl=atoi(buffer);
    }while(!validate_danger(lvl));
    if (buffer[0]!='\n'){
        a->danger_lvl=lvl;
    }


    int year;
    do{
        printf("Nowy rok odkrycia [%d]:",a->disc_year);
        fgets(buffer,MAX_TXT,stdin);
        if(buffer[0]=='\n'){
            break;
        }
        year=atoi(buffer);
        }while(!validate_year(year));
        if(buffer[0]!='\n'){
            a->disc_year=year;
        }


    int st;
    do{    
        printf("Nowy status [%d]: ", a->status);
        printf("0-bezpieczny, 1-niestabilny, 2-zakazany, 3-kwarantanna, 4-badania\n");
        fgets(buffer, MAX_TXT, stdin);
        if(buffer[0]=='\n'){
            break;
        }
        st=atoi(buffer);
        }while(!validate_status(st));
        if(buffer[0]!='\n'){
            a->status=st;
        }
    

    printf("Artefakt %s zaktualizowany!\n",name);
    return 1;

}

void find_by_origin_prefix(Node *head,const char *prefix){
    int found=0;

    while(head!=NULL){
        if(strncmp(head->artifact.origin,prefix,strlen(prefix))==0){
            display_single(head);
            found=1;
        }
        head=head->next;
    }
    if(!found){
        printf("Brak artefaktów spelniajacych kryterium!\n");
    }
}

void find_by_danger(Node *head,int min_lvl){
    int found=0;

    while(head!=NULL){
        if(head->artifact.danger_lvl>=min_lvl){
            display_single(head);
            found=1;
        }
        head=head->next;
    }
    if(!found){
        printf("Brak artefaktów spelniajacych kryterium!\n");
    }
}
