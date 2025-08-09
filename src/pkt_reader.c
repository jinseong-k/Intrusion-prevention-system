#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "common.h"
#include "pkt_reader.h"

int move_file(char *src_file, char *dst_dir) {
  FILE *src_fp, *dst_fp;
  src_fp = fopen(src_file, "r");
  dst_fp = fopen(dst_dir, "w+");

  if (!src_fp || !dst_fp) {
    fprintf(stderr, "[%s:%d] file open fail\n", __func__, __LINE__);
    return RET_FAIL;
  }

  // TODO file move.
  return RET_OK;
}

int read_file(char *file_name) {
  fprintf(stderr, "FILE_NAME : [%s]\n", file_name);

  // TODO read file, enqueue to pkt decoder thread

  return 1;
}

void *run_pkt_read(void *arg) {
  DIR *dir;
  struct dirent *dp;
  char file_name[MAX_FILE_NAME];
  while (1) {
#define READ_PKT_DIR "test_pkt"
    dir = opendir(READ_PKT_DIR);
    if (!dir) {
      fprintf(stderr, "Not found Packet directory [%s]. Please check...\n",
          READ_PKT_DIR);
      sleep(1);
      continue;
    }

    while ((dp = readdir(dir))) {
      if ((dp->d_namlen == 1 && !strncmp(".", dp->d_name, 1)) ||
          (dp->d_namlen == 2 && !strncmp("..", dp->d_name, 2))) {
        continue;
      }

      snprintf(file_name, MAX_FILE_NAME, "%s/%s", READ_PKT_DIR, dp->d_name);
      read_file(file_name);
    }

    sleep(1);
  }
  return NULL;
}
