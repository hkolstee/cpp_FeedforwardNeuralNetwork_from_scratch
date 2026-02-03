#pragma once

#include <cstddef>
#include <string_view>
#include <vector>
#include <utility>

namespace fnn {

// Project metadata (kept header-only for simplicity).
inline constexpr std::string_view kProjectName = "FeedforwardNeuralNetwork";
inline constexpr std::string_view kVersion = "0.1.0";

// Minimal numeric types used across the public API.
using Scalar = double;
using Vector = std::vector<Scalar>;
using Dims = std::vector<std::size_t>;

} // namespace fnn
