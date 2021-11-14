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

if(NOT MSVC)
  target_compile_options(game-flo
    PRIVATE
    $<$<CONFIG:DEBUG>:"-Wall";"-Wextra";"-g";"-fsanitize=address,undefined">
  )

  set_target_properties(game-flo
    PROPERTIES
      LINK_FLAGS $<$<CONFIG:DEBUG>:"-fsanitize=address,undefined">
  )
endif()

include(GNUInstallDirs)
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
      $<$<CONFIG:DEBUG>:${CMAKE_BINARY_DIR}/Debug/game-flo.pdb>

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

  install(TARGETS game-flo DESTINATION .)
else ()
  install(TARGETS game-flo RUNTIME)
endif ()

# Install data
install(DIRECTORY ${CMAKE_SOURCE_DIR}/data/game-flo DESTINATION ${CMAKE_INSTALL_DATADIR})

# Package rules
if (WIN32)
  set(CPACK_GENERATOR "ZIP")
  include(CPack)
endif()
