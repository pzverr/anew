#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>

void ReadSourceFileContents(std::ifstream& stream,
                            std::vector<std::string>& lines);
const std::vector<std::string>
GetNewLinesFromStream(std::istream& stream,
                      const std::vector<std::string>& lines);

#endif
