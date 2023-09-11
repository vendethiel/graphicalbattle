cmake_minimum_required(VERSION 3.26)
project(graphicalbattle C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_STANDARD 11)
set(CMAKE_GENERATOR "Ninja")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL_MIXER_INCLUDE_DIRS})
# TODO depending on target, if SDL_IMAGE_INCLUDE_DIRS is empty, use this fallback:
# XXX CMAKE_SYSTEM_PREFIX_PATH already has /opt/homebrew, but it's still broken somehow
include_directories("/opt/homebrew/include/SDL2")

add_executable(${PROJECT_NAME}
        actions/event/keydown.c
        actions/tick.c
        fight/fight.c
        fight/monster/monster.c
        lib/err.c
        lib/readfile.c
        lib/sdl/rect.c
        lib/sdl/text.c
        lib/sdl/ximg_load.c
        lib/sdl/xupdate_window_surface.c
        lib/xmalloc.c
        character.c
        class.c
        entity.c
        event.c
        main.c
        game.c
        map.c
        menu/class.c
        menu/draw_menu.c
        menu/fight.c
        sprite.c)

execute_process(COMMAND sdl2-config --libs
    OUTPUT_VARIABLE SDL_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE)

target_link_libraries(graphicalbattle ${SDL_LIBS} SDL2_image SDL2_mixer SDL2_ttf)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
