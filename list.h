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
Node* find_a(Node *head,const char *name);

void find_by_origin_prefix(Node *head,const char *prefix);
void find_by_danger(Node *head,int min_lvl);

void display(Node *head);
void freelist(Node *head);

Node* sort_by_name(Node *head);
Node* sort_by_danger(Node *head);

int edit(Node *head,const char *name);

#endif