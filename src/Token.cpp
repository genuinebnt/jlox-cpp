#include <string>
#include <utility>
#include <vector>

#include "Token.h"

Token::Token(TokenType type, std::string lexeme, int line)
    : _type(type), _lexeme(std::move(lexeme)), _line(line) {}

Token::Token(TokenType type, char lexeme, int line) : _type(type), _line(line) {
  _lexeme = std::string(1, lexeme);
}

Token::~Token() = default;

auto Token::TokenTypeString(TokenType type) -> std::string {
  switch (type) {
  case TokenType::LEFT_PAREN:
    return "LEFT_PAREN";
  case TokenType::RIGHT_PAREN:
    return "RIGHT_PAREN";
  case TokenType::LEFT_BRACE:
    return "LEFT_BRACE";
  case TokenType::RIGHT_BRACE:
    return "RIGHT_BRACE";
  case TokenType::COMMA:
    return "COMMA";
  case TokenType::DOT:
    return "DOT";
  case TokenType::MINUS:
    return "MINUS";
  case TokenType::PLUS:
    return "PLUS";
  case TokenType::SEMICOLON:
    return "SEMICOLON";
  case TokenType::SLASH:
    return "SLASH";
  case TokenType::STAR:
    return "STAR";
  case TokenType::BANG:
    return "BANG";
  case TokenType::BANG_EQUAL:
    return "BANG_EQUAL";
  case TokenType::EQUAL:
    return "EQUAL";
  case TokenType::EQUAL_EQUAL:
    return "EQUAL_EQUAL";
  case TokenType::GREATER:
    return "GREATER";
  case TokenType::GREATER_EQUAL:
    return "GREATER_EQUAL";
  case TokenType::LESS:
    return "LESS";
  case TokenType::LESS_EQUAL:
    return "LESS_EQUAL";
  case TokenType::IDENTIFIER:
    return "IDENTIFIER";
  case TokenType::STRING:
    return "STRING";
  case TokenType::NUMBER:
    return "NUMBER";
  case TokenType::AND:
    return "AND";
  case TokenType::CLASS:
    return "CLASS";
  case TokenType::ELSE:
    return "ELSE";
  case TokenType::FALSE:
    return "FALSE";
  case TokenType::FUN:
    return "FUN";
  case TokenType::FOR:
    return "FOR";
  case TokenType::IF:
    return "IF";
  case TokenType::NIL:
    return "NIL";
  case TokenType::OR:
    return "OR";
  case TokenType::PRINT:
    return "PRINT";
  case TokenType::RETURN:
    return "RETURN";
  case TokenType::SUPER:
    return "SUPER";
  case TokenType::THIS:
    return "THIS";
  case TokenType::TRUE:
    return "TRUE";
  case TokenType::VAR:
    return "VAR";
  case TokenType::WHILE:
    return "WHILE";
  case TokenType::EOF_TOKEN:
    return "EOF_TOKEN";
  default:
    return "UNKNOWN";
  }

  return "UNKNOWN";
}

auto Token::toString() const -> std::string {
  return TokenTypeString(_type) + " " + _lexeme + " " + std::to_string(_line);
}

auto Token::getType() const -> TokenType { return _type; }

auto Token::getTokenType(const std::vector<std::unique_ptr<Token>>& tokens)
    -> std::vector<TokenType> {
  std::vector<TokenType> types;
  for (const auto &token : tokens) {
    types.push_back(token->getType());
  }
  return types;
}