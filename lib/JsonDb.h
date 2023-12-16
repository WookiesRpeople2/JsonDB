#ifndef JSONDB_H
#define JSONDB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct KeyValuePair
 * @brief reprensets a key valeue pair found in a json object, {key: value}
 * @param *key Pointer to the key value in the json obj
 * @param *value Pointer to the value obj in the json obj
 */
typedef struct
{
  char *key;
  char *value;
} KeyValuePair;

/**
 * @struct JSONObject
 * @brief reprensets a json object
 * @param size Int to know the current size of the object
 * @param *pairs KeyValuePair to get the key and value
 */
typedef struct
{
  int size;
  KeyValuePair *pairs;
} JSONObject;

/**
 * @brief reads json from a file
 * @param *path the path to the .json file
 */
char *readJson(char *path);

/**
 * @brief function that free the jsonObject from memory
 * @param *obj JsonObject that will be freed
 */
void freeJSONObject(JSONObject *obj);

/**
 * @brief parses a jsonString into a json object
 * @param *json The json data that will be passed
 */
JSONObject parseJSON(const char *json);

#endif
