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
  auto multilineComment() -> void;
  auto number() -> void;
  auto peeknext() -> char;
  auto isAlpha(char c) -> bool;
  auto isAlphaNumeric(char c) -> bool;
  auto identifier() -> void;

  inline static const std::map<std::string, TokenType> _keywords = {
      {"and", TokenType::AND},       {"class", TokenType::CLASS},
      {"else", TokenType::ELSE},     {"false", TokenType::FALSE},
      {"for", TokenType::FOR},       {"fun", TokenType::FUN},
      {"if", TokenType::IF},         {"nil", TokenType::NIL},
      {"or", TokenType::OR},         {"print", TokenType::PRINT},
      {"return", TokenType::RETURN}, {"super", TokenType::SUPER},
      {"this", TokenType::THIS},     {"true", TokenType::TRUE},
      {"var", TokenType::VAR},       {"while", TokenType::WHILE},
  };
};

#endif