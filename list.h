#ifndef LIST_H
#define LIST_H

#include "artifact.h"
#include <stdio.h>

typedef struct Node{
    Artifact artifact;
    struct  Node *next; 
}Node;

Node* add(Node *head,Artifact new_a);
Node* delete_a(Node *head,const char *name);
    // if (artifact.danger_lvl>=8){
    //     printf("Odmowa wykonania polecenia!\n");
    //     return head;

Node* find(Node *head,const char *name);

void display(Node *head);
void freelist(Node *head);

Node* sort_by_name(Node *head);
Node* sort_by_danger(Node *head);

#endif