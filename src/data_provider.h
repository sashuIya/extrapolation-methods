#ifndef EXTRAPOLATION_METHODS_DATA_PROVIDER_H_
#define EXTRAPOLATION_METHODS_DATA_PROVIDER_H_

#include <string>
#include <vector>

namespace extrapolation {

// DataProvider handles reading input data from files.
class DataProvider {
 public:
  struct Data {
    std::vector<double> x;
    std::vector<double> f;
  };

  // Reads data from the specified file.
  // Returns the data on success, or an empty Data object on failure.
  static Data ReadFromFile(const std::string& filename);
};

}  // namespace extrapolation

#endif  // EXTRAPOLATION_METHODS_DATA_PROVIDER_H_
