# pacserver - Run pacman as server process

## Running

1. run with `pacserver <port>`, then it will listen at that port
2. the client send pacman's command line option via the socket
3. the server send log or confirm Y/N using the socket
4. the server process exit, connection is closed
