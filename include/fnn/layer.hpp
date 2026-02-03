#pragma once

#include "config.hpp"

namespace fnn {

// Interface-only scaffolding (no implementation yet).
// This is a minimal OO boundary you can evolve as you implement backprop.
class Layer {
public:
    virtual ~Layer() = default;

    // Forward pass.
    [[nodiscard]] virtual Vector forward(const Vector& input) = 0;

    // Backward pass: returns gradient w.r.t. input.
    [[nodiscard]] virtual Vector backward(const Vector& d_output) = 0;
};

} // namespace fnn
