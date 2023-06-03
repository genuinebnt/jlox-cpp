#include <iostream>
#include <memory>

#include "Lox.h"

auto main(int argc, char *argv[]) -> int {
  if (argc > 2) {
    std::cout << "Usage: jlox-cpp [script]" << std::endl;
    return 64;
  }

  std::unique_ptr<Lox> lox = std::make_unique<Lox>();

  if (argc == 2) {
    lox->runFile(argv[1]);
  }
}