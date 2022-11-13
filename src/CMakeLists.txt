set(pacserver_SRCS
  callback.c check.c conf.c
  database.c deptest.c
  files.c
  ini.c
  package.c pacman-conf.c pacman.c protocol.c
  query.c
  remove.c
  sighandler.c sync.c
  upgrade.c util-common.c util.c
)

target_sources(pacserver PRIVATE ${pacserver_SRCS})
target_link_libraries(pacserver alpm archive curl crypto)
