#ifndef PLIK_H
#define PLIK_H

#include "list.h"

void write_to_file(Node *head,const char *file_name);
Node* load_from_file(const char *file_name);

#endif