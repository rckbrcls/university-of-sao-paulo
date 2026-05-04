# Introduction to Computer Science II

> Status: archived academic coursework.

This folder contains intermediate C programming assignments and exercises, including standalone algorithm programs and two Spotify dataset projects.

## Scope

- Project type: course folder with independent C programs and small Makefile-based projects.
- Main stack: C and Make.
- Shared runtime: none.
- Current status: archived study reference.

## Contents

| Path | Purpose |
| --- | --- |
| `CocktailSort.c` | Cocktail sort exercise. |
| `Corretor.c` | Correction/spell-check style exercise. |
| `FrequênciaNum.c` | Numeric-frequency exercise. |
| `Labirinto.c` | Maze-related exercise. |
| `MergeSort3Vias.c` | Three-way merge sort exercise. |
| `PrimeiraProva.c` | Exam-related C file. |
| `hash.c` | Hashing exercise. |
| `imagens.c` | Image-processing or image-data exercise. |
| `spotify.c` | Standalone Spotify-related C exercise. |
| `Spotify/` | Spotify dataset project with `Dataset.csv`, `main.c`, `spotify.c`, `spotify.h`, and `Makefile`. |
| `Spotify pt.2/` | Second Spotify dataset project with the same local structure and Makefile workflow. |

## Build Pattern

The Spotify projects include Makefiles:

```sh
cd introduction-to-computer-science-II/Spotify
make
```

Standalone files can be compiled directly when they do not require extra local data:

```sh
gcc introduction-to-computer-science-II/CocktailSort.c -o cocktail-sort
```

## Data Files

The Spotify projects include `Dataset.csv`. Keep each dataset next to its source files when compiling or running those assignments because the expected file path is assignment-specific.

## Notes

- No root runner exists for this course folder.
- No automated test suite was identified.
- File names and assignment structure are preserved from the original coursework.
