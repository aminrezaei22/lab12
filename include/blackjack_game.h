#ifndef ARCADE_BLACKJACK_GAME_H
#define ARCADE_BLACKJACK_GAME_H

#include "game.h"

/// @file blackjack_game.h
/// @brief Blackjack as a Game.

/// Wraps play_blackjack() in a Game.
class Blackjack : public Game {
public:
  Blackjack();

  /// Play one game of Blackjack and record its score.
  void play();

  /// @return how many times play() has run
  int times_played() const;

private:
  int m_times_played;
};

#endif // ARCADE_BLACKJACK_GAME_H
