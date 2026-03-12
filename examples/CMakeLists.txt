cmake_minimum_required(VERSION 3.28)
project(NovaEngineExamples)

file(GLOB BLOB_FOLDERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
foreach(folder ${BLOB_FOLDERS})
    add_subdirectory(${folder}/app)
endforeach()