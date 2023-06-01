#include <cctype>
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
  case '/':
    if (match('/')) {
      while (peek() != '\n' && !isAtEnd()) {
        advance();
      }
    } else {
      addToken(TokenType::SLASH);
    }
    break;
  case ' ':
    break;
  case '\t':
    break;
  case '\r':
    break;
  case '\n':
    _line += 1;
    break;
  case '"':
    string();
    break;
  default:
    if (isdigit(c)) {
      number();
    } else {
      Logger::error(_line, "Unexpected token");
    }
  }
}

auto Scanner::number() -> void {
  while (isdigit(peek())) {
    advance();
  }

  if (peek() == '.' && isdigit(peeknext())) {
    advance();
  }

  while (isdigit(peek())) {
    advance();
  }

  addToken(TokenType::NUMBER);
}

auto Scanner::advance() -> char { return _source.at(_current++); }

auto Scanner::peek() -> char {
  if (isAtEnd()) {
    return '\0';
  }
  return _source[_current];
}

auto Scanner::peeknext() -> char {
  if (_current + 1 >= static_cast<int>(_source.size())) {
    return '\0';
  }

  return _source[_current + 1];
}

auto Scanner::string() -> void {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n') {
      _line += 1;
    }
    advance();
  }

  if (isAtEnd()) {
    Logger::error(_line, "Unterminated string");
    return;
  }

  advance();
  addToken(TokenType::STRING, _start + 1, _current - 1);
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

auto Scanner::addToken(TokenType type) -> void {
  std::string text = _source.substr(_start, _current - _start);

  auto token = std::make_unique<Token>(type, text, _line);
  _tokens.push_back(std::move(token));
}

auto Scanner::addToken(TokenType type, int start, int current) -> void {
  std::string text = _source.substr(start, current - start);

  auto token = std::make_unique<Token>(type, text, _line);
  _tokens.push_back(std::move(token));
}