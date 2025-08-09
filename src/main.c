#include <stdio.h>
#include "init_env.h"
#include "common.h"

int main() {
  init_run();

  start_thread();

  return RET_OK;
}

