#pragma once

#include "config.hpp"

namespace fnn {

// Interface-only scaffolding (no implementation yet).
// You can implement MSE, cross-entropy, etc. later.
class LossFunction {
public:
    virtual ~LossFunction() = default;

    // Compute loss given a prediction and a target.
    [[nodiscard]] virtual Scalar forward(const Vector& y_pred, const Vector& y_true) const = 0;

    // Gradient of the loss w.r.t. prediction (dL/dy_pred).
    [[nodiscard]] virtual Vector backward(const Vector& y_pred, const Vector& y_true) const = 0;
};

} // namespace fnn
