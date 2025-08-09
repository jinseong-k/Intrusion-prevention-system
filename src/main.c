#include <stdio.h>
#include "init_env.h"
#include "common.h"

int main() {
  init_ips();

  start_thread();

  return RET_OK;
}

