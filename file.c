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
    int line_num=0;

    while (fgets(line,sizeof(line),f)){
        line_num++;

        Artifact a;
        char *token;
        int field = 0;

        token = strtok(line, "|");//rozdziela ciąg na slowa| wywolanie zwraca wskażnik do następnego slowa
        while (token) {
            switch (field) {
                case 0: strncpy(a.name, token, MAX_NAME); break;
                case 1: strncpy(a.origin, token, MAX_TXT); break;
                case 2: strncpy(a.creator, token, MAX_TXT); break;
                case 3: a.danger_lvl = atoi(token); break;
                case 4: a.disc_year = atoi(token); break;
                case 5: a.status = atoi(token); break;
            }
            field++;
            token = strtok(NULL, "|");
        }
        if (field != 6) {
            printf("Blad formatu w linii %d\n", line_num);
            continue;
        }

        head = add(head, a);
    }
        
    fclose(f);
    return head;
}