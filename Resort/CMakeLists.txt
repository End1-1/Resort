cmake_minimum_required(VERSION 3.21)

project(Resort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Улучшайзинг: Включаем Unity Build ---
set(CMAKE_UNITY_BUILD OFF)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ---------- Qt ----------
find_package(Qt6 REQUIRED COMPONENTS
    Core Gui Widgets Network Sql PrintSupport WebSockets
)

qt_standard_project_setup()

# ---------- Sources ----------
# Оставляем GLOB, раз тебе так удобнее, но Unity Build нивелирует его минусы при сборке
file(GLOB_RECURSE PROJECT_SOURCES
    *.cpp *.h *.ui *.qrc
    ../Base/*.cpp ../Base/*.h ../Base/*.ui
    ../Cache/*.cpp ../Cache/*.h ../Cache/*.ui
    ../Cache2/*.cpp ../Cache2/*.h ../Cache2/*.ui
    ../Selector/*.cpp ../Selector/*.h ../Selector/*.ui
    ../Controls/*.cpp ../Controls/*.h ../Controls/*.ui
    ../RowEditor/*.cpp ../RowEditor/*.h ../RowEditor/*.ui
    ../RoomChart/*.cpp ../RoomChart/*.h ../RoomChart/*.ui
    ../Filter/*.cpp ../Filter/*.h ../Filter/*.ui
    ../Print/*.cpp ../Print/*.h ../Print/*.ui
    ../Widgets/*.cpp ../Widgets/*.h ../Widgets/*.ui
    ../Threads/*.cpp ../Threads/*.h ../Threads/*.ui
    ../RGDoubleClick/*.cpp ../RGDoubleClick/*.h ../RGDoubleClick/*.ui
    ../GridOptionWidgets/*.cpp ../GridOptionWidgets/*.h ../GridOptionWidgets/*.ui
    ../Vouchers/*.cpp ../Vouchers/*.h ../Vouchers/*.ui
    ../Server2/*.cpp ../Server2/*.h ../Server2/*.ui
    C:/Development/projects/desktop.newtax/Src/*.h
    C:/Development/projects/desktop.newtax/Src/*.cpp
)

qt_add_executable(${PROJECT_NAME} WIN32
    ${PROJECT_SOURCES}
)

# --- Исключаем проблемные файлы из склейки ---
# Добавляем сюда те, на которых OfficeN или Shop спотыкались
set_source_files_properties(
    "C:/Development/projects/desktop.newtax/Src/printtaxn.cpp"
    # Добавь сюда QRCodeGenerator.cpp, если он есть в этом проекте
    PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON
)

# ---------- Include paths ----------
target_include_directories(${PROJECT_NAME} PRIVATE
    ./
    ../Base ../Cache ../Cache2 ../Selector ../Controls ../RowEditor
    ../RoomChart ../Filter ../Print ../Widgets ../Threads
    ../RGDoubleClick ../GridOptionWidgets ../Vouchers ../Server2
    C:/Development/projects/desktop.newtax/Src
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

# ---------- QXlsx ----------
set(CPACK_GENERATOR "" CACHE STRING "Disable CPack in QXlsx" FORCE)
add_subdirectory(C:/Development/projects/qxlsx qxlsx_build)
target_link_libraries(${PROJECT_NAME} PRIVATE QXlsx)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "/P")
