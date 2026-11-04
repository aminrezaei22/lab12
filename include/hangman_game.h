#ifndef ARCADE_HANGMAN_GAME_H
#define ARCADE_HANGMAN_GAME_H

#include "game.h"

/// @file hangman_game.h
/// @brief Hangman as a Game.

/// Wraps play_hangman() in a Game.
class Hangman : public Game {
public:
  Hangman();

  /// Play one game of Hangman and record its score.
  void play();

  /// @return how many times play() has run
  int times_played() const;

private:
  int m_times_played;
};

#endif // ARCADE_HANGMAN_GAME_H
