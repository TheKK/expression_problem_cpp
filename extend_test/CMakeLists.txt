add_executable(extend_ast ast.cpp)

target_compile_features(extend_ast PRIVATE cxx_std_14)

if(MSVC)
  target_compile_options(extend_ast PRIVATE /W4 /WX)
else()
  target_compile_options(extend_ast PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(extend_ast basic_expr)
