# Best Practices (for this repo)

This project is intentionally structured so you can **learn C++ by implementing the NN logic yourself** while still having a clean, real-world library setup.

## Repo layout rules

- **Public API in `include/`**: anything under `include/fnn/` is considered *stable* and “user-facing”.
- **Implementation in `src/`**: `.cpp` files should include the corresponding header and implement it.
- **Apps in `apps/`**: small executables that link the library and prove it builds.
- **Tests in `tests/`**: keep tests small and targeted; start with smoke tests, then add unit tests.

## Header hygiene (the C++ equivalent of keeping compilation sane)

- **Prefer `#pragma once`** in this repo.
- **Minimize includes in headers**:
  - Put heavy includes in `.cpp`.
  - Use forward declarations when you can.
- **Don’t put “real logic” in headers by default**:
  - Keep headers to declarations and small inline functions.
  - This speeds up rebuilds and reduces accidental coupling.

## Namespaces

- Everything public should live in `namespace fnn { ... }`.
- Avoid `using namespace` in headers.

## RAII + ownership (your biggest “C to C++” mindset shift)

- Prefer standard library types that manage memory:
  - `std::vector` for dynamic arrays/buffers
  - `std::string` for text
  - `std::unique_ptr` for owning polymorphic objects
- Avoid owning raw pointers (`T*` that you `new`/`delete`).
- Make destruction safe:
  - Destructors should usually be `noexcept`.
  - Don’t throw from destructors.

### Rule of 0 (default)

If your types only contain RAII members (`vector`, `string`, `unique_ptr`, etc.), then you usually **do not need** to define:
- destructor
- copy/move constructors
- copy/move assignment

Let the compiler generate them and move on.

## Const-correctness (treat this as API design)

- Mark read-only methods `const`.
- Pass heavy inputs as `const T&`.
- Return by value unless you have a clear performance reason not to.

## Error handling policy (pick one and be consistent)

Default recommendation for a learning library:
- Use **exceptions** for programmer errors and invalid states (e.g., shape mismatch).
- Use return-values for “expected” control flow only when it is truly expected.

If you later want a no-exceptions mode, you can add it—but don’t design for it prematurely.

## Build settings (what we optimize for)

- **C++20** (so you can learn modern language features).
- **Warnings enabled** (`-Wall -Wextra -Wpedantic` on GCC/Clang; `/W4` on MSVC).
- Keep builds out-of-source:
  - `cmake -S . -B build`
  - `cmake --build build`

## How to grow the library without painting yourself into a corner

- Start with a single working “vertical slice” (one model, one layer, one loss) in your own implementation.
- Keep interfaces small and stable; refactor implementations freely.
- Add tests as you add features:
  - first for math primitives
  - then for gradient checks
  - then for end-to-end training decreasing loss
