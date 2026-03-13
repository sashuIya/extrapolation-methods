#include "include/data_provider.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace extrapolation {

DataProvider::Data DataProvider::ReadFromFile(const std::string& filename) {
  DataProvider::Data data;
  std::ifstream input_file(filename);

  if (!input_file.is_open()) {
    std::cerr << "Failed to open input file: " << filename << std::endl;
    return data;
  }

  double x_curr, f_curr;
  while (input_file >> x_curr >> f_curr) {
    data.x.push_back(x_curr);
    data.f.push_back(f_curr);
  }

  return data;
}

}  // namespace extrapolation
