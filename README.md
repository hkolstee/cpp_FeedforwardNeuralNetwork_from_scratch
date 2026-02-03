# FNN (WIP learning project)

This repository is a **work-in-progress** where I’m learning modern C++ by building a small neural network library (from scratch) for regression/classification.

The emphasis is:
- **I write the NN logic myself** (layers, losses, training, backprop, etc.)
- The repo provides **good C++ structure + best-practice guidance** so C++ doesn’t get in the way
- The codebase is expected to change as I learn and iterate

## Quick Start

### Build the library

```bash
cmake -S . -B build
cmake --build build
```

## What’s intentionally missing

- This is a learning repo: some parts are incomplete and may be refactored frequently.
- NN logic is implemented as I go; don’t expect stable APIs yet.

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
├── Makefile
├── include/
│   └── fnn/
│       ├── config.hpp
│       ├── fnn.hpp
│       ├── activation_func.hpp
│       ├── layer.hpp
│       ├── loss_func.hpp
│       └── model.hpp
├── src/
│   ├── activation_func.cpp
│   ├── layer.cpp
│   ├── loss_func.cpp
│   └── model.cpp
│   └── tensor*.cpp
└── docs/
    └── BEST_PRACTICES.md
```

## Best practices guide

See `docs/BEST_PRACTICES.md` for repo-specific conventions and the “C to C++” mindset shift notes.

## Contributing

This is a personal learning project; contributions are welcome but the primary goal is learning-by-implementing.

## License

This project is provided as-is for educational purposes.
