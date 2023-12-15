#include <JsonDb.h>

void JsonParseArray(const char *jsonString, char ***keys, char ***values, int *count)
{
  char *token = strtok((char *)jsonString, "[],{}\":");

  *count = 0;

  while (token != NULL)
  {
    if (strlen(token) > 0 && token[0] != ' ' && token[0] != '\t' && token[0] != '\n')
    {
      if (*count % 2 == 0)
      {
        *keys = realloc(*keys, ((*count / 2) + 1) * sizeof(char *));
        (*keys)[*count / 2] = strdup(token);
      }
      else
      {
        *values = realloc(*values, ((*count / 2) + 1) * sizeof(char *));
        (*values)[*count / 2] = strdup(token);
      }

      (*count)++;
    }

    token = strtok(NULL, "[],{}\":");
  }
}

char *readJson(char *path)
{
  FILE *file;
  char *jsonData;
  long length;

  file = fopen(path, "r");

  if (file == NULL)
  {
    printf("Error: File not found!");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);

  jsonData = (char *)malloc(length + 1);

  if (jsonData == NULL)
  {
    printf("Error: Memory allocation failed!");
    exit(1);
  }

  fread(jsonData, 1, length, file);

  jsonData[length] = '\0';

  fclose(file);

  return jsonData;
}
