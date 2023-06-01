#ifndef SCANNER_H
#define SCANNER_H

#include <memory>
#include <string>
#include <vector>

#include "Token.h"

#pragma once

class Scanner {
public:
  Scanner(const std::string contents);
  ~Scanner();

  auto scanTokens() -> std::vector<std::unique_ptr<Token>>;

private:
  std::string _source;
  int _start;
  int _current;
  int _line;
  std::vector<std::unique_ptr<Token>> _tokens;

  auto isAtEnd() -> bool;
  auto scanToken() -> void;
  auto advance() -> char;
  auto addToken(TokenType type) -> void;
  auto addToken(TokenType type, int start, int current) -> void;
  auto match(char expected) -> bool;
  auto peek() -> char;
  auto string() -> void;
  auto number() -> void;
  auto peeknext() -> char;
};

#endif