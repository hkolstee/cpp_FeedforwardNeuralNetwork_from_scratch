# FNN (learning skeleton)

This repo is a **C++20 compiled-library skeleton** for a from-scratch feedforward neural network project.

The goal is to give you a clean, real-world setup (build, layout, docs) while you implement the actual NN logic yourself.

## Quick Start

### Build and Run the smoke app

```bash
cmake -S . -B build
cmake --build build
./build/fnn_app
```

### Include the library in code

```cpp
#include <fnn/fnn.hpp>

int main() {
    fnn::ExampleComponent c{"hello"};
    c.process();
    return 0;
}
```

## What’s intentionally missing

- The actual NN logic (layers, training, backprop) is **left for you to implement**.
- The interfaces under `include/fnn/` are **scaffolding** with TODOs.

## Dependencies

- C++20 compatible compiler
- Standard Library only (no external dependencies)

## Building

### CMake (Recommended)

```bash
cmake -S . -B build
cmake --build build
```

#### Build Options

- **Build shared library**: `cmake -S . -B build -DFNN_BUILD_SHARED=ON`

## Project Structure

```
├── CMakeLists.txt
├── README.md
├── CppCheatsheet.md
├── CppCheatsheet.pdf
├── include/
│   └── fnn/
│       ├── config.hpp
│       ├── fnn.hpp
│       ├── activation_func.hpp
│       ├── layer.hpp
│       ├── loss_func.hpp
│       └── model.hpp
├── src/
│   ├── component.cpp
│   ├── activation_func.cpp
│   ├── layer.cpp
│   ├── loss_func.cpp
│   └── model.cpp
├── apps/
│   └── main.cpp
├── tests/
│   └── test_smoke.cpp
└── docs/
    └── BEST_PRACTICES.md
```

## Best practices guide

See `docs/BEST_PRACTICES.md` for repo-specific conventions and the “C to C++” mindset shift notes.

## Contributing

This is a learning project. The neural network implementation is in the header file and can be extended with additional features.

## License

This project is provided as-is for educational purposes.
