#include <stdio.h>
#include <unistd.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#include "common.h"
#include "pkt_decoder.h"

extern ctx_t g_ctx;

static void print_mac(const unsigned char *m) {
    fprintf(stderr, "%02x:%02x:%02x:%02x:%02x:%02x\n",
           m[0], m[1], m[2], m[3], m[4], m[5]);
}

unsigned char *decode_eth(JS_PACKET *pkt, unsigned char *raw) {
  const struct ether_header *eth =
    (const struct ether_header *)raw;
  print_mac(eth->ether_shost);

  return raw;
}

unsigned char *decode_ip(JS_PACKET *pkt, unsigned char *raw) {
  return raw;
}

unsigned char *decode_tcp(JS_PACKET *pkt, unsigned char *raw) {
  return raw;
}

unsigned char *decode_udp(JS_PACKET *pkt, unsigned char *raw) {
  return raw;
}

void *run_pkt_decode(void *arg) {
  int empty_cnt = 0;
  unsigned char raw[MAX_PKT_SIZE] = {0, };
  unsigned char *next_raw;
  JS_PACKET pkt;

  ctx_t *ctx = &g_ctx;
  while (1) {
    if (QUEUE_OK != js_dequeue(ctx->pkt_read_q, (void *)raw)) {
      // TODO check fail count for control deq func.
      usleep(1000);
      continue;
    }
    next_raw = decode_eth(&pkt, raw);
    // TODO decode each layer.
  }
}
