#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <memory>

#include "AIPlayer.hpp"
#include "DrawDeck.hpp"
#include "Player.hpp"

// The Game class controls the flow of the Mission Control card game.
// It manages the players, the deck, turn-taking, and determines the winner.

class Game {
 private:
  Player player1;  // Human player
  std::unique_ptr<Player>
      player2;  // AI player (using pointer for polymorphism)
  DrawDeck deck;
  int turn;

 public:
  // Constructor: initializes players and sets turn counter
  Game();

  // Prepares the game: initializes and shuffles the deck
  void setup();

  // Runs the game loop: alternates turns between Player 1 and Player 2
  void play();

  // Checks if the game should end (deck is empty)
  bool isGameOver() const;

  // Prints the final scores and declares the w
  // Prints the final scores and declares the winner
  void announceWinner();
};

#endif
