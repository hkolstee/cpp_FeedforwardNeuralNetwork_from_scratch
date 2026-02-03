#pragma once

#include "config.hpp"

namespace fnn {

// You can implement concrete activations later (Sigmoid/ReLU/etc.).
class ActivationFunction {
public:
    virtual ~ActivationFunction() = default;

    // Compute activation for a scalar.
    [[nodiscard]] virtual Scalar forward(Scalar x) const = 0;

    // Compute derivative with respect to input x (common for backprop).
    [[nodiscard]] virtual Scalar derivative(Scalar x) const = 0;
};

} // namespace fnn
