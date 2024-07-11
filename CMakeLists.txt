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
        src/Aircraft.cpp
        src/Aircraft.hpp
        src/Animation.cpp
        src/Animation.hpp
        src/Application.cpp
        src/Application.hpp
        src/Button.cpp
        src/Button.hpp
        src/BloomEffect.cpp
        src/BloomEffect.hpp
        src/Category.hpp
        src/Command.hpp
        src/Command.cpp
        src/CommandQueue.hpp
        src/CommandQueue.cpp
        src/Component.hpp
        src/Component.cpp
        src/Container.hpp
        src/Container.cpp
        src/DataTables.hpp
        src/DataTables.cpp
        src/EmitterNode.hpp
        src/EmitterNode.cpp
        src/Entity.hpp
        src/Entity.cpp
        src/GameOverState.hpp
        src/GameOverState.cpp
        src/GameServer.hpp
        src/GameServer.cpp
        src/GameState.hpp
        src/GameState.cpp
        src/KeyBinding.hpp
        src/KeyBinding.cpp
        src/Label.hpp
        src/Label.cpp
        src/MenuState.hpp
        src/MenuState.cpp
        src/MultiplayerGameState.hpp
        src/MultiplayerGameState.cpp
        src/MusicPlayer.hpp
        src/MusicPlayer.cpp
        src/NetworkNode.hpp
        src/NetworkNode.cpp
        src/PauseState.hpp
        src/PauseState.cpp
        src/Particle.hpp
        src/ParticleNode.hpp
        src/ParticleNode.cpp
        src/Pickup.hpp
        src/Pickup.cpp
        src/Player.hpp
        src/Player.cpp
        src/PostEffect.hpp
        src/PostEffect.cpp
        src/Projectile.hpp
        src/Projectile.cpp
        src/ResourceHolder.hpp
        src/ResourceIdentifiers.hpp
        src/ResourceHolder.inl
        src/Foreach.hpp
        src/SceneNode.hpp
        src/SceneNode.cpp
        src/SettingsState.hpp
        src/SettingsState.cpp
        src/SpriteNode.hpp
        src/SpriteNode.cpp
        src/TextNode.hpp
        src/TextNode.cpp
        src/SoundNode.hpp
        src/SoundNode.cpp
        src/SoundPlayer.hpp
        src/SoundPlayer.cpp
        src/State.hpp
        src/State.cpp
        src/StateIdentifiers.hpp
        src/StateStack.hpp
        src/StateStack.cpp
        src/TitleState.hpp
        src/TitleState.cpp
        src/Utility.hpp
        src/Utility.cpp
        src/Utility.inl
        src/World.hpp
        src/World.cpp
)


target_link_libraries(main PRIVATE sfml-graphics sfml-audio sfml-network)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
