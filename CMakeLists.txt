cmake_minimum_required(VERSION 3.18...3.27)

project(Prises VERSION 0.1 LANGUAGES CXX)

find_package(Git)

find_package(gf COMPONENTS graphics QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
      message(STATUS "Submodule update")
      execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                      RESULT_VARIABLE GIT_SUBMOD_RESULT)
      if(NOT GIT_SUBMOD_RESULT EQUAL "0")
          message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
      endif()

      # Override gf options
      set(BUILD_TESTING OFF CACHE BOOL "Build tests")
      set(GF_DEBUG OFF CACHE BOOL "Activate debug build")
      set(GF_BUILD_EXAMPLES OFF CACHE BOOL "Build examples")
      set(GF_BUILD_DOCUMENTATION OFF CACHE BOOL "Build documentation (needs Doxygen)")
      set(GF_BUILD_GAMES OFF CACHE BOOL "Build games")

      add_subdirectory(src/vendor/gf)
      add_library(gf::graphics ALIAS gf0)
  endif()
endif()

find_package(box2d REQUIRED)

add_executable(prises
  src/vendor/gf-box2d/gfb2d/PhysicsModel.cc
  src/vendor/gf-box2d/gfb2d/PhysicsDebugger.cc

  src/local/GameHub.cc
  src/local/GameData.cc
  src/local/LevelScene.cc
  src/local/LevelData.cc
  src/local/LevelEntity.cc
  src/local/MenuEntity.cc
  src/local/MenuScene.cc
  src/local/PlayerEntity.cc
  src/local/PhysicsState.cc
  src/main.cc
)

target_include_directories(prises
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/vendor/gf-box2d
    ${CMAKE_BINARY_DIR}
)

target_link_libraries(prises
  gf::graphics
  box2d::box2d
)

target_compile_features(prises
  PUBLIC
    cxx_std_14
)

set_target_properties(prises
  PROPERTIES
    CXX_EXTENSIONS OFF
)

if(NOT MSVC)
  target_compile_options(prises
    PRIVATE
    $<$<CONFIG:DEBUG>:-Wall>
    $<$<CONFIG:DEBUG>:-Wextra>
    $<$<CONFIG:DEBUG>:-g>
    $<$<CONFIG:DEBUG>:-fsanitize=address,undefined>
  )

  target_link_options(prises
    PRIVATE
      $<$<CONFIG:DEBUG>:-fsanitize=address,undefined>
  )
endif()

include(GNUInstallDirs)
set(GAME_DATA_DIR "${CMAKE_INSTALL_FULL_DATAROOTDIR}/games" CACHE PATH "Game Data Dir")
set(GAME_RELATIVE_DATA_DIR "./share/prises" CACHE STRING "Game Relative Data Dir")
configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_BINARY_DIR}/config.h @ONLY)

if (WIN32)
  install(
    FILES
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/SDL2d.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/brotlicommon.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/brotlidec.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/bz2d.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/freetyped.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/gf0.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/gfcore0.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/libpng16d.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/pugixml_d.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/zlibd1.dll>
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/prises.pdb>

      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/SDL2.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/brotlicommon.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/brotlidec.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/bz2.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/freetype.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/gf0.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/gfcore0.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/libpng16.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/pugixml.dll>
      $<$<CONFIG:RELEASE>:${CMAKE_BINARY_DIR}/Release/zlib1.dll>
    DESTINATION .
  )

  install(TARGETS prises DESTINATION .)
else ()
  install(TARGETS prises RUNTIME)
endif ()

# Install data
install(DIRECTORY ${CMAKE_SOURCE_DIR}/data/prises DESTINATION ${CMAKE_INSTALL_DATADIR})

# Package rules
if (WIN32)
  set(CPACK_GENERATOR "ZIP")
  include(CPack)
endif()
