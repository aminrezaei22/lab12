# Inheritance notes

Answer in your own words. Use your GDB log for the constructor and destructor order.

## 1. Overriding or hiding?

`Game *g = &hangman; g->play();` What printed?

Is the derived `play()` overriding or hiding the base `play()`? How would a call through a `Game *` show you which one it is?

## 2. Slicing

`Game copy = hangman;` What was lost? Explain slicing.

## 3. protected

What does `protected` allow that `private` does not? Why is `set_score` `protected` instead of `public`?

## 4. Procedural versus object-oriented Hangman

Four bullets comparing your Week 1 procedural Hangman with the class version:

- Where the data lives:
- Who can change it:
- How you would add a second Hangman variant:
- How you would test it:
