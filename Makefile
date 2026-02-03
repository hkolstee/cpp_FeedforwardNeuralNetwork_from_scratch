BUILD_DIR := build
CMAKE := cmake
CTEST := ctest

.PHONY: help configure build run test all clean rebuild

help:
	@echo "Targets:"
	@echo "  configure  - generate build files into ./$(BUILD_DIR)"
	@echo "  build      - build library + app + tests"
	@echo "  run        - run ./$(BUILD_DIR)/fnn_app"
	@echo "  test       - run ctest in ./$(BUILD_DIR)"
	@echo "  all        - build + run + test"
	@echo "  clean      - remove ./$(BUILD_DIR)"
	@echo "  rebuild    - clean + all"

configure:
	$(CMAKE) -S . -B $(BUILD_DIR)
	@# Optional but recommended: expose compile flags to clangd/IDE tooling.
	@# clangd commonly looks for `./compile_commands.json` at repo root.
	@ln -sf $(BUILD_DIR)/compile_commands.json compile_commands.json

build: configure
	$(CMAKE) --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/fnn_app

test: build
	$(CTEST) --test-dir $(BUILD_DIR)

all: run test

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all
