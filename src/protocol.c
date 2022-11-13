#include <unistd.h>
#include <string.h>

#include "protocol.h"

int connected_fd;

static char *msg_types[] = {
  "EVENT",
  "ERROR",
  "WARNING",
  "INFO",
  "QUEST",
  "PROGRESS",
};

void send_log(int socket, pm_message_type type, const char *msg) {
  write(socket, msg, strlen(msg));
  write(socket, msg_types[type], strlen(msg_types[type]));
}
