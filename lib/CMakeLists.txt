set(alpm_SRCS
  add.c alpm.c alpm_list.c
  backup.c base64.c be_local.c be_package.c be_sync.c
  conflict.c
  db.c deps.c diskspace.c dload.c
  error.c
  filelist.c
  graph.c group.c
  handle.c hook.c
  ini.c
  log.c
  package.c pkghash.c
  rawstr.c remove.c
  signing.c sync.c
  trans.c
  util.c util-common.c
  version.c
)

target_sources(alpm PRIVATE ${alpm_SRCS})
set_target_properties(alpm
  PROPERTIES
  C_VISIBILITY_PRESET hidden
)
