QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishopmodel.cpp \
    bishopview.cpp \
    button.cpp \
    chessboard.cpp \
    chessbox.cpp \
    chesspiecemodel.cpp \
    chesspieceview.cpp \
    game.cpp \
    kingmodel.cpp \
    kingview.cpp \
    knightmodel.cpp \
    knightview.cpp \
    main.cpp \
    pawnmodel.cpp \
    pawnview.cpp \
    queenmodel.cpp \
    queenview.cpp \
    rookmodel.cpp \
    rookview.cpp

HEADERS += \
    bishopmodel.h \
    bishopview.h \
    button.h \
    chessboard.h \
    chessbox.h \
    chesspiecemodel.h \
    chesspieceview.h \
    game.h \
    kingmodel.h \
    kingview.h \
    knightmodel.h \
    knightview.h \
    pawnmodel.h \
    pawnview.h \
    queenmodel.h \
    queenview.h \
    rookmodel.h \
    rookview.h \
    side.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    images.qrc
