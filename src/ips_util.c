#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "ips_util.h"
#include "common.h"

int find_ext_name(char *name, char *target_ext, int ext_len) {
  char *pos = NULL;
  char *ext = NULL;
  int len = 0;
  if ((pos = strchr(name, '.'))) { 
    pos++;
    len = strlen(pos);
    if (len <= 0) {
      return RET_FAIL;
    }
    if (len == ext_len) {
      if (strnstr(pos, target_ext, len)) {
        return RET_OK;
      }
    }
  }
  return RET_FAIL;
}
