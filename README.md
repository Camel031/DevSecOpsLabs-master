# DevSecOps Labs

Lab exercises from a DevSecOps / systems security course. Each lab runs in an isolated Docker environment and focuses on a specific vulnerability class or systems programming concept.

## Labs Overview

| Lab | Topic | Language |
|-----|-------|----------|
| lab01-03 | Image file parsing — BMP and JPEG format analysis | C |
| lab04-05 | Memory management — heap allocation and leak analysis | C |
| lab06 | Buffer overflow and input validation vulnerabilities | C |
| lab07 | Multiple vulnerability classes: format string, use-after-free | C |

## Quick Start

Each lab is self-contained. Build and run using Docker:

```bash
# Example: run lab06
cd lab06
docker build -t lab06 .
docker run -it lab06

# Or compile directly (requires gcc)
make
./vulnerable
```

Lab07 includes a run script:

```bash
cd lab07
bash run.sh
```

## Lab Details

### lab01-03 — Image Parsing
Implements BMP and JPEG file format parsers from scratch in C. Covers binary I/O, struct layout, marker parsing, and the `qdbmp` library for BMP manipulation.

### lab04-05 — Memory Management
Minimal C programs demonstrating heap allocation patterns. Used as a baseline for static analysis tools (e.g. Valgrind, AddressSanitizer) to detect memory leaks and misuse.

### lab06 — Buffer Overflow
A text-processing utility (`vulnerable.c`) with intentional vulnerabilities:
- Heap buffer overflow via `malloc` undersizing
- Out-of-bounds write through unchecked length parameter
- Null pointer dereference easter egg

Build with ASan enabled for analysis:
```bash
CFLAGS="-g -fsanitize=address" make
```

### lab07 — Multiple Vulnerabilities
Demonstrates three common C vulnerability patterns in isolated functions:
- **Format string** — `printf(user_input)` without format specifier
- **Use-after-free** — accessing heap memory after `free()`
- Additional compound vulnerability scenarios

## Requirements

- Docker (recommended)
- gcc + make (for local builds)
- Optional: Valgrind or AddressSanitizer for dynamic analysis

## License

See [LICENSE](LICENSE).
