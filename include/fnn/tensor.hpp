#pragma once

#include "config.hpp"

#include <cstddef>
#include <vector>

namespace fnn {

class Tensor {
  public:
    Tensor(Dims dims);
    // returns number of elements in the tensor
    size_t numel();
    // returns shape dimensionality
    Dims shape();
    // Reshape to a new set of dimensions.
    void reshape(Dims dims);

  private:
    Dims dims_;
    // Store elements in a single contiguous buffer of length product(dims_).
    Vector data_;
};

} // namespace fnn
