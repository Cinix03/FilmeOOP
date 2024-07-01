cmake_minimum_required(VERSION 3.27)
project(Lab6OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@5")
find_package(Qt5Widgets REQUIRED)

add_executable(Lab6OOP main.cpp
        Cos.cpp
        Cos.h
        Film.cpp
        Film.h
        Tests/teste.cpp
        Tests/teste.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        Ui.cpp
        Ui.h
        MyVector.cpp
        vector.h
        Validator.cpp
        Validator.h
        Errors.h
        ClasaNoua.cpp
        ActiuneUndo.h
        ActiuneUndo.cpp
        FilmeGUI.h
        FilmeGUI.cpp
        CosGUI.h
        CosGUI.cpp
        Login.h
        Login.cpp
        UserModeGui.h
        UserModeGui.cpp
        CosReadOnly.h
        Observer.h
        ClasaProprieLista.h
        ClasaProprieLista.cpp
        TableModel.h
        TableModel.cpp)

target_link_libraries(Lab6OOP Qt5::Widgets)