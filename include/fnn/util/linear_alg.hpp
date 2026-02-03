
#pragma once

#include "fnn/config.hpp"
#include <cstddef>
#include <vector>

namespace fnn::util {

[[nodiscard]] std::size_t multiply(std::size_t a, std::size_t b, const char* what);
[[nodiscard]] int multiply(int a, int b, const char* what);
// product for size_t, int, double vectors
[[nodiscard]] std::size_t product(const std::vector<std::size_t> vec, const char* what);
[[nodiscard]] std::size_t product(const std::vector<int>& vec, const char* what);
[[nodiscard]] Scalar product(const Vector vec, const char* what);
// dot and cross product
[[nodiscard]] Scalar dot_product(const Vector vec1, const Vector vec2, const char* what);
[[nodiscard]] Vector cross_product(const Vector vec1, const Vector vec2, const char* what);

} // namespace fnn::util
