#include "fnn/tensor2D.hpp"

// Source responsibilities (best practice):
// - Define functions declared in the header.
// - Include heavier headers here (e.g., <stdexcept>) rather than in the public
//   header to keep compile times down for users.

#include <algorithm>
#include <limits>
#include <stdexcept>

namespace fnn {

Tensor2D::Tensor2D(std::size_t rows, std::size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols) {}

void Tensor2D::zero_fill() { std::fill(data_.begin(), data_.end(), 0.0); }

void Tensor2D::reshape(std::size_t new_rows, std::size_t new_cols) {
    // Reshape is only a metadata change: it must not change element count.
    if (rows_ * cols_ != new_rows * new_cols) {
        throw std::invalid_argument(
            "Tensor2D::reshape: element count must stay constant");
    }

    rows_ = new_rows;
    cols_ = new_cols;
}

Shape Tensor2D::shape() const noexcept { return {rows_, cols_}; }

} // namespace fnn
