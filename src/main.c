#include <stdio.h>
#include "init_env.h"
#include "common.h"

#include "js_queue.h"

ctx_t g_ctx;

int main() {
  if (!init_ips(&g_ctx)) {
    fprintf(stderr, "Fail to init IPS Service\n");
    return RET_FAIL;
  }

  start_thread();

  destroy_ips(&g_ctx);

  return RET_OK;
}

