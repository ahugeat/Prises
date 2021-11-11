cmake_minimum_required(VERSION 3.18...3.21)

project(GameFlo VERSION 0.1 LANGUAGES CXX)

find_package(gf COMPONENTS graphics REQUIRED)

add_executable(game-flo
  src/local/GameHub.cc
  src/local/MenuEntity.cc
  src/local/MenuScene.cc
  src/main.cc
)

target_include_directories(game-flo
  PRIVATE
    ${CMAKE_SOURCE_DIR}/code
    ${CMAKE_BINARY_DIR}
)

target_link_libraries(game-flo
  gf::graphics
)

target_compile_features(game-flo
  PUBLIC
    cxx_std_17
)

set_target_properties(game-flo
  PROPERTIES
    CXX_EXTENSIONS OFF
)

include(GNUInstallDirs)
set(GAME_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/games/game-flo")
set(GAME_SOURCE_DATA_DIR ".")

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(GAME_SOURCE_DATA_DIR "${CMAKE_SOURCE_DIR}/data/game-flo") # To avoid to doing make install

  target_compile_options(game-flo
    PRIVATE
    "-Wall" "-Wextra" "-g" "-fsanitize=address,undefined"
  )

  set_target_properties(game-flo
    PROPERTIES
      LINK_FLAGS "-fsanitize=address,undefined"
  )
endif()

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_BINARY_DIR}/config.h @ONLY)
