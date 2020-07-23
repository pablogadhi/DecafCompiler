cmake_minimum_required(VERSION 3.0.0)
project(DecafCompiler VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

find_package(PkgConfig)
find_package(antlr4-runtime)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS} ${ANTLR4_INCLUDE_DIR})
link_directories(${GTKMM_LIBRARY_DIRS})

set(DECAF_CORE_FILES
   ${PROJECT_SOURCE_DIR}/core/DecafLexer.cpp 
   ${PROJECT_SOURCE_DIR}/core/DecafParser.cpp
   ${PROJECT_SOURCE_DIR}/core/DecafBaseListener.cpp
   ${PROJECT_SOURCE_DIR}/core/DecafBaseVisitor.cpp
   ${PROJECT_SOURCE_DIR}/core/DecafListener.cpp
   ${PROJECT_SOURCE_DIR}/core/DecafVisitor.cpp
 )
 
set(ALL_SRC_FILES
  ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/decaf_controller.cpp
  ${PROJECT_SOURCE_DIR}/ui_controller.cpp
  ${PROJECT_SOURCE_DIR}/data_tree.cpp
  ${DECAF_CORE_FILES}
)

set (extra_flags "-Wno-overloaded-virtual -Wno-attributes")

foreach(src_file ${ALL_SRC_FILES})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${extra_flags}"
          )
endforeach(src_file ${ALL_SRC_FILES})

add_executable(DecafCompiler ${ALL_SRC_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} antlr4_shared)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
