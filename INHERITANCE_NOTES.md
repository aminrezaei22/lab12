# Inheritance notes

Answer in your own words. Use your GDB log for the constructor and destructor order.

## 1. Overriding or hiding?

`Game *g = &hangman; g->play();` What printed?

`Game::play called`. Hangman did not run.

Is the derived `play()` overriding or hiding the base `play()`? How would a call through a `Game *` show you which one it is?

Hiding. `play()` is not virtual, so the compiler picks the function from the pointer type, which is `Game`. That is exactly how the call through `Game *` shows it: if it were overriding, `g->play()` would have started a Hangman game instead of printing the base message.

## 2. Slicing

`Game copy = hangman;` What was lost? Explain slicing.

`copy` is a plain `Game`. It kept the title "Hangman" and the last score, but `m_times_played` and `Hangman::play()` are gone, and `copy.play()` prints the base message. Copying a derived object into a base variable only copies the base part, the derived part is cut off. That is slicing.

## 3. protected

What does `protected` allow that `private` does not? Why is `set_score` `protected` instead of `public`?

Private members can only be used inside `Game`. Protected members can also be used inside the derived classes, but not from main. `set_score` is protected so only a game can record its own score. If it were public, main or anything else could write a fake score.

Copy constructor and destructor: the derived classes only hold an int and `Game` only holds a string and an int, nothing is allocated with `new`, so the compiler-generated copy and destructor already do the right thing.

## 4. Procedural versus object-oriented Hangman

Four bullets comparing your Week 1 procedural Hangman with the class version:

- Where the data lives: in Week 1 the word, guesses and misses were local variables in main or passed around as parameters. Now the score lives inside the object (`m_last_score` in `Game`, `m_times_played` in `Hangman`) and stays there after the game ends.
- Who can change it: in Week 1 any function that got the variables could change them. Now only `Game` can touch `m_last_score`, and a derived class can only change it through `set_score`.
- How you would add a second Hangman variant: in Week 1 I would copy the function and edit it. Now I write another class that inherits from `Game`, chains the constructor with a new title and writes its own `play()`. The menu code does not change.
- How you would test it: in Week 1 I had to play the game by hand. Now a test can build a `Hangman`, check `title()` and `last_score()` start at "Hangman" and 0, and check `times_played()` goes up after `play()`.
