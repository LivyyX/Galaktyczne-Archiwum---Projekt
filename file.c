#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_to_file(Node *head,const char *filename){
    FILE *f=fopen(filename,"w");
    if (!f){
        printf("Nie można otworzyć pliku do zapisu!\n");
        return;
    }
    Node *tmp = head;
    while (tmp!=NULL){
        fprintf(
            f,
            "%s|%s|%s|%d|%d|%d\n",
            tmp->artifact.name,
            tmp->artifact.origin,
            tmp->artifact.creator,
            tmp->artifact.danger_lvl,
            tmp->artifact.disc_year,
            tmp->artifact.status
        );
        tmp=tmp->next;
    }
    fclose(f);
}

Node* load_from_file(const char *filename){
    FILE *f = fopen(filename,"r");
    if (!f){
        printf("Nie można otworzyć pliku do odczytu!\n");
        return NULL;
    }
    Node *head =NULL;
    Artifact a;
    char line[512];

    while (fgets(line,sizeof(line),f)){
        line[strcspn(line,"\n")]='\0';

        char *token = strtok(line,"|");
        if(!token) continue;
        strncpy(a.name,token,MAX_NAME);

        token=strtok(NULL,"|");
        if (!token) continue;
        strncpy(a.origin,token,MAX_TXT);

        token=strtok(NULL,"|");
        if (!token) continue;
        strncpy(a.creator,token,MAX_TXT);

        token=strtok(NULL,"|");
        if (!token) continue;
        a.danger_lvl=atoi(token);

        token=strtok(NULL,"|");
        if (!token) continue;
        a.disc_year=atoi(token);

        token=strtok(NULL,"|");
        if (!token) continue;
        a.status=(Status)atoi(token);

        head=add(head,a);
        
    }
    fclose(f);
    return head;
}