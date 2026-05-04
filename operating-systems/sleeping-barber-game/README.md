# Sleeping Barber Game

> Status: archived academic coursework.

This project implements a sleeping-barber concurrency simulation/game for an operating systems course. It uses C++ and POSIX threads/semaphores through a local Makefile.

## Scope

- Project type: standalone operating-systems assignment.
- Main stack: C++, pthread, Make.
- Current status: archived study reference.

## Files

| Path | Purpose |
| --- | --- |
| `game.cpp` | Main program entry and simulation/game flow. |
| `barber.cpp`, `barber.h` | Barber-specific behavior and declarations. |
| `semaphore.cpp`, `semaphore.h` | Semaphore wrapper/support code. |
| `Makefile` | Local build, debug, valgrind, run, and zip targets. |
| `barber_example.txt` | Example input/output or reference material for the assignment. |
| `game`, `teste` | Committed Linux executables from earlier builds. |

## Build Pattern

The Makefile compiles with `g++`, warnings enabled, debug symbols, and pthread support:

```sh
cd operating-systems/sleeping-barber-game
make
```

Available Makefile targets identified in the current file:

| Target | Purpose |
| --- | --- |
| `all` | Compiles the project. |
| `debug` | Builds and runs with `gdb`. |
| `valgrind` | Builds and runs with Valgrind. |
| `run` | Builds and runs the project executable. |
| `zip` | Builds and creates a zip package. |

## Notes

- The committed `game` and `teste` files are Linux ELF executables and may not run on other platforms.
- No automated test suite was identified.
- This project is independent from the rest of the repository.
