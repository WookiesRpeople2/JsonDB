#ifndef JSONDB_H
#define JSONDB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void JsonParseArray(const char *jsonString, char ***keys, char ***values, int *count);
char *readJson(char *path);

#endif
