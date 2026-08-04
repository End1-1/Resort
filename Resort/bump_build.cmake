# Increments the 4th version component in rc.h on every build.
# Usage: cmake -DRC_FILE=.../rc.h -P bump_build.cmake
#
# NOTE: Do not put "\0" literally in CMake strings — it becomes a NUL and
# corrupts the file (CMake uses C strings internally).

if(NOT RC_FILE)
    message(FATAL_ERROR "RC_FILE is not set")
endif()
if(NOT EXISTS "${RC_FILE}")
    message(FATAL_ERROR "rc.h not found: ${RC_FILE}")
endif()

file(READ "${RC_FILE}" content)

if(NOT content MATCHES "#define[ \t]+_PRODUCT_VERSION[ \t]+([0-9]+)[ \t]*,[ \t]*([0-9]+)[ \t]*,[ \t]*([0-9]+)[ \t]*,[ \t]*([0-9]+)")
    message(FATAL_ERROR "Cannot parse _PRODUCT_VERSION in ${RC_FILE}")
endif()

set(MAJOR "${CMAKE_MATCH_1}")
set(MINOR "${CMAKE_MATCH_2}")
set(PATCH "${CMAKE_MATCH_3}")
set(BUILD "${CMAKE_MATCH_4}")
math(EXPR BUILD "${BUILD} + 1")

# Build the two-character sequence backslash-zero without embedding NUL in CMake
string(ASCII 92 _BS)
set(_RC_NUL "${_BS}0")

file(WRITE "${RC_FILE}"
"#ifndef RC_H
#define RC_H

#define _PRODUCT_VERSION ${MAJOR}, ${MINOR}, ${PATCH}, ${BUILD}
#define _FILE_VERSION_STR \"${MAJOR}.${MINOR}.${PATCH}.${BUILD}${_RC_NUL}\"
#define _PRODUCT_VERSION_STR \"${MAJOR}.${MINOR}${_RC_NUL}\"

#endif // RC_H
")

message(STATUS "Version build number -> ${MAJOR}.${MINOR}.${PATCH}.${BUILD}")
