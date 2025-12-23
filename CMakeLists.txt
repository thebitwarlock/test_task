cmake_minimum_required(VERSION 3.10)
project(TestTask)

# Указать путь к заголовочным файлам
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Создать исполняемый файл из исходников
add_executable(test_task src/main.cpp)

# Установите стандарт и ВКЛЮЧИТЕ отладочную информацию
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # Ключевая строка: -g

# Новый исполняемый файл для echo-сервера
add_executable(echo_server src/echo_server.cpp)
# Для cpp-httplib может потребоваться библиотека pthread
target_link_libraries(echo_server PUBLIC pthread)