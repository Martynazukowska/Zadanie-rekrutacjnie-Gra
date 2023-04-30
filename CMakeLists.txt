# Wymagana minimalna wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu i język programowania
project(myproject CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

# Dodanie źródeł programu i utworzenie pliku wykonywalnego
add_executable(myprogram scr/main.cpp)

# Dodanie źródeł programu gracz1 i mapa
add_executable(gracz1 scr/Gracz1.cpp scr/mapa.cpp scr/status.cpp scr/jednostka.cpp)
target_include_directories(gracz1 PRIVATE scr) # Dodanie katalogu scr do include


