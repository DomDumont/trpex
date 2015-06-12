cmake_minimum_required(VERSION 2.6)

cmake_policy(SET CMP0015 NEW)                

#Déclaration du projet

project(TRPEX)


include_directories(Extern/OpenAL/include)
link_directories(Extern/OpenAL/libs/Win32/)

#Génération de la liste des fichiers sources

file(

        GLOB_RECURSE

        source_files

        src/*

)



#Déclaration de l'exécutable

add_executable(

        trpex

        ${source_files}

)


target_link_libraries(trpex OpenAL32)