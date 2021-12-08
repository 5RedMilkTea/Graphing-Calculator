TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.5.1\lib"
//LIBS += -L"..\..\..\SFML-2.5.1\lib" #change this
LIBS += -L"..\SFML-2.5.1\bin"
//LIBS += -L"..\..\..\SFML-2.5.1\bin" #change this


CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.5.1\include" #change this
DEPENDPATH  += "..\SFML-2.5.1\include" #change this



SOURCES += \
        main.cpp \
    animation.cpp \
    token.cpp \
    numbers.cpp \
    operators.cpp \
    variables.cpp \
    rpn.cpp \
    shunting_yard.cpp \
    tokenizer.cpp \
    lparenthesis.cpp \
    rparenthesis.cpp \
    trigfunctions.cpp \
    plot.cpp \
    graph.cpp \
    system.cpp \
    sidebar.cpp \
    test_functions.cpp \
    textbox.cpp \
    negative.cpp \
    button.cpp

HEADERS += \
    animation.h \
    token.h \
    numbers.h \
    operators.h \
    variables.h \
    rpn.h \
    ../../Stack and Queue/IteratedStack/stack/stack.h \
    ../../Stack and Queue/IteratedQueue/queue/queue.h \
    shunting_yard.h \
    tokenizer.h \
    lparenthesis.h \
    rparenthesis.h \
    trigfunctions.h \
    plot.h \
    graph_info.h \
    graph.h \
    system.h \
    sidebar.h \
    constants.h \
    test_functions.h \
    textbox.h \
    negative.h \
    button.h \
    z_workreport.h
