# KImage/test

cmake_minimum_required(VERSION 3.4)

PROJECT(KImage_tests)

FILE(GLOB SRCS "*.cpp")
FILE(GLOB HDRS "*.h")

SET(MY_FILES ${SRCS} ${HDRS})

SOURCE_GROUP("Source" FILES ${MY_FILES})

ADD_EXECUTABLE(KImage_tests ${MY_FILES})

TARGET_LINK_LIBRARIES(KImage_tests PRIVATE KImage)