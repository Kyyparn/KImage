###ROOT###

cmake_minimum_required(VERSION 3.4)

#Set configuration types
SET(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

#Project name
project("KImage")

#Add subdirectory
add_subdirectory (src)

