# File Organization

> Status: archived academic coursework.

This folder contains C exercises and practical assignments for a file organization course. The projects focus on structured file processing, indexing, B-tree helpers, and record manipulation.

## Scope

- Project type: course folder with independent C assignments.
- Main stack: C and Make.
- Shared runtime: none.
- Current status: archived study reference.

## Project Catalog

| Path | Main files | Responsibility |
| --- | --- | --- |
| `Exercicio1/` | `exercicio1.c`, `exercicio1.h`, `main.c`, `Makefile` | First file-organization exercise. |
| `Exercicio2/` | `exercicio2.c`, `exercicio2.h`, `main.c`, `Makefile` | Second file-organization exercise. |
| `Exercicio3/` | `exercicio3.c`, `exercicio3.h`, `main.c`, `Makefile` | Third file-organization exercise. |
| `Trabalho-Pratico1/` | `exercicio3.c`, `exercicio3.h`, `main.c`, `Makefile` | First practical assignment. |
| `Trabalho-Pratico2/` | `dados.h`, `arvoreb.c`, `auxiliares.c`, `veiculo.c`, `linha.c`, `main.c`, `Makefile` | Practical assignment with B-tree, vehicle, line, and helper modules. |
| `Trabalho-Pratico3/` | `dados.h`, `arvoreb.c`, `juncaoEordenacao.c`, `auxiliares.c`, `veiculo.c`, `linha.c`, `main.c`, `Makefile` | Practical assignment extending the data-processing workflow with join/sort routines. |

## Build Pattern

Each assignment has a local Makefile:

```sh
cd file-organization/Trabalho-Pratico2
make
```

Executables are local to each folder. Some assignments build `exec`; later practical assignments build `programaTrab`.

## Notes

- There is no shared database or ORM. The assignments operate on local files and records.
- Keep generated data files and input files close to the assignment that expects them.
- No automated test suite was identified.
