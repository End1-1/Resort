cmake_minimum_required(VERSION 3.21)

project(Resort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Unity Build ---
set(CMAKE_UNITY_BUILD ON)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# .ui files live in sibling dirs (../Controls, ../Filter, ...); AUTOUIC must search them
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Base
    ${CMAKE_CURRENT_SOURCE_DIR}/../Controls
    ${CMAKE_CURRENT_SOURCE_DIR}/../Filter
    ${CMAKE_CURRENT_SOURCE_DIR}/../GridOptionWidgets
    ${CMAKE_CURRENT_SOURCE_DIR}/../Print
    ${CMAKE_CURRENT_SOURCE_DIR}/../RoomChart
    ${CMAKE_CURRENT_SOURCE_DIR}/../RowEditor
    ${CMAKE_CURRENT_SOURCE_DIR}/../Widgets
)

# ---------- Qt ----------
find_package(Qt6 REQUIRED COMPONENTS
    Core Gui Widgets Network Sql PrintSupport WebSockets
)

qt_standard_project_setup()

# ---------- Sources (explicit list in sources.cmake) ----------
include(${CMAKE_CURRENT_SOURCE_DIR}/sources.cmake)

qt_add_executable(${PROJECT_NAME} WIN32
    ${PROJECT_SOURCES}
)

# Files that break unity (winsock2/OpenSSL order; out-of-tree .ui include)
set_source_files_properties(
    ${CMAKE_CURRENT_SOURCE_DIR}/printtaxno.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../Controls/efilterlineedit.cpp
    PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON
)

# ---------- Include paths ----------
target_include_directories(${PROJECT_NAME} PRIVATE
    ./
    ../Base ../Cache ../Cache2 ../Selector ../Controls ../RowEditor
    ../RoomChart ../Filter ../Print ../Widgets ../Threads
    ../RGDoubleClick ../GridOptionWidgets ../Vouchers ../Server2
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/include
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/Controls
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/Base
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/Filter
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/Print
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/RoomChart
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/RowEditor
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/Widgets
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/GridOptionWidgets
    C:/Development/OpenSSL-Win64/include
    C:/Development/OpenSSL-Win64/include/openssl
)

# ---------- Defines & Options ----------
target_compile_definitions(${PROJECT_NAME} PRIVATE
    _ORGANIZATION_="SmartHotel"
    _APPLICATION_="SmartHotel"
    _DBDRIVER_="QMYSQL"
    NOMINMAX # Важнейшая штука для Windows
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /wd4834 # Глушим "discarding return value"
        /utf-8  # Чтобы кириллица в коде не плыла
    )
endif()

# ---------- Libraries ----------
target_link_directories(${PROJECT_NAME} PRIVATE
    C:/Development/OpenSSL-Win64/lib/VC/x64/MD
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::Sql
    Qt6::PrintSupport Qt6::WebSockets
    Version
    libssl     # Заменил на libssl, так как в Shop у тебя было так
    libcrypto
    ws2_32     # Правильное имя для Winsock2
)

# Runtime assets next to the executable (debug/release)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/SmartHotelTouch.qss"
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/SmartHotelTouch.qss"
    COMMENT "Copy SmartHotelTouch.qss to output directory"
)

# Bump build number BEFORE compile/link.
# (PRE_BUILD is PRE_LINK on Ninja/Make — too late for res.rc.)
# Touch res.rc after bump: OBJECT_DEPENDS is ignored by Ninja, so without
# touching the .rc the VERSIONINFO stays at the previous build number.
# SKIP_RESORT_VERSION_BUMP=1 is checked at build time inside bump_build.cmake
# (setup/build.ps1 bumps once before packaging).
add_custom_target(bump_resort_version
    COMMAND ${CMAKE_COMMAND}
        -DRC_FILE=${CMAKE_CURRENT_SOURCE_DIR}/rc.h
        -P ${CMAKE_CURRENT_SOURCE_DIR}/bump_build.cmake
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_SOURCE_DIR}/res.rc
    COMMENT "Increment build number in rc.h"
)
add_dependencies(${PROJECT_NAME} bump_resort_version)

# ---------- Excely PMSConnect ----------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../excely excely_build)
target_link_libraries(${PROJECT_NAME} PRIVATE ExcelyPmsConnect)

# ---------- QXlsx ----------
set(CPACK_GENERATOR "" CACHE STRING "Disable CPack in QXlsx" FORCE)
add_subdirectory(C:/Development/projects/qxlsx qxlsx_build)
target_link_libraries(${PROJECT_NAME} PRIVATE QXlsx)
