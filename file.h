#ifndef PLIK_H
#define PLIK_H

#include "list.h"

void writetofile(Node *head,const char *file_name);
Node* readfile(const char *file_name);

#endif