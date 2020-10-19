cmake_minimum_required(VERSION 3.5.1)
project(pcreshow VERSION 1.0.0.0 LANGUAGES C CXX)

add_executable(main main.c)

if(WITHOUT_UTF)
	add_definitions(-DWITHOUT_UTF)
endif()
message("flag = " ${WITHOUT_UTF})

add_custom_target(pcre2)
add_library(pcre STATIC pcre.c)
find_library(PCRE2_LIBRARIES NAMES pcre2 pcre2-8)
find_path(PCRE2_INCLUDE_DIRS pcre2.h)

find_package(Curses REQUIRED)

include_directories(
	${CURSES_INCLUDE_DIRS}
	${PCRE2_INCLUDE_DIRS} )

target_link_libraries(main pcre ncurses ${CURSES_LIBRSRIES}  ${PCRE2_LIBRARIES})

add_custom_target(allclean COMMAND rm CMakeCache.txt && rm cmake_install.cmake && rm Makefile* && rm libpcre.a && rm -rf CMakeFiles/)
