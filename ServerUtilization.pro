TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    ServerUtilizationApp \
    UtilizationLib \
    TestLoadGen

ServerUtilizationApp.depends = TestLoadGen
