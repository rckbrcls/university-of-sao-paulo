# Algorithms and Data Structures

> Status: archived academic coursework.

This folder contains C assignments and projects for an algorithms and data structures course. Each subfolder is an independent exercise or project, usually built with a local Makefile and a small group of `.c` and `.h` files.

## Scope

- Project type: course folder with multiple standalone C programs.
- Main stack: C and Make.
- Shared runtime: none.
- Root workflow: none.
- Current status: archived study reference.

## Project Catalog

| Path | Main files | Responsibility |
| --- | --- | --- |
| `Pilha-jogo-de-cartas/` | `pilha.c`, `pilha.h`, `main.c`, `Makefile` | Stack implementation used in a card-game exercise. |
| `Trabalho 3/` | `fila.c`, `fila.h`, `main.c`, `Makefile` | Queue-based assignment. |
| `Trabalho 4/` | `lista.c`, `lista.h`, `main.c`, `Makefile` | Linked-list assignment. |
| `Trabalho 5/` | `backward.c`, `backward.h`, `main.c`, `Makefile` | Backward-processing assignment. |
| `trabalho 6/` | `grandesNum.c`, `grandesNum.h`, `main.c`, `Makefile` | Big-number routines. |
| `trabalho 7/` | `arvoreBinaria.c`, `arvoreBinaria.h`, `main.c`, `Makefile` | Binary-tree assignment. |
| `Projeto 1/` | `skipList.c`, `skipList.h`, `main.c`, `Makefile` | Skip-list project. |
| `Projeto 2/` | `rubronegra.c`, `rubronegra.h`, `main.c`, `Makefile` | Red-black tree project. |
| `Projeto 3/` | `treaps.c`, `treaps.h`, `main.c`, `Makefile` | Treap project. |
| `Substituição/` | `substring.c`, `substring.h`, `main.c`, `Makefile` | String-substitution exercise. |

## Build Pattern

Most subfolders include a Makefile that compiles an executable named `exec`; `Substituição/` builds `sub`.

```sh
cd algorithms-and-data-structures/Projeto\ 1
make
```

Some Makefiles also define a `run` target, but target behavior is not consistent across all assignments. Inspect the local Makefile before using it.

## Notes

- There is no shared library between assignments.
- Header/source pairs are local to each subfolder.
- The code reflects course exercises and should be read in the context of each assignment rather than as one integrated data-structures package.
- No automated test suite was identified for this folder.
