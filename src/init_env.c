#include <stdio.h>
#include "common.h"
#include "init_env.h"
#include "thr_manager.h"

int init_ips(ctx_t *ctx_arg) {
  fprintf(stderr, "init variables for runnning\n");

  ctx_arg->pkt_read_q = create_queue(MAX_PKT_SIZE, PKT_READ_QSIZE);
  if (ctx_arg->pkt_read_q == NULL) {
    fprintf(stderr, "[%s:%d] Fail to create queue\n",
        __func__, __LINE__);
    return RET_FAIL;
  }

  return RET_OK;
}

int start_thread() {
  fprintf(stderr, "run thread each engines\n");
  init_thread();

  return RET_OK;
}

int destroy_ips(ctx_t *ctx_arg) {
  if (ctx_arg->pkt_read_q) {
    destroy_queue(ctx_arg->pkt_read_q);
  }

  return RET_OK;
}
