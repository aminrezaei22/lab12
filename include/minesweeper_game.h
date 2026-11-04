#ifndef ARCADE_MINESWEEPER_GAME_H
#define ARCADE_MINESWEEPER_GAME_H

#include "game.h"

/// @file minesweeper_game.h
/// @brief Minesweeper as a Game.

/// Wraps play_minesweeper() in a Game.
class Minesweeper : public Game {
public:
  Minesweeper();

  /// Play one game of Minesweeper and record its score.
  void play();

  /// @return how many times play() has run
  int times_played() const;

private:
  int m_times_played;
};

#endif // ARCADE_MINESWEEPER_GAME_H
