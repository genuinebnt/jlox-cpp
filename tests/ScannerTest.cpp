#include <gtest/gtest.h>

#include <memory>

#include "../src/Scanner.h"

TEST(ScannerTest, Scan) {
  std::string contents = "(({..})).--+);*,==<=>=!===="
                         "//=>"
                         "*===!"
                         "//comment"
                         "\"this is a string\""
                         "//comment"
                         "!!1234.5678+==="
                         "_isnotakeyworkbutitworks"
                         "&thisshouldntwork"
                         "and"
                         "class"
                         "if"
                         "while";

  auto scanner = std::make_unique<Scanner>(contents);
  auto tokens = scanner->scanTokens();

  std::vector<TokenType> expectedTokens = {TokenType::LEFT_PAREN,
                                           TokenType::LEFT_PAREN};
  EXPECT_EQ(tokens.size(), expectedTokens.size());
  for (size_t i = 0; i < tokens.size(); i++) {
    EXPECT_EQ(tokens[i]->getType(), expectedTokens[i]);
  }
}