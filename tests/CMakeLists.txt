# GoogleTest: Use the system copy if there is one, otherwise download it.
find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        GIT_SHALLOW TRUE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    set(gtest_main_target gtest_main)
else()
    set(gtest_main_target GTest::gtest_main)
endif()

include(GoogleTest)

# Minesweeper board.
add_executable(minesweeper_tests test_board.cpp)
target_link_libraries(minesweeper_tests PRIVATE arcade_lib ${gtest_main_target})
gtest_discover_tests(minesweeper_tests)

# Game scores (every play_* function returns a score).
add_executable(score_tests test_scores.cpp)
target_link_libraries(score_tests PRIVATE arcade_lib ${gtest_main_target})
gtest_discover_tests(score_tests)

# Lab 10: Deck. Finished.
add_executable(deck_tests test_deck.cpp)
target_link_libraries(deck_tests PRIVATE arcade_lib ${gtest_main_target})
gtest_discover_tests(deck_tests)

# Lab 11: Card operators and Hand. Finished.
add_executable(hand_tests test_hand.cpp)
target_link_libraries(hand_tests PRIVATE arcade_lib ${gtest_main_target})
gtest_discover_tests(hand_tests)

# Blackjack game rules.
add_executable(blackjack_tests test_blackjack.cpp)
target_link_libraries(blackjack_tests PRIVATE arcade_lib ${gtest_main_target})
gtest_discover_tests(blackjack_tests)
