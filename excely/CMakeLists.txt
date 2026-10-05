cmake_minimum_required(VERSION 3.21)

project(ExcelyPmsConnect LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

set(EXCELY_HEADERS
    include/excely/channel/bookingdto.h
    include/excely/channel/ibookingsource.h
    include/excely/channel/ibookingsink.h
    include/excely/resort/resortbookingdraft.h
    include/excely/resort/channeltoresort.h
    include/excely/pms/pmsconfig.h
    include/excely/pms/models.h
    include/excely/pms/soapenvelope.h
    include/excely/pms/pmsconnectclient.h
)

set(EXCELY_SOURCES
    src/channel/bookingdto.cpp
    src/resort/channeltoresort.cpp
    src/pms/pmsconfig.cpp
    src/pms/soapenvelope.cpp
    src/pms/models.cpp
    src/pms/xmlhelpers.cpp
    src/pms/pmsconnectclient.cpp
    src/pms/exelybookingsource.cpp
)

add_library(ExcelyPmsConnect STATIC
    ${EXCELY_HEADERS}
    ${EXCELY_SOURCES}
    include/excely/pms/exelybookingsource.h
    include/excely/pms/xmlhelpers.h
)

target_include_directories(ExcelyPmsConnect
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ExcelyPmsConnect
    PUBLIC
        Qt6::Core
        Qt6::Network
)

add_executable(pmsconnect_poller
    tools/pmsconnect_poller.cpp
)

target_link_libraries(pmsconnect_poller
    PRIVATE
        ExcelyPmsConnect
        Qt6::Core
        Qt6::Network
)

install(TARGETS ExcelyPmsConnect pmsconnect_poller
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
