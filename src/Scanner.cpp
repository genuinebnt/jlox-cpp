#include <iostream>
#include <memory>

#include "Lox.h"
#include "Scanner.h"

Scanner::Scanner(const std::string contents)
    : _source(contents), _start(0), _current(0), _line(1) {}

Scanner::~Scanner() {}

auto Scanner::isAtEnd() -> bool {
  return _current >= static_cast<int>(_source.length());
}

auto Scanner::scanTokens() -> std::vector<std::unique_ptr<Token>> {

  while (!isAtEnd()) {
    _start = _current;
    scanToken();
  }

  _tokens.push_back(std::make_unique<Token>(TokenType::EOF_TOKEN, "", _line));

  return std::move(_tokens);
}

auto Scanner::scanToken() -> void {
  char c = advance();

  switch (c) {
  case '(':
    addToken(TokenType::LEFT_PAREN);
    break;
  case ')':
    addToken(TokenType::RIGHT_PAREN);
    break;
  case '{':
    addToken(TokenType::LEFT_BRACE);
    break;
  case '}':
    addToken(TokenType::RIGHT_BRACE);
    break;
  case ',':
    addToken(TokenType::COMMA);
    break;
  case '.':
    addToken(TokenType::DOT);
    break;
  case '-':
    addToken(TokenType::MINUS);
    break;
  case '+':
    addToken(TokenType::PLUS);
    break;
  case ';':
    addToken(TokenType::SEMICOLON);
    break;
  case '*':
    addToken(TokenType::STAR);
    break;
  case '!':
    addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    break;
  case '<':
    addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    break;
  case '>':
    addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  default:
    Logger::error(_line, "Unexpected token");
  }
}

auto Scanner::match(char expected) -> bool {
  if (isAtEnd()) {
    return false;
  }

  if (_source[_current] != expected) {
    return false;
  }

  _current += 1;
  return true;
}

auto Scanner::advance() -> char { return _source.at(_current++); }

auto Scanner::addToken(TokenType type) -> void {
  std::string text = _source.substr(_start, _current - _start);

  auto token = std::make_unique<Token>(type, text, _line);
  _tokens.push_back(std::move(token));
}