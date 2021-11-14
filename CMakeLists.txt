cmake_minimum_required(VERSION 3.18...3.21)

project(GameFlo VERSION 0.1 LANGUAGES CXX)

find_package(gf COMPONENTS graphics REQUIRED)

add_executable(game-flo
  src/local/GameHub.cc
  src/local/GameModel.cc
  src/local/LevelScene.cc
  src/local/MapEntity.cc
  src/local/MenuEntity.cc
  src/local/MenuScene.cc
  src/local/PlayerEntity.cc
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
    cxx_std_14
)

set_target_properties(game-flo
  PROPERTIES
    CXX_EXTENSIONS OFF
)

include(GNUInstallDirs)

set(GAME_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/games/game-flo")
set(GAME_SOURCE_DATA_DIR "./share/game-flo")

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(GAME_SOURCE_DATA_DIR "${CMAKE_SOURCE_DIR}/data/game-flo") # To avoid to doing make install

  if(NOT MSVC)
    target_compile_options(game-flo
      PRIVATE
      "-Wall" "-Wextra" "-g" "-fsanitize=address,undefined"
    )

    set_target_properties(game-flo
      PROPERTIES
        LINK_FLAGS "-fsanitize=address,undefined"
    )
  endif()
endif()

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_BINARY_DIR}/config.h @ONLY)

# Install rules
if(NOT WIN32)
  set(RUNTIME_DIR ${CMAKE_INSTALL_BINDIR})
else()
  set(RUNTIME_DIR .)
endif()

# Install executable
install(TARGETS game-flo DESTINATION ${RUNTIME_DIR})

# Install DLL (under windows only)
if (WIN32)
  if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/SDL2d.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/brotlicommon.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/brotlidec.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/bz2d.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/freetyped.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/gf0.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/gfcore0.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/libpng16d.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/pugixml_d.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/zlibd1.dll)
  else()
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/SDL2.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/brotlicommon.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/brotlidec.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/bz2.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/freetype.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/gf0.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/gfcore0.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/libpng16.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/pugixml.dll)
    list(APPEND DLL_FILES ${CMAKE_BINARY_DIR}/zlib1.dll)
  endif()

  install(FILES ${DLL_FILES} DESTINATION ${RUNTIME_DIR})
endif ()

# Install data
install(DIRECTORY ${CMAKE_SOURCE_DIR}/data/game-flo DESTINATION ${CMAKE_INSTALL_DATADIR})

# Package rules
if (WIN32)
  set(CPACK_GENERATOR "ZIP")
  include(CPack)
endif()
