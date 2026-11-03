# Lab 12 class diagram

```
                     +----------------------------+
                     | Game                       |
                     +----------------------------+
                     | - m_title : std::string  <>--- std::string (composition)
                     | - m_last_score : int       |
                     +----------------------------+
                     | + Game(title)              |
                     | + title()                  |
                     | + last_score()             |
                     | + play()                   |
                     | # set_score(score)         |
                     | # ask_play_again()         |
                     +----------------------------+
                        ^        ^        ^        ^      is-a (public inheritance)
                        |        |        |        |
   +--------------------+-+ +----+------+ +-------+------+ +-+-----------------+
   | Hangman              | | Dungeon   | | Blackjack    | | Minesweeper       |
   +----------------------+ +-----------+ +--------------+ +-------------------+
   | - m_times_played     | | same      | | same         | | same              |
   | + play()             | |           | |              | |                   |
   | + times_played()     | |           | |              | |                   |
   +----------------------+ +-----------+ +--------------+ +-------------------+
            |  uses              |  uses         |  uses             |  uses
            v                    v               v                   v
      play_hangman()      play_dungeon()   play_blackjack()   play_minesweeper()
```

Each derived class adds one int, m_times_played, and its play() calls the old play_* function, passes the score to set_score and adds one to m_times_played. The games keep their Deck, Board and Player inside the play_* functions, so the classes own nothing else.
