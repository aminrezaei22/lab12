#ifndef ARCADE_GAME_H
#define ARCADE_GAME_H

#include <string>

/// @file game.h
/// @brief The base class the four arcade games share.

/// One arcade game: a title and the score of the last play.
class Game {
public:
  /// @param title the name of the game
  explicit Game(std::string title);

  /// @return the name of the game
  const std::string &title() const;

  /// @return the score of the most recent play, 0 before the first play
  int last_score() const;

  /// Placeholder. Each derived class has its own play().
  void play();

protected:
  /// Record the score of a finished game.
  /// @param score the number the game logic returned
  void set_score(int score);

  /// Ask the player whether to play again.
  /// @return true if the answer starts with y
  bool ask_play_again() const;

private:
  std::string m_title;
  int m_last_score;
};

#endif // ARCADE_GAME_H
