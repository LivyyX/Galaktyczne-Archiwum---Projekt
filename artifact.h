#ifndef ARTIFACT_H
#define ARTIFACT_H

#define MAX_NAME 100
#define MAX_TXT 100

typedef enum{
    BEZPIECZNY,
    NIESTABILNY,
    ZAKAZANY,
    WYMAGA_KWARANTANNY,
    W_TRAKCIE_BADAN,
}Status;

typedef struct {
    char name[MAX_NAME+1];
    char origin[MAX_TXT];
    char creator[MAX_TXT];
    int danger_lvl;
    int disc_year;
    Status status;
} Artifact;

const char* status_to_string(Status s);


#endif