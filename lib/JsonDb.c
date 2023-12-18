#include <JsonDb.h>

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

void freeJSONObject(JSONObject *obj)
{
  for (int i = 0; i < obj->size; i++)
  {
    free(obj->pairs[i].key);
    free(obj->pairs[i].value);
  }
  free(obj->pairs);
}

JSONObject parseJSON(const char *json)
{
  JSONObject result;
  result.size = 0;
  result.pairs = NULL;
  char *delemiter = "{}\":, \t\n\r[]";

  const char *token = strtok((char *)json, delemiter);

  while (token != NULL)
  {
    KeyValuePair pair;
    pair.key = strdup(token);

    token = strtok(NULL, delemiter);

    if (token == NULL)
    {
      fprintf(stderr, "Error: Malformed JSON\n");
      freeJSONObject(&result);
      return result;
    }

    pair.value = strdup(token);

    result.size++;
    result.pairs = realloc(result.pairs, result.size * sizeof(KeyValuePair));
    result.pairs[result.size - 1] = pair;

    token = strtok(NULL, delemiter);
  }

  return result;
}

PGconn *connectDb(const char *connectionInfo)
{
  PGconn *connection = PQconnectdb(connectionInfo);
  if (PQstatus(connection) != CONNECTION_OK)
  {
    fprintf(stderr, "Error occured while connectiong to Postgreql database: %s\n", PQerrorMessage(connection));
    PQfinish(connection);
    exit(1);
  }

  printf("connected to database yayyy");
  return connection;
}
