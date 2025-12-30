#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* add(Node *head,Artifact new_a){
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

Node* find_a(Node *head,const char *name){
    if (head!=NULL){
        Node *tmp=head;
        while (tmp!=NULL){
            if(tmp->artifact.name != NULL && stricmp(tmp->artifact.name,name)==0){
                printf("Znaleziono!\n");
                return tmp;
            }
            tmp=tmp->next;
        }
        printf("Nie znaleziono.\n");
    }else{
        printf("Lista jest pusta!\n");
    }
}

void display(Node *head){
    Node *tmp=head;
    while (tmp!=NULL){
        printf("Nazwa: %s|Pochodzenie: %s|Cywilizacja: %s|\nPoziom zagrozenia: %d|Rok odkrycia: %d|Status: %s\n",
            tmp->artifact.name,
            tmp->artifact.origin,
            tmp->artifact.creator,
            tmp->artifact.danger_lvl,
            tmp->artifact.disc_year,
            status_to_string(tmp->artifact.status));

        tmp=tmp->next;
    }
    
}
void freelist(Node *head){
    while (head!=NULL){
        Node *tmp=head;
        head=head->next;
        free(tmp);
    }
    
}

Node* sort_by_name(Node *head){
    if (head==NULL) return head;
    int swapped;
    Node *ptr;
    Artifact temp;

    do {
        swapped=0;
        ptr=head;

        while (ptr->next != NULL){
            if (strcmp(ptr->artifact.name,ptr->next->artifact.name)>0){
                temp=ptr->artifact;
                ptr->artifact=ptr->next->artifact;
                ptr->next->artifact=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
    }while (swapped);
    return head;
}
Node* sort_by_danger(Node *head){
        if (head==NULL) return head;
    int swapped;
    Node *ptr;
    Artifact temp;

    do {
        swapped=0;
        ptr=head;

        while (ptr->next != NULL){
            if (ptr->artifact.danger_lvl>ptr->next->artifact.danger_lvl){
                temp=ptr->artifact;
                ptr->artifact=ptr->next->artifact;
                ptr->next->artifact=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
    }while (swapped);
    return head;
}
