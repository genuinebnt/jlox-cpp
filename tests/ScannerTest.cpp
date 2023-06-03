#include <gtest/gtest.h>

#include <memory>

#include "Scanner.h"

TEST(ScannerTest, Scan) {
  std::string contents = "(){},.-+;*==!=<=>="
                         "\"this is a string\""
                         "!!1234.5678"
                         "_isnotakeyworkbutitworks"
                         "&thisshouldntwork"
                         "/*this is a mult\n"
                         "iline comment*/\n"
                         "//comment\n"
                         "and\n"
                         "class\n"
                         "if\n"
                         "while\n"
                         "/*this will cause error";

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
    // EXPECT_EQ(tokens[i]->getType(), expectedTokens[i]);
  }
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}