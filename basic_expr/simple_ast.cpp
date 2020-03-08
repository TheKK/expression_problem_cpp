#include "simple_ast.hpp"

#include <string>
#include <unordered_map>

std::string
ast(const IntExpr& e) {
  return std::to_string(e.val);
}
