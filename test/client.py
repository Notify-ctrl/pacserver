#!/usr/bin/python3

from socket import *
import json

PM_MSG_EVENT = 0
PM_MSG_ERROR = 1
PM_MSG_WARNING = 2
PM_MSG_INFO = 3
PM_MSG_QUEST = 4
PM_MSG_PROGRESS = 5,

def handle_msg(client, data):
  type = data[0]
  if type == PM_MSG_QUEST:
    client.send(b'n')
  else:
    pass

def main():
  client = socket(AF_INET, SOCK_STREAM)
  client.connect(("127.0.0.1", 5000))
  client.sendall("-S base".encode('utf-8'))

  while True:
    recv_data = client.recv(1024)
    if recv_data == b'':
      return

    print("RX:", recv_data.decode('utf-8'))
    #data = json.loads(recv_data)
    #handle_msg(client, data)

main()

