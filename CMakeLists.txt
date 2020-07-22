cmake_minimum_required(VERSION 3.0.0)
project(DecafCompiler VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/usr/include/antlr4-runtime /usr/include/libgtkmm-3.0)

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
target_link_libraries(DecafCompiler antlr4-runtime gtkmm-3.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
