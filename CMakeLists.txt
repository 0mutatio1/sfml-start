cmake_minimum_required(VERSION 3.16)
project(asdf )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(
    main
    src/main.cpp
    src/include/StringHelpers.h
    src/include/ResourceHolder.h
    src/Game.cpp
    src/include/Game.h
    src/World.cpp
    src/include/World.h
    src/Player.cpp
    src/include/Player.h
    src/CommandQueue.cpp
    src/include/CommandQueue.h
    src/include/ResourceIdentifiers.h
    src/SceneNode.cpp
    src/include/SceneNode.h
    src/Aircraft.cpp
    src/include/Aircraft.h
    src/Command.cpp
    src/include/Command.h
    src/Entity.cpp
    src/include/Entity.h
    src/SpriteNode.cpp
    src/include/SpriteNode.h
 "src/include/Category.h")

target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
