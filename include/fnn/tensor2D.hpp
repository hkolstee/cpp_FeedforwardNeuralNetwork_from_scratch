#pragma once

#include "config.hpp"

#include <cstddef>

namespace fnn {

// Header responsibilities (policy B for this repo):
// - Keep headers declaration-only: no function bodies here (even trivial getters),
//   except for templates / inline constants that must live in headers.
// - Put definitions in a corresponding `.cpp` to reduce rebuild impact.
//   See `src/tensor2D.cpp`.

struct Shape {
    std::size_t rows{};
    std::size_t cols{};
};

class Tensor2D {
public:
    Tensor2D(std::size_t rows, std::size_t cols);

    // zero intialization
    void zero_fill();
    // Reshape to a new (rows, cols) pair, effectively only metadata change.
    void reshape(std::size_t new_rows, std::size_t new_cols);
    // Shape itself
    [[nodiscard]] Shape shape() const noexcept;

private:
    std::size_t rows_{0};
    std::size_t cols_{0};

    // Store elements in a single contiguous buffer of length rows_*cols_.
    // This is typically more cache-friendly than `vector<vector<...>>`.
    Vector data_;
};

} // namespace fnn
