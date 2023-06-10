#include "Logger.h"
#include <iostream>
#include <utility>

Logger::Logger() = default;

Logger::~Logger() = default;

auto Logger::error(int line, const std::string& message, char c) -> void {
  report(line, "", message, c);
}

auto Logger::report(int line, const std::string& where, const std::string& message, char c)
    -> void {
  std::cout << "[line " << line << "] Error: " << where << ": " << message
            << " " << c << std::endl;
  hadError = true;
}