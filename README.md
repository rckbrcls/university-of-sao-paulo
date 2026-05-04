# University of Sao Paulo

> Status: archived academic repository.

This repository preserves coursework, exercises, assignments, prototypes, games, and study projects produced for University of Sao Paulo computer science subjects. It is not a single application, package, service, or monorepo with one shared build system. Each course folder should be read as an independent academic artifact with its own language, tooling, and level of completeness.

## Scope

- Repository type: medium-to-large academic archive.
- Project shape: collection of independent course folders and standalone assignments.
- Runtime model: no shared runtime, no root package manager, and no root build command.
- Main languages and platforms: C, C++, Java, Python, Haskell, Assembly, HTML/CSS/JavaScript/PHP, Next.js/React/TypeScript, and Unity/C#.
- Current status: archived for study and reference. Some folders include generated files, compiled binaries, old vendor assets, or historical setup assumptions.

## Course Catalog

| Path | Contents | Main stack |
| --- | --- | --- |
| `algorithms-and-data-structures/` | C data-structure assignments and projects, including stacks, queues, linked lists, skip lists, red-black trees, treaps, big-number routines, and binary-tree exercises. | C, Make |
| `file-organization/` | File organization exercises and practical assignments, including indexed file work, B-tree helpers, vehicle/line datasets, joins, and sorting routines. | C, Make |
| `functional-programming/` | A bowling-score assignment. | Haskell |
| `graphs/` | Graph algorithm exercises and final-project parts, including random graph generation, BFS, DFS, Dijkstra, Prim, and graph-processing stages. | C, Make |
| `human-computer-interaction/ihc-voe/` | Voe, an HCI travel-booking interface prototype built with Next.js and accessibility-oriented dependencies. | Next.js, React, TypeScript, MUI, Tailwind CSS |
| `introduction-to-computer-science-I/` | Foundational C exercises, classroom examples, lists, file-handling practice, and small assignments. | C |
| `introduction-to-computer-science-II/` | Intermediate C programs and Spotify dataset assignments with Makefiles. | C, Make |
| `introduction-to-the-theory-of-computation/finite-automaton/` | Deterministic finite automaton implementation, tests, report/manual material, and a packaged Windows executable. | Python |
| `introduction-to-video-game-development/Deathn't/` | Unity 2D game project with scenes, scripts, assets, URP settings, movement, rewind, possession, menus, and level progression. | Unity 2019.4.31f1, C# |
| `laboratoy-of-computer-science/` | Small introductory C programs stored as extensionless source files. | C |
| `object-oriented-programming/` | Java exercises and games, including Bozo dice game work, geometric/product inheritance exercises, and the Mar Profundo quiz-style project. | Java |
| `operating-systems/sleeping-barber-game/` | Sleeping-barber concurrency simulation/game. | C++, pthread, Make |
| `practice-in-computer-organization/jogo-da-memoria-assembly/` | Memory game implemented in assembly with simulator and memory initialization files. | Assembly, C simulator support, MIF |
| `web/MyPortfolio/` | Static BootstrapMade portfolio template copy with HTML pages, assets, vendor libraries, and a placeholder PHP contact form. | HTML, CSS, JavaScript, PHP |

The folder name `laboratoy-of-computer-science` is preserved as committed.

## Repository Structure

```text
university-of-sao-paulo/
├── algorithms-and-data-structures/
├── file-organization/
├── functional-programming/
├── graphs/
├── human-computer-interaction/
│   └── ihc-voe/
├── introduction-to-computer-science-I/
├── introduction-to-computer-science-II/
├── introduction-to-the-theory-of-computation/
│   └── finite-automaton/
├── introduction-to-video-game-development/
│   └── Deathn't/
├── laboratoy-of-computer-science/
├── object-oriented-programming/
├── operating-systems/
│   └── sleeping-barber-game/
├── practice-in-computer-organization/
│   └── jogo-da-memoria-assembly/
└── web/
    └── MyPortfolio/
```

## Prerequisites

Install only the tooling needed for the folder you want to inspect.

