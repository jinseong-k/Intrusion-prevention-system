#ifndef __THR_MANAGER_HDR__
#define __THR_MANAGER_HDR__

#include <stdint.h>
#include <pthread.h>

#define MAX_THREAD_CNT 128

typedef struct _THREAD_MGR_ {
  pthread_t p[MAX_THREAD_CNT];
  uint32_t thread_cnt;
} THREAD_MGR;

void init_thread();

#endif  //__THR_MANAGER_HDR__
