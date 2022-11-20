#include "protocol.h"

#include <string.h>
#include <unistd.h>

int connected_fd;

int send_yes_no(int socket, const char *msg, int yes) {
  char buf[strlen(msg) + 8];
  sprintf(buf, "[%d,\"%s\"]", PM_MSG_QUEST, msg); /* should be [4]\0 */
  write(socket, buf, strlen(buf));
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
  write(socket, buf, strlen(buf));
}

void send_progress(int socket, alpm_progress_t event, const char *pkg,
                   int percent, size_t howmany, size_t current) {
  int buflen = strlen(pkg) + 128;
  char buf[buflen];
  memset(buf, 0, buflen);
  sprintf(buf, "[%d,%d,\"%s\",%d,%zu,%zu]", PM_MSG_PROGRESS, event, pkg, percent, howmany, current);
  write(socket, buf, strlen(buf));
}