| Work area | Typical requirement |
| --- | --- |
| C assignments | `gcc` and `make` when a Makefile exists. |
| C++ operating-systems project | `g++`, `make`, and pthread support. |
| Java assignments | JDK with `javac` and `java`. |
| Python automaton | Python 3. The bundled Windows executable is separate from the source script. |
| Haskell assignment | GHC or another Haskell environment. |
| Next.js HCI project | Node.js and Yarn, based on the committed `yarn.lock`. |
| Unity game | Unity 2019.4.31f1, matching `ProjectSettings/ProjectVersion.txt`. |
| Static web portfolio | A browser; PHP only if testing `forms/contact.php`. |

## Working With This Archive

There is no root install step. Start from the course folder, then read its README if present.

For C and C++ folders with Makefiles:

```sh
cd algorithms-and-data-structures/Projeto\ 1
make
```

For single C files without Makefiles:

```sh
gcc introduction-to-computer-science-II/CocktailSort.c -o cocktail-sort
```

For the HCI project:

```sh
cd human-computer-interaction/ihc-voe
yarn
yarn dev
```

For the Unity project, open `introduction-to-video-game-development/Deathn't/` with Unity 2019.4.31f1.

These commands are examples for local use. The repository itself does not provide a root workflow that validates every course folder at once.

## Tests

Test coverage is fragmented:

- `introduction-to-the-theory-of-computation/finite-automaton/test.py` contains unit tests for the `FiniteAutomaton` class, although the file is missing its imports in the current codebase.
- `object-oriented-programming/Exercicio3/src/jogo/bozo/` includes Java test classes for the Bozo dice-game exercise.
- Many C assignments rely on manual input, Makefile targets, or course judge behavior rather than automated tests.
- No root test runner was identified.

## Data, APIs, Authentication, and Deployment

- Database: none identified. Persistent data appears as local files such as `.csv`, `.bin`, `.mif`, rankings, Unity assets, or generated artifacts.
- API: no shared API or backend contract exists.
- Authentication: the HCI Voe project includes login and signup screens, but no backend authentication flow was identified.
- Payments: the HCI Voe checkout screen is a UI prototype and should not be treated as a real payment integration.
- Deployment: no production deployment pipeline, CI workflow, Docker setup, or hosting configuration was identified for the repository as a whole.

## Generated and Legacy Artifacts

This archive intentionally contains historical material that would normally be excluded from an active software project:

- Unity generated folders such as `Library/`, `Logs/`, and `Temp - Copia/` are present under `introduction-to-video-game-development/Deathn't/`.
- Java `.class` files and generated Javadocs are present in object-oriented programming exercises.
- Compiled binaries are present, including Linux executables in `operating-systems/sleeping-barber-game/` and a Windows executable in `introduction-to-the-theory-of-computation/finite-automaton/executavel/`.
- `web/MyPortfolio/` includes vendor assets from the BootstrapMade template.

When updating the archive, preserve assignment context and avoid rewriting historical project structure as if it were an active production codebase.

## Documentation Map

Focused README files exist only where they add useful orientation:

- `algorithms-and-data-structures/README.md`
- `file-organization/README.md`
- `graphs/README.md`
- `human-computer-interaction/ihc-voe/README.md`
- `introduction-to-computer-science-I/README.md`
- `introduction-to-computer-science-II/README.md`
- `introduction-to-the-theory-of-computation/finite-automaton/README.md`
- `introduction-to-video-game-development/Deathn't/README.md`
- `object-oriented-programming/README.md`
- `operating-systems/sleeping-barber-game/README.md`
- `practice-in-computer-organization/jogo-da-memoria-assembly/README.md`
- `web/MyPortfolio/README.md`

No separate `docs/` directory is used because the repository does not have a unified architecture, API, database, deployment flow, or contribution process.

## License

No repository-level license file was identified. Some copied or generated third-party materials may carry their own licenses, such as the BootstrapMade template notes in `web/MyPortfolio/Readme.txt` and bundled runtime/license files in packaged artifacts.
