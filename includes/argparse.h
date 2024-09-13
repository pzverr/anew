#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <string>
#include <vector>

class ArgParser {
public:
  ArgParser(int& argc, char** argv);

  const std::string& GetArgument(const std::string& option) const;

  bool Exists(const std::string& option) const;

private:
  std::vector<std::string> tokens;
};

#endif
