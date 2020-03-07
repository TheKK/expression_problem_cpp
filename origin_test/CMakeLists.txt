add_executable(eval eval.cpp)

target_compile_features(eval PRIVATE cxx_std_14)

if(MSVC)
  target_compile_options(eval PRIVATE /W4 /WX)
else()
  target_compile_options(eval PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(eval basic_expr)

###

add_executable(ast ast.cpp)

target_compile_features(ast PRIVATE cxx_std_14)

if(MSVC)
  target_compile_options(ast PRIVATE /W4 /WX)
else()
  target_compile_options(ast PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(ast basic_expr)
