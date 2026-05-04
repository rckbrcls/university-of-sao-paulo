# Introduction to Computer Science I

> Status: archived academic coursework.

This folder contains foundational C programming exercises, classroom examples, assignment lists, and small projects for an introductory computer science course.

## Scope

- Project type: course folder with many independent C programs.
- Main stack: C.
- Shared runtime: none.
- Build system: no shared Makefile was identified in this folder.
- Current status: archived study reference.

## Folder Map

| Path | Contents |
| --- | --- |
| `Exercícios de aula/` | Classroom examples covering conditionals, loops, recursion, vectors, matrices, and simple math routines. |
| `Lista 1/` | Basic input/output and arithmetic exercises such as weighted averages, fuel consumption, age in days, and geometric calculations. |
| `Lista 2/` | Conditional logic exercises such as BMI, parity, triangle classification, salary adjustment, palindrome, and simple calculator programs. |
| `Lista 3/` | Looping and numeric-sequence exercises such as arithmetic/geometric progression, Fibonacci, primes, perfect numbers, and multiples. |
| `Lista 4/` | Vector and matrix exercises such as reverse order, transposition, determinant, subsequence, and Euclidean distance. |
| `Lista 5/` | String and date exercises such as substring, character counting, vowel removal, replacement, case conversion, and palindrome checks. |
| `Lista 6/` | File-handling and Caesar-cipher exercises. |
| `Lista 7/` | Additional classroom exercises. |
| `Lista 8/` | File and binary data practice, including `niver.c`, `niver.csv`, and `binario.bin`. |
| `Trabalhos/` | Larger assignments such as `Pacientes.c` and `flores.c`. |

## Usage

Most files are standalone C programs. Compile the target file directly:

```sh
gcc introduction-to-computer-science-I/Lista\ 2/IMC.c -o imc
```

Some programs expect standard input or local data files. When a file reads from disk, keep related files in the same assignment folder unless the source code says otherwise.

## Notes

- This folder preserves early programming practice and uses assignment names as the main organization system.
- There is no central test runner.
- File names and folder names are preserved from the original coursework.
