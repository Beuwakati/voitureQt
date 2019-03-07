include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread


HEADERS += \
    test_testvoitureroule.h \
    tst_testvoitureconstructor.h

SOURCES += \
        main.cpp

include(../VoitureAppli/voiture.pri)
INCLUDEPATH += ../VoitureAppli
