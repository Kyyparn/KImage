###PROJECTSOURCE###

cmake_minimum_required(VERSION 3.4)

FILE(GLOB MY_SRCS "*.cpp")
FILE(GLOB MY_HDRS "*.h")

SET(MY_FILES ${MY_SRCS} ${MY_HDRS})

#Add folders in project

ADD_LIBRARY(GEI ${MY_FILES})