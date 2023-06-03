#include <gtest/gtest.h>

#include <memory>

#include "Scanner.h"

TEST(ScannerTest, Scan) {
  std::string contents1 = "(({..})).--+);*,==<=>=!===="
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

  std::string contents = "("
                         "(";

  auto scanner = std::make_unique<Scanner>(contents);
  auto tokens = scanner->scanTokens();

  std::vector<TokenType> expectedTokens = {
      TokenType::LEFT_PAREN,
      TokenType::LEFT_PAREN,
  };

  for (const auto &token : tokens) {
    std::cerr << token->toString() << std::endl;
  }

  EXPECT_EQ(tokens.size(), expectedTokens.size());

  for (size_t i = 0; i < tokens.size(); i++) {
    EXPECT_EQ(tokens[i]->getType(), expectedTokens[i]);
  }
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}