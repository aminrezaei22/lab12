# Arcade: Week 12 starter (S12)

A text-game arcade in C++20. This is the starting point for **Lab 12: Inheritance**. It contains the finished Blackjack from Lab 11 and the other three games. Every `play_*` function returns the game's score as an `int`, and the menu prints it.

## What is already here

| Part | Files | Notes |
| --- | --- | --- |
| Menu | `app/main.cpp`, `include/input.h`, `src/input.cpp` | Calls the four `play_*` functions and prints the score each returns |
| Hangman | `include/hangman.h`, `src/hangman.cpp`, `include/words.h` | Free functions. `play_hangman()` returns the score. |
| Dungeon | `include/dungeon.h`, `src/dungeon.cpp`, `room.*`, `player.*`, `item.*`, `direction.*` | Six rooms, items, a trap, text commands. `play_dungeon()` returns the score. |
| Blackjack | `include/blackjack.h`, `src/blackjack.cpp`, `card.*`, `deck.*`, `hand.*` | The finished game from Lab 11. `play_blackjack()` returns the final bankroll. |
| Minesweeper | `include/minesweeper.h`, `src/minesweeper.cpp`, `board.*` | `play_minesweeper()` returns the score. |
| Tests | `tests/` | Everything passes. Keep it that way. |
| **Lab 12** | *you create* `game.h`, `game.cpp`, and a header and source file for each derived class | See the lab page |
| Notes to fill in | `INHERITANCE_NOTES.md`, `GDB_LOG.md` | |

## Scores

| Game | Score |
| --- | --- |
| Hangman | `misses_left * 10 + word_length * 5` for a win, 0 for a loss |
| Dungeon | `10 * items_carried + health`, or 0 if the player died |
| Blackjack | the final bankroll |
| Minesweeper | squares revealed, plus 100 for a win |

## Build and run

```
cmake -S . -B build                  # Debug build, -g included
cmake --build build
./build/arcade
```

With AddressSanitizer (use a separate folder):

```
cmake -S . -B build-asan -DENABLE_ASAN=ON
cmake --build build-asan
./build-asan/arcade
```

Tests:

```
cd build && ctest --output-on-failure
```

The first run downloads GoogleTest with git unless `libgtest-dev` is installed. A new `.cpp` file in `src/` must also be added to the `arcade_lib` list in `CMakeLists.txt`.

## Rules

- No warnings under `-Wall -Wextra`.
- Allowed headers: `<iostream>`, `<iomanip>`, `<string>`, `<fstream>`, `<stdexcept>`, `<random>`. No standard containers, no `<algorithm>`, no `using namespace std;`.
- Naming: `underscore_separated` functions and variables, `Capitalized` types, private data members start with `m_`, enumerators are lowercase, no ALL_CAPS constants.
- Commit messages follow Conventional Commits, composed in the editor (not `-m`).
