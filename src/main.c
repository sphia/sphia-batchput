
#include <stdio.h>
#include <sophia/sophia.h>
#include <sophia/sp.h>

int main(int argc, char *argv[]) {
  void *env = sp_env();
  int rc;
  if (NULL == env) return 1;

  rc = sp_ctl(env, SPDIR, SPO_CREAT|SPO_RDWR, ".");
  if (-1 == rc) {
    fprintf(stderr, "Error creating or reading database\n");
    sp_destroy(env);
    return 1;
  }

  rc = sp_ctl(env, SPGC, 1);
  if (-1 == rc) {
    fprintf(stderr, "%s\n", sp_error(env));
    sp_destroy(env);
    return 1;
  }

  void *db = sp_open(env);
  if (NULL == db) {
    fprintf(stderr, "%s\n", sp_error(env));
    sp_destroy(env);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    if (0 == i % 2) {
      char *key = strdup(argv[i - 1]);
      char *value = strdup(argv[i]);
      rc = sp_set(db, key, strlen(key), value, strlen(value));
      if (-1 == rc) {
        fprintf(stderr
          , "An error occured setting key '%s'. %s"
          , key
          , sp_error(db));
        free(key);
        free(value);
        sp_destroy(db);
        sp_destroy(env);
        return 2;
      }
      free(key);
      free(value);
    }
  }

  sp_destroy(db);
  sp_destroy(env);
  return 0;
}
