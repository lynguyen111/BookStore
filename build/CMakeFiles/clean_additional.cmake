# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/convert_legacy_bin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/convert_legacy_bin_autogen.dir/ParseCache.txt"
  "CMakeFiles/pbl2_book_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pbl2_book_autogen.dir/ParseCache.txt"
  "convert_legacy_bin_autogen"
  "pbl2_book_autogen"
  )
endif()
