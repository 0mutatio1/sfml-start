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
    "src/include/Category.h"
    src/State.cpp
    src/include/State.h
    src/include/StateIdentifiers.h
    src/StateStack.cpp
    src/include/StateStack.h
    src/GameState.cpp
    src/include/GameState.h
    src/Application.cpp
    src/include/Application.h
    src/TitleState.cpp
    src/include/TitleState.h
    src/Utility.cpp
    src/include/Utility.h
    src/MenuState.cpp
    src/include/MenuState.h
    src/PauseState.cpp

    src/include/PauseState.h
    src/LoadingState.cpp
    src/include/LoadingState.h
    src/ParallelTask.cpp
    src/include/ParallelTask.h
    src/Component.cpp
    src/include/Component.h  "src/include/Container.h" "src/Container.cpp"
        src/Label.cpp
        src/include/Label.h
        src/Button.cpp
        src/include/Button.h
        src/SettingState.cpp
        src/include/SettingState.h
        src/GameOverState.cpp
        src/include/GameOverState.h
        src/DataTables.cpp
        src/include/DataTables.h
        src/TextNode.cpp
        src/include/TextNode.h
        src/Pickup.cpp
        src/include/Pickup.h
        src/Projectile.cpp
        src/include/Projectile.h
        src/Particle.cpp
        src/include/Particle.h
        src/ParticleNode.cpp
        src/include/ParticleNode.h
        src/EmitterNode.cpp
        src/include/EmitterNode.h
        src/Animation.cpp
        src/include/Animation.h
)


target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
