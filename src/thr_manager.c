#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "common.h"
#include "thr_manager.h"
#include "pkt_reader.h"

THREAD_MGR g_thr_mgr;

int run_thread(void *(run_f)(void *), char *name, void *arg) {
  THREAD_MGR *thr_mgr = &g_thr_mgr;
  if (thr_mgr->thread_cnt >= MAX_THREAD_CNT) {
    return RET_FAIL;
  }
  fprintf(stderr, "Thread [%s] start\n", name);
  pthread_create(&thr_mgr->p[thr_mgr->thread_cnt],
      NULL, run_f, arg);
  thr_mgr->thread_cnt++;

  return RET_OK;
}

void init_thread() {
  int arg = 1;
  int thr_idx;
  memset(&g_thr_mgr, 0x00, sizeof(g_thr_mgr));
  THREAD_MGR *thr_mgr = &g_thr_mgr;

  run_thread(run_pkt_read, "read thread", (void *)&arg);

  for (thr_idx=0; thr_idx<thr_mgr->thread_cnt; thr_idx++) {
    pthread_join(thr_mgr->p[thr_idx], NULL);
  }
}
