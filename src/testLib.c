#include <JsonDb.h>

int main()
{
  char *jsonString = readJson("C:/Users/KeenanTOBIANSKY/Documents/jsonDb/src/data.json");

  char **keys = NULL;
  char **values = NULL;
  int count = 0;

  JsonParseArray(jsonString, &keys, &values, &count);

  for (int i = 0; i < count / 2; ++i)
  {
    printf("Key: %s, Value: %s\n", keys[i], values[i]);
  }

  for (int i = 0; i < count / 2; ++i)
  {
    free(keys[i]);
    free(values[i]);
  }

  free(keys);
  free(values);

  return 0;
}
