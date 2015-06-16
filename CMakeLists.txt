cmake_minimum_required(VERSION 2.6)

cmake_policy(SET CMP0015 NEW)                

#Déclaration du projet

project(TRPEX)

# Set CMake modules search path
set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

message (${CMAKE_MODULE_PATH})

FIND_PACKAGE(OPENAL)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if (OPENAL_FOUND)
	include_directories(${OPENAL_INCLUDE_DIR})
endif (OPENAL_FOUND)


#Génération de la liste des fichiers sources

file(

        GLOB_RECURSE

        source_files

        Src/*

)



#Déclaration de l'exécutable

add_executable(trpx ${source_files})


if (OPENAL_FOUND)	
	message ("coucou2")
	target_link_libraries (trpx ${OPENAL_LIBRARY})
endif (OPENAL_FOUND)
