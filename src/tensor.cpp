#include "fnn/tensor.hpp"
#include "fnn/util/math.hpp"

#include <stdexcept>

namespace fnn {

Tensor::Tensor(Dims dims) : dims_(std::move(dims)) {
    const auto count = util::product(dims_, "Tensor: element count overflows size_t");
    data_.resize(count);
}

size_t Tensor::numel() { return util::product(dims_, "Tensor::numel overflows size_t"); }

Dims Tensor::shape() { return dims_; }

void Tensor::reshape(Dims dims) {
    const auto old_count = numel();
    const auto new_count = util::product(dims, "Tensor::reshape overflows size_t");
    if (new_count != old_count) {
        throw std::invalid_argument("Tensor::reshape: element count must stay constant");
    }

    dims_ = std::move(dims);
}

} // namespace fnn
