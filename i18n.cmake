# Setting up Intl
find_package (Intl REQUIRED)
find_package(Gettext REQUIRED)
include_directories(${INTL_INCLUDE_DIRS})
link_directories(${INTL_LIBRARY_DIRS})

find_program(MSGFMT_EXECUTABLE msgfmt)

function(generate_translation path GMO_FILES NAME)
  set(catalogname rkward)

  file(GLOB PO_FILES ${path})

  foreach(_poFile ${PO_FILES})
    get_filename_component(_poFileName ${_poFile} NAME)
    string(REGEX REPLACE "^${catalogname}_?" "" _langCode ${_poFileName} )
    string(REGEX REPLACE "\\.po$" "" _langCode ${_langCode} )

    if( _langCode )
      get_filename_component(_lang ${_poFile} NAME_WE)
      set(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/locale/${_lang}/LC_MESSAGES/${NAME}.mo)

      add_custom_command(OUTPUT ${_gmoFile}
        COMMAND ${MSGFMT_EXECUTABLE} -o ${_gmoFile} ${_poFile}
        DEPENDS ${_poFile}
      )

      list(APPEND GMO_FILES ${_gmoFile})
    endif()
  endforeach()
endfunction()


if(NOT MSGFMT_EXECUTABLE)
  message("NOTE: msgfmt not found. Translations will *not* be installed")
else()
  set(GMO_FILES)
  set(catalogname rkward)

  file(GLOB PO_FILES src/po/*.po)

  foreach(_poFile ${PO_FILES})
    get_filename_component(_poFileName ${_poFile} NAME)
    string(REGEX REPLACE "^${catalogname}_?" "" _langCode ${_poFileName} )
    string(REGEX REPLACE "\\.po$" "" _langCode ${_langCode} )

    if( _langCode )
      get_filename_component(_lang ${_poFile} NAME_WE)
      set(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/locale/${_lang}/LC_MESSAGES/pacman.mo)

      add_custom_command(OUTPUT ${_gmoFile}
        COMMAND ${MSGFMT_EXECUTABLE} -o ${_gmoFile} ${_poFile}
        DEPENDS ${_poFile}
      )

      list(APPEND GMO_FILES ${_gmoFile})
    endif()
  endforeach()

  file(GLOB PO_FILES lib/po/*.po)

  foreach(_poFile ${PO_FILES})
    get_filename_component(_poFileName ${_poFile} NAME)
    string(REGEX REPLACE "^${catalogname}_?" "" _langCode ${_poFileName} )
    string(REGEX REPLACE "\\.po$" "" _langCode ${_langCode} )

    if( _langCode )
      get_filename_component(_lang ${_poFile} NAME_WE)
      set(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/locale/${_lang}/LC_MESSAGES/libalpm.mo)

      add_custom_command(OUTPUT ${_gmoFile}
        COMMAND ${MSGFMT_EXECUTABLE} -o ${_gmoFile} ${_poFile}
        DEPENDS ${_poFile}
      )

      list(APPEND GMO_FILES ${_gmoFile})
    endif()
  endforeach()

  add_custom_target(translations ALL DEPENDS ${GMO_FILES})
ENDIF()
