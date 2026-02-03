#include "fnn/tensor.hpp"

// Source responsibilities (best practice):
// - Define functions declared in the header.
// - Include heavier headers here (e.g., <stdexcept>) rather than in the public
//   header to keep compile times down for users.

#include <limits>
#include <stdexcept>

namespace fnn {

Tensor::Tensor(Dims dims) : dims_(dims) {}

void Tensor::reshape(Dims new_dims) {
    // Reshape is only a metadata change: it must not change element count.
    // TODO (yours): implement the element-count check using product(dims).
    // This is the correct place to keep the logic: inside the tensor
    // implementation, not in apps/tests, so it can't drift.
    if () {
        throw std::invalid_argument(
            "Tensor::reshape: element count must stay constant");
    }
}

Dims Tensor::shape(){
    return dims_;
}

// TODO (yours): This `shape()` function currently does not match the `Tensor`
// class in `include/fnn/tensor.hpp` (it references `Shape`, `rows_`, `cols_`).
// Decide how you want to represent N-D shape publicly:
// - return `Dims` directly, or
// - define a dedicated `TensorShape` type for N-D tensors.
Shape Tensor::shape() const noexcept {

}

} // namespace fnn
