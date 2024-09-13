#include <algorithm>

#include "argparse.h"
#include "main.h"

void ReadSourceFileContents(std::ifstream& stream,
                            std::vector<std::string>& lines) {
  std::string line;

  while (getline(stream, line)) {
    if (line.empty())
      continue;

    lines.push_back(line);
  }
}

const std::vector<std::string>
GetNewLinesFromStream(std::istream& stream,
                      const std::vector<std::string>& lines) {
  std::vector<std::string> new_lines;

  std::string line;

  while (getline(stream, line)) {
    if (line.empty())
      continue;

    if (std::find(lines.begin(), lines.end(), line) != lines.end())
      continue;

    new_lines.push_back(line);
  }

  return new_lines;
}

int main(int argc, char* argv[]) {
  bool quiet_mode = false;
  bool dry_run = false;

  ArgParser arg_parse(argc, argv);
  if (arg_parse.Exists("-q"))
    quiet_mode = true;

  if (arg_parse.Exists("-d"))
    dry_run = true;

  const std::string& filename = arg_parse.GetArgument("-f");

  if (filename.empty()) {
    std::cerr << "filename not passed\n";
    return 1;
  }

  std::vector<std::string> lines;

  std::ifstream ifs(filename);
  std::ofstream ofs(filename, ofs.app);

  if (!ifs.is_open()) {
    std::cerr << "could not open file\n";
    return 1;
  }

  ReadSourceFileContents(ifs, lines);

  const std::vector<std::string> new_lines =
      GetNewLinesFromStream(std::cin, lines);

  for (const std::string& line : new_lines) {
    if (!quiet_mode)
      std::cout << line << "\n";

    if (!dry_run)
      ofs << line << "\n";
  }
}
