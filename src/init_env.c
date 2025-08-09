#include <stdio.h>
#include "common.h"
#include "init_env.h"

int init_run() {
  fprintf(stderr, "init variables for runnning\n");

  return RET_OK;
}

int start_thread() {
  fprintf(stderr, "run thread each engines\n");

  return RET_OK;
}
