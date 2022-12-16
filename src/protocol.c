#include "protocol.h"

#include <string.h>
#include <unistd.h>

int connected_fd;

// replace all '\n' to '\\n' in JSON string
// return a malloc'ed string, remember to free it
static char *json_replace(const char *str) {
  int len = strlen(str) * 2;
  int i = 0;
  char *ret = malloc(len);
  memset(ret, 0, len);
  for (; *str; str++) {
    if (*str == '\n') {
      ret[i++] = '\\';
      ret[i++] = 'n';
    } else {
      ret[i++] = *str;
    }
  }
  return ret;
}

int send_yes_no(int socket, const char *msg, int yes) {
  char buf[strlen(msg) + 8];
  sprintf(buf, "[%d,\"%s\"]", PM_MSG_QUEST, msg); /* should be [4]\0 */
  char *send = json_replace(buf);
  write(socket, send, strlen(send));
  free(send);
  memset(buf, 0, sizeof(buf));
  read(socket, buf, 1);
  if (*buf == 'y' || *buf == 'Y') {
    return 1;
  }
  return 0;
}

void send_log(int socket, pm_message_type type, const char *msg) {
  int buflen = strlen(msg) + 128;
  char buf[buflen];
  memset(buf, 0, buflen);
  sprintf(buf, "[%d,\"%s\"]", type, msg);
  char *send = json_replace(buf);
  write(socket, send, strlen(send));
  free(send);

  read(socket, buf, 1); // ACK
}

void send_progress(int socket, alpm_progress_t event, const char *pkg,
                   int percent, size_t howmany, size_t current) {
  int buflen = strlen(pkg) + 128;
  char buf[buflen];
  memset(buf, 0, buflen);
  sprintf(buf, "[%d,%d,\"%s\",%d,%zu,%zu]", PM_MSG_PROGRESS, event, pkg, percent, howmany, current);
  char *send = json_replace(buf);
  write(socket, send, strlen(send));
  free(send);

  read(socket, buf, 1); // ACK
}

