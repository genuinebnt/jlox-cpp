#include "Logger.h"
#include <iostream>

Logger::Logger() {}

Logger::~Logger() {}

auto Logger::error(int line, std::string message, char c) -> void {
  report(line, "", message, c);
}

auto Logger::report(int line, std::string where, std::string message, char c)
    -> void {
  std::cout << "[line " << line << "] Error: " << where << ": " << message
            << " " << c << std::endl;
  hadError = true;
}