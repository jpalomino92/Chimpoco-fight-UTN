cmake_minimum_required(VERSION 3.29)
project(Chimpoco_fight_UTN)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chimpoco_fight_UTN
    attack.cpp
    attack.h
    aventura.cpp
    aventura.h
    batalla.cpp
    batalla.h
    chimpocos.cpp
    chimpocos.h
    constantes.h
    estadisticas.cpp
    estadisticas.h
    items.cpp
    items.h
    main.cpp
    pasivas.cpp
    pasivas.h
    visuales.cpp
    visuales.h
        versus.cpp
        versus.h
        random.cpp
        random.h
        dado.cpp)
