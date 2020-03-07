add_library(basic_expr SHARED)

target_compile_features(basic_expr PRIVATE cxx_std_14)

target_sources(basic_expr
  PUBLIC
    basic_expr.cpp
    simple_evaluator.cpp
    simple_ast.cpp
  )

target_include_directories(basic_expr
  PUBLIC .
  )

if(MSVC)
target_compile_options(basic_expr PRIVATE /W4 /WX)
else()
target_compile_options(basic_expr PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
