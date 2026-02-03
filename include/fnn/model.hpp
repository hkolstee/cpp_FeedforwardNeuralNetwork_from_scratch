#pragma once

#include "config.hpp"

namespace fnn {

// Interface-only scaffolding (no implementation yet).
// Keep this minimal until you have a single end-to-end training path working.
class Model {
public:
    virtual ~Model() = default;

    [[nodiscard]] virtual Vector predict(const Vector& input) = 0;
};

} // namespace fnn
