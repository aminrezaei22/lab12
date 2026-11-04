# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

```
(gdb) break Hangman::Hangman      stop in the derived constructor
(gdb) run                         stops at hangman_game.cpp:5 before main's loop
(gdb) bt                          who called it
(gdb) step                        went into std::allocator for the "Hangman" string, not Game yet
(gdb) break Game::Game            so I set a breakpoint on the base constructor instead
(gdb) continue
(gdb) bt
(gdb) finish                      run until the base constructor returns
(gdb) break Hangman::~Hangman
(gdb) break Game::~Game
(gdb) continue                    typed 0 at the menu, then continued through each destructor stop
```

Backtrace inside `Hangman::Hangman` (paste it):

```
#0  Hangman::Hangman (this=0x7fffffffe970) at src/hangman_game.cpp:5
#1  0x0000555555557713 in main () at app/main.cpp:49
```

Backtrace inside `Game::Game` (paste it):

```
#0  Game::Game (this=0x7fffffffe970, title="Hangman") at src/game.cpp:8
#1  0x0000555555559059 in Hangman::Hangman (this=0x7fffffffe970) at src/hangman_game.cpp:5
#2  0x0000555555557713 in main () at app/main.cpp:49
```

Where `finish` returned to:

```
Run till exit from #0  Game::Game (this=0x7fffffffe970, title="Hangman") at src/game.cpp:8
0x0000555555559059 in Hangman::Hangman (this=0x7fffffffe970) at src/hangman_game.cpp:5
```

Back in the Hangman constructor, on the same line 5, right after `Game{"Hangman"}` in the initializer list. Same `this` in both frames, it is one object.

Order of destructor breakpoints when the program ended:

```
Game::~Game        called from Minesweeper::~Minesweeper
Game::~Game        called from Blackjack::~Blackjack
Game::~Game        called from Dungeon::~Dungeon
Hangman::~Hangman  called from main
Game::~Game        called from Hangman::~Hangman
```

Construction order and destruction order, as read from the backtraces:

Construction: main calls `Hangman::Hangman`, which calls `Game::Game` first, then finishes its own part. So base first, derived second. Destruction is the other way: `Hangman::~Hangman` runs first and calls `Game::~Game` last. The four objects are destroyed in reverse order of creation, minesweeper first and hangman last.

### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:
