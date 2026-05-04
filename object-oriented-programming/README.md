# Object-Oriented Programming

> Status: archived academic coursework.

This folder contains Java exercises, games, generated class files, generated Javadocs, and a larger quiz-style project from object-oriented programming coursework.

## Scope

- Project type: course folder with multiple independent Java assignments.
- Main stack: Java.
- Shared build system: none identified.
- Current status: archived study reference.

## Project Catalog

| Path | Purpose |
| --- | --- |
| `Exercício1/` | Introductory Java exercise with `PrimeiraQuestao.java`, `SegundaQuestao.java`, and `EntradaTeclado.java`. |
| `Exercicio2/` | Multiple OOP exercises, including people/agenda classes, geometric figures, products, and inheritance/polymorphism examples under `exercicios/`. |
| `JogoDeBozo/` | Bozo dice-game implementation with source files, compiled classes, and generated Javadocs. |
| `Exercicio3/` | Packaged Bozo exercise under `src/jogo/bozo/`, including test classes such as `DadoTest.java`, `PlacarTest.java`, and `RolaDadosTest.java`. |
| `mar-profundo/` | Larger Java quiz-style project with screens, ranking/score files, CSV datasets, and image assets. |

## Notable Modules

### Bozo Dice Game

`JogoDeBozo/src/` and `Exercicio3/src/jogo/bozo/` contain dice-game classes such as `Bozo`, `Dado`, `Placar`, `Random`, and `RolaDados`. `JogoDeBozo/doc/` contains generated Javadocs.

### Mar Profundo

`mar-profundo/` includes Swing-style screen classes such as `TelaInicial.java`, `TelaNome.java`, `TelaCategoria.java`, `TelaPergunta.java`, and `TelaPlacar.java`. Supporting classes include `Pergunta.java`, `DeckDePerguntas.java`, `Ranking.java`, `Placar.java`, and `Arquivos.java`. Data and assets live under `Datasets/`, `view/`, `placar.csv`, and `ranking.txt`.

## Build Pattern

No shared Makefile, Gradle project, Maven project, or root Java build configuration was identified. Compile individual assignments with `javac` from the relevant folder when needed:

```sh
cd object-oriented-programming/JogoDeBozo/src
javac *.java
```

## Tests

`object-oriented-programming/Exercicio3/src/jogo/bozo/` includes Java test classes, but the current codebase does not include a build tool configuration that wires them into a repeatable test command.

## Notes

- Compiled `.class` files are committed in several folders as historical artifacts.
- Generated Javadocs are committed in `JogoDeBozo/doc/`.
- Keep each assignment isolated when making changes; there is no shared package boundary across the whole folder.
