QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    bishopmodel.cpp \
    button.cpp \
    chessboard.cpp \
    chessbox.cpp \
    chesspiece.cpp \
    chesspiecemodel.cpp \
    game.cpp \
    king.cpp \
    kingmodel.cpp \
    knight.cpp \
    knightmodel.cpp \
    main.cpp \
    pawn.cpp \
    pawnmodel.cpp \
    queen.cpp \
    queenmodel.cpp \
    rook.cpp \
    rookmodel.cpp

HEADERS += \
    bishop.h \
    bishopmodel.h \
    button.h \
    chessboard.h \
    chessbox.h \
    chesspiece.h \
    chesspiecemodel.h \
    game.h \
    king.h \
    kingmodel.h \
    knight.h \
    knightmodel.h \
    pawn.h \
    pawnmodel.h \
    queen.h \
    queenmodel.h \
    rook.h \
    rookmodel.h \
    side.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    images.qrc
