#include <JsonDb.h>

int main()
{
  const char *jsonString = readJson("src/data.json");
  JSONObject jsonObject = parseJSON(jsonString);

  for (int i = 0; i < jsonObject.size; ++i)
  {
    printf("Key: %s, Value: %s\n", jsonObject.pairs[i].key, jsonObject.pairs[i].value);
  }

  freeJSONObject(&jsonObject);

  return 0;
}
