#include <stdio.h>
#include "common.h"
#include "init_env.h"
#include "thr_manager.h"

int init_ips() {
  fprintf(stderr, "init variables for runnning\n");

  return RET_OK;
}

int start_thread() {
  fprintf(stderr, "run thread each engines\n");
  init_thread();

  return RET_OK;
}
