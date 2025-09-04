#ifndef __COMMON_HDR_
#define __COMMON_HDR_

#include "js_queue.h"

#define RET_OK 1
#define RET_FAIL 0

#define MAX_FILE_NAME 256
#define MAX_PKT_SIZE 2048
#define PKT_READ_QSIZE 1024

typedef struct _CONTEXT_ {
  JS_QUEUE_t *pkt_read_q;
} ctx_t;

typedef struct _JS_PACKET_ {
  uint32_t len;
} JS_PACKET;

#endif  // __COMMON_HDR_
