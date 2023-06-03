#ifndef LOGGER_H
#define LOGGER_H

#pragma once
#include <string>
#include <vector>

class Logger {
public:
  Logger();
  ~Logger();
  static auto error(int line, std::string message, char c) -> void;
  inline static bool hadError = false;

private:
  std::vector<std::string> errorMessages;

  static auto report(int line, std::string where, std::string message, char c)
      -> void;
};

#endif