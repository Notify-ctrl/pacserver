#ifndef PM_PROTOCOL_H
#define PM_PROTOCOL_H

#include "alpm_list.h"

typedef enum {
  PM_MSG_EVENT,
  PM_MSG_ERROR,
  PM_MSG_WARNING,
  PM_MSG_INFO,
  PM_MSG_QUEST,
  PM_MSG_PROGRESS,
} pm_message_type;

extern int connected_fd;

alpm_list_t *parse_packet(const char *packet);
int send_yes_no(int socket, const char *msg, int yes);
void send_log(int socket, pm_message_type type, const char *msg);
void send_progress();

#endif
