
//
// main.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <stdio.h>
#include <sophia/sp.h>
#include "commander/commander.h"
#include "batchput.h"

#define SPHIA_BATCHPUT_VERSION "0.0.1"

static void *env;
static void *db;
static char path[256];

static void
set_path(command_t *self) {
  strcpy(path, self->arg);
}

static int
batchput_init() {
  env = sp_env();
  int rc;
  if (NULL == env) return 1;

  rc = sp_ctl(env, SPDIR, SPO_CREAT|SPO_RDWR, path);
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

  db = sp_open(env);
  if (NULL == db) {
    fprintf(stderr, "%s\n", sp_error(env));
    sp_destroy(env);
    return 1;
  }

  return 0;
}

int
main(int argc, char *argv[]) {
  command_t program;
  command_init(&program
    , "sphia-batchput"
    , SPHIA_BATCHPUT_VERSION);
  command_option(&program
    , "-p"
    , "--path <path>"
    , "path to database"
    , set_path);
  command_parse(&program, argc, argv);

  if (0 != program.argc % 2) {
    fprintf(stderr, "Invalid number of key/value paris\n");
    command_free(&program);
    return 1;
  }

  if (0 == strlen(path)) {
    char *default_path = getenv("SPHIA_PATH");
    if (NULL != default_path) {
      // support for `$ SPHIA_PATH=foo sphia batchput foo bar`
      strcpy(path, default_path);
    } else {
      // default to pwd
      strcpy(path, ".");
    }
  }

  int rc;
  if (0 != (rc = batchput_init())) {
    command_free(&program);
    return 1;
  }

  rc = sphia_batchput(db, program.argc, program.argv);

  command_free(&program);
  sp_destroy(db);
  sp_destroy(env);

  return -1 == rc
    ? 1
    : 0;
}
