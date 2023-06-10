#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

enum TokenType {
  // Single-character tokens.
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  // One or two character tokens.
  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  // Literals.
  IDENTIFIER,
  STRING,
  NUMBER,

  // Keywords.
  AND,
  CLASS,
  ELSE,
  FALSE,
  FUN,
  FOR,
  IF,
  NIL,
  OR,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,

  EOF_TOKEN
};

class Token {
public:
  Token(TokenType type, std::string lexeme, int line);
  Token(TokenType type, char lexeme, int line);
  ~Token();

  static auto TokenTypeString(TokenType type) -> std::string;
  [[nodiscard]] auto toString() const -> std::string;
  static auto getTokenType(const std::vector<std::unique_ptr<Token>>& tokens)
      -> std::vector<TokenType>;
  [[nodiscard]] auto getType() const -> TokenType;

private:
  TokenType _type;
  std::string _lexeme;
  int _line;
};