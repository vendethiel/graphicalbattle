cmake_minimum_required(VERSION 3.26)
project(graphicalbattle C)

set(CMAKE_C_STANDARD 11)

add_executable(graphicalbattle
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
