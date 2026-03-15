#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "complex_num.h"
#include "data_provider.h"
#include "extrapolation.h"

using extrapolation::ComplexNum;
using extrapolation::DataProvider;
using extrapolation::ExtrapolationEngine;

void PrintUsage(const char* prog_name) {
  std::cout << "Usage: " << prog_name << " [input_file] [output_file] [imaginary_part]\n"
            << "Defaults:\n"
            << "  input_file: input.txt\n"
            << "  output_file: output.txt\n"
            << "  imaginary_part: 0.1\n";
}

int main(int argc, char* argv[]) {
  std::string input_filename = "input.txt";
  std::string output_filename = "output.txt";
  double imaginary_part = 0.1;

  if (argc > 1) {
    std::string arg1 = argv[1];
    if (arg1 == "-h" || arg1 == "--help") {
      PrintUsage(argv[0]);
      return 0;
    }
    input_filename = arg1;
  }
  if (argc > 2) {
    output_filename = argv[2];
  }
  if (argc > 3) {
    try {
      imaginary_part = std::stod(argv[3]);
    } catch (const std::exception& e) {
      std::cerr << "Invalid imaginary part: " << argv[3] << ". Using default 0.1\n";
    }
  }

  DataProvider::Data data = DataProvider::ReadFromFile(input_filename);
  if (data.x.empty()) {
    std::cerr << "No data read from " << input_filename << std::endl;
    return 1;
  }

  std::ofstream output_file(output_filename);
  if (!output_file.is_open()) {
    std::cerr << "Failed to open output file: " << output_filename << std::endl;
    return 1;
  }

  output_file << std::fixed << std::setprecision(2);

  ComplexNum point(0.0, imaginary_part);

  for (size_t index = 0; index < data.x.size(); ++index) {
    point.set_x(data.x[index]);
    output_file << ExtrapolationEngine::GetPolynomialValue(data.x, data.f, point) << "\n";
  }

  for (size_t index = 0; index < data.x.size(); ++index) {
    point.set_x(data.x[index]);
    output_file << ExtrapolationEngine::GetRationalValue(data.x, data.f, point) << "\n";
  }

  std::cout << "Results written to " << output_filename << std::endl;

  return 0;
}
