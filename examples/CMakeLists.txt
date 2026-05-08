cmake_minimum_required(VERSION 3.28)
project(NovaEngineExamples)

file(GLOB CHILDREN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(child ${CHILDREN})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${child}/app")
        add_subdirectory(${child}/app)
    endif()
endforeach()