
#include <stdio.h>
#include <string.h>
#include <sophia/sp.h>
#include "batchput.h"

/**
 * Set `count` key/value pairs as listed in
 * the given `batch`.
 */

int
sphia_batchput(void *db, int count, char **batch) {
  if (NULL == db || NULL == batch) return 1;

  for (int i = 0; i < count; i += 2) {
    char *key = strdup(batch[i]);
    if (NULL == key) return 1;

    char *value = strdup(batch[i + 1]);
    if (NULL == value) {
      free(key);
      return 1;
    }

    int rc = sp_set(db, key, strlen(key), value, strlen(value));
    if (-1 == rc) {
      fprintf(stderr
        , "An error occured setting key '%s': %s"
        , key
        , sp_error(db));
    }

    free(key);
    free(value);
    if (-1 == rc) return 1;
  }

  return 0;
}
