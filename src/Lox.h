#pragma once

#include <memory>
#include <string>

#include "Logger.h"

class Lox {
public:
  Lox();
  ~Lox();

  auto runFile(const std::string &filepath) -> void;
  auto runPrompt() -> void;

private:
  static auto run(const std::string& contents) -> void;
};