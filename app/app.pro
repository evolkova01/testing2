TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += append_line.cpp \
    create_text.cpp \
    editor.cpp \
    j.cpp \
    load.cpp \
    m.cpp \
    mp.cpp \
    process_forward.cpp \
    remove_all.cpp \
    save.cpp \
    show.cpp \
    showodd.cpp

HEADERS += \
    _text.h \
    common.h \
    text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
