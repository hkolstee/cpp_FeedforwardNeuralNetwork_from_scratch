#include "fnn/util/math.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>

namespace fnn::util {

std::size_t multiply(std::size_t a, std::size_t b, const char* what) {
    // checked for max size
    if (a != 0 && b > (std::numeric_limits<std::size_t>::max() / a)) {
        throw std::length_error(what);
    }
    return a * b;
}

int multiply(int a, int b, const char* what) {
    // checked for max size
    if (a != 0 && b > (std::numeric_limits<int>::max() / a)) {
        throw std::length_error(what);
    }
    return a * b;
}

std::size_t product(const std::vector<std::size_t> dims, const char* what) {
    std::size_t p = 1;
    for (const auto d : dims) {
        p = multiply(p, d, what);
    }
    return p;
}

std::size_t product(const std::vector<int>& vec, const char* what) {
    std::size_t p = 1;
    for (const int x : vec) {
        if (x < 0) {
            throw std::invalid_argument(what);
        }
        p = multiply(p, static_cast<std::size_t>(x), what);
    }
    return p;
}

} // namespace fnn::util
