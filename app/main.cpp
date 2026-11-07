/// @file main.cpp
/// @brief The Arcade menu

#include <iostream>
#include <string>

#include "blackjack.h"
#include "dungeon.h"
#include "hangman.h"
#include "input.h"
#include "minesweeper.h"

namespace {
enum class Choice { hangman, dungeon, blackjack, minesweeper, quit, invalid };

void print_menu() {
  std::cout << "\n=== ARCADE ===\n"
            << "1. Hangman\n"
            << "2. Dungeon\n"
            << "3. Blackjack\n"
            << "4. Minesweeper\n"
            << "0. Quit\n";
}

void report_score(int score) { std::cout << "Score: " << score << "\n"; }

Choice parse_choice(const std::string &text) {
  if (text == "1") {
    return Choice::hangman;
  }
  if (text == "2") {
    return Choice::dungeon;
  }
  if (text == "3") {
    return Choice::blackjack;
  }
  if (text == "4") {
    return Choice::minesweeper;
  }
  if (text == "0") {
    return Choice::quit;
  }
  return Choice::invalid;
}

} // namespace

int main() {
  std::string line;
  while (true) {
    print_menu();
    if (!prompt_line("Choose: ", line)) {
      break; // input ended
    }
    const Choice choice{parse_choice(line)};
    if (choice == Choice::quit) {
      break;
    }
    switch (choice) {
    case Choice::hangman:
      report_score(play_hangman());
      break;
    case Choice::dungeon:
      report_score(play_dungeon());
      break;
    case Choice::blackjack:
      report_score(play_blackjack());
      break;
    case Choice::minesweeper:
      report_score(play_minesweeper());
      break;
    case Choice::quit:
      break;
    case Choice::invalid:
      std::cout << "Please enter 1-4, or 0 to quit.\n";
      break;
    }
  }
  std::cout << "Goodbye.\n";
  return 0;
}
