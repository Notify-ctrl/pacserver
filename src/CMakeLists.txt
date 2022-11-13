set(pacserver_SRCS
  main.c
)

target_sources(pacserver PRIVATE ${pacserver_SRCS})
target_link_libraries(pacserver alpm archive curl crypto)
