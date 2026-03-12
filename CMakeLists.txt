cmake_minimum_required(VERSION 3.28)
project(NovaEngineWorkspace)

add_subdirectory(app)

if(NOT SKIP_EXAMPLES)
    #add_subdirectory(examples)
endif()

if(NOT SKIP_MODULES)
    add_subdirectory(modules)
endif()
