#ifndef VALIDATION_H
#define VALIDATION_H

#include "artifact.h"
#include "list.h"

int validate_name(const char *name,Node *head);
int validate_text(const char *txt);
int validate_danger(int lvl);
int validate_year(int year);
int validate_status(int status);

int validate_artifact(Artifact *a,Node *head);

#endif