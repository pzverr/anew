#include <algorithm>

#include "argparse.h"

ArgParser::ArgParser(int& argc, char** argv) {
  for (int i = 1; i < argc; ++i)
    tokens.push_back(std::string(argv[i]));
}

const std::string& ArgParser::GetArgument(const std::string& option) const {
  auto it = std::find(this->tokens.begin(), this->tokens.end(), option);

  if (it != this->tokens.end() && ++it != this->tokens.end()) {
    return *it;
  }

  static const std::string empty_string("");

  return empty_string;
}

bool ArgParser::Exists(const std::string& option) const {
  auto it = std::find(this->tokens.begin(), this->tokens.end(), option);
  return it != this->tokens.end();
}
