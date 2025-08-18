#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#include "common.h"
#include "pkt_reader.h"
#include "ips_util.h"

int move_file(char *src_file, char *dst_dir) {
  FILE *src_fp, *dst_fp;
  char buffer[8192];
  size_t bytes;

  src_fp = fopen(src_file, "r");
  dst_fp = fopen(dst_dir, "w+");

  if (!src_fp || !dst_fp) {
    fprintf(stderr, "[%s:%d] file open fail\n", __func__, __LINE__);
    if (src_fp) {
      fclose(src_fp);
      fclose(dst_fp);
    }
    return RET_FAIL;
  }

  while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp))) {
    if (fwrite(buffer, 1, bytes, dst_fp) != bytes) {
      fclose(src_fp);
      fclose(dst_fp);
      return RET_FAIL;
    }
  }  // while fread

  fclose(src_fp);
  fclose(dst_fp);

  unlink(src_file);

  return RET_OK;
}

int process_packet(char *file_name) {
  fprintf(stderr, "FILE_NAME : [%s]\n", file_name);

  // TODO read file, enqueue pkt to decoder thread

  return 1;
}

#define READ_PKT_DIR "test_pkt"
#define POST_PKT_DIR "post_pkt"
void *run_pkt_read(void *arg) {
  DIR *dir;
  struct dirent *dp;
  char file_name[MAX_FILE_NAME];
  char post_file_path[MAX_FILE_NAME];
  uint32_t read_pkt_count = 0;

  while (1) {
    if (0 != access(READ_PKT_DIR, F_OK)) {
      fprintf(stderr, "Not found %s directory.\n", READ_PKT_DIR);
      sleep(1);
      continue;
    }

    if (0 != access(POST_PKT_DIR, F_OK)) {
      mkdir(POST_PKT_DIR, 0755);
    }

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
      read_pkt_count++;

      snprintf(file_name, MAX_FILE_NAME, "%s/%s", READ_PKT_DIR, dp->d_name);
      snprintf(post_file_path, MAX_FILE_NAME, "%s/%s", POST_PKT_DIR, dp->d_name);
      if (find_ext_name(file_name, "pcap", 4) ||
          find_ext_name(file_name, "cap", 3)) { 
        process_packet(file_name);
      }
      move_file(file_name, post_file_path);
    }  // while (readdir)

    if (read_pkt_count == 0) {
      fprintf(stderr, "No more packet files\n");
      sleep(1);
    } else {
      read_pkt_count = 0;
    }

    usleep(100);
  }  // while (1); whole loop
  return NULL;
}
