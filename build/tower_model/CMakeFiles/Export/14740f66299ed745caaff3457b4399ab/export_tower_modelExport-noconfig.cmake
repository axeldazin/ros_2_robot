#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tower_model::tower_model" for configuration ""
set_property(TARGET tower_model::tower_model APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tower_model::tower_model PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtower_model.so"
  IMPORTED_SONAME_NOCONFIG "libtower_model.so"
  )

list(APPEND _cmake_import_check_targets tower_model::tower_model )
list(APPEND _cmake_import_check_files_for_tower_model::tower_model "${_IMPORT_PREFIX}/lib/libtower_model.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
