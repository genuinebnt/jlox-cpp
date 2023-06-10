#pragma once

#include <string>
#include <vector>

class Logger {
public:
  Logger();
  ~Logger();
  static auto error(int line, const std::string& message, char c) -> void;
  inline static bool hadError = false;

private:
  std::vector<std::string> errorMessages;

  static auto report(int line, const std::string& where, const std::string& message, char c)
      -> void;
};