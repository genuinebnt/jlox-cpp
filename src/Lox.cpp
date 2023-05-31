#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "Lox.h"
#include "Scanner.h"

Lox::Lox() {}

Lox::~Lox() {}

auto Lox::runFile(const std::string &filepath) -> void {
  std::ifstream input_file(filepath);
  if (!input_file.is_open()) {
    std::cerr << "Error: Could not open file " << filepath << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string contents((std::istreambuf_iterator<char>(input_file)),
                       std::istreambuf_iterator<char>());

  run(contents);

  if (Logger::hadError) {
    exit(65);
  }
}

auto Lox::run(const std::string contents) -> void {
  auto scanner(std::make_unique<Scanner>(contents));
  auto tokens = scanner->scanTokens();

  for (const auto &token : tokens) {
    std::cout << token->toString() << std::endl;
  }
}
