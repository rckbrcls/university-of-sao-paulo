# Graphs

> Status: archived academic coursework.

This folder contains C implementations for graph exercises and final-project stages. Each subfolder is an independent assignment with its own source files and Makefile.

## Scope

- Project type: course folder with multiple standalone graph programs.
- Main stack: C and Make.
- Shared runtime: none.
- Current status: archived study reference.

## Project Catalog

| Path | Main files | Responsibility |
| --- | --- | --- |
| `Exercicio1/` | `erdosrenyi.c`, `erdosrenyi.h`, `main.c`, `Makefile` | Erdos-Renyi random graph exercise. |
| `Busca-em-largura(ex2)/` | `buscaLargura.c`, `buscaLargura.h`, `main.c`, `Makefile` | Breadth-first search exercise. |
| `Busca-em-profundidade(ex3.0)/` | `exercicio3a.c`, `exercicio3a.h`, `main.c`, `Makefile` | Depth-first search exercise. |
| `Busca-em-profundidade-2(ex3.1)/` | `exercicio3b.c`, `exercicio3b.h`, `main.c`, `Makefile` | Second depth-first search exercise. |
| `Dijkstra(ex4)/` | `exercicio4.c`, `exercicio4.h`, `main.c`, `Makefile` | Dijkstra shortest-path exercise. |
| `Prim(ex5)/` | `exercicio5.c`, `exercicio5.h`, `main.c`, `Makefile` | Prim minimum-spanning-tree exercise. |
| `Projeto-Final(parte1)/` | `parte1.c`, `parte1.h`, `main.c`, `Makefile` | Final project, part 1. |
| `Projeto-Final(parte2)/` | `parte2.c`, `parte2.h`, `main.c`, `Makefile` | Final project, part 2. |
| `Projeto-Final(parte3)/` | `parte3.c`, `parte3.h`, `main.c`, `Makefile` | Final project, part 3. |
| `Projeto-Final(parte4)/` | `parte4.c`, `parte4.h`, `main.c`, `Makefile` | Final project, part 4. |

## Build Pattern

Each subfolder owns its Makefile:

```sh
cd graphs/Dijkstra\(ex4\)
make
```

Several Makefiles include `val` and `run` targets, but their behavior is local to each assignment. Inspect the target before using it.

## Notes

- The final-project parts are stored as separate course deliverables, not as a unified library.
- Some graph exercises parse external graph-like input formats in their own source files.
- No automated test suite was identified for the folder.
