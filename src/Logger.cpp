#include "Logger.h"
#include <iostream>

Logger::Logger() {}

Logger::~Logger() {}

auto Logger::error(int line, std::string message) -> void {
  report(line, "", message);
}

auto Logger::report(int line, std::string where, std::string message) -> void {
  std::cout << "[line " << line << "] Error: " << where << ": " << message
            << std::endl;
  hadError = true;
}