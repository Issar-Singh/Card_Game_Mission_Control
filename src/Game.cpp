#include "Game.hpp"

#include <iostream>
#include <memory>

#include "AIPlayer.hpp"

// Constructor: initialize players and deck
Game::Game()
    : player1("Player 1"),  // Human player
      player2(std::make_unique<AIPlayer>(
          "AI Player")),  // AI player using unique_ptr
      turn(0) {
  // deck will be initialized separately in setup()
}

// Set up the game: shuffle deck and deal initial cards
void Game::setup() {
  deck.Shuffle();  // Shuffle the draw deck

  // Deal starting cards to each player
  player1.drawFromDeck(deck, 3);   // Human starts with 3 cards
  player2->drawFromDeck(deck, 3);  // AI starts with 3 cards
}

// Main game loop
void Game::play() {
  std::cout << "Starting Mission Control Card Game!" << std::endl;

  while (!isGameOver()) {
    std::cout << "------------------------" << std::endl;

    if (turn % 2 == 0) {
      // Human player's turn
      std::cout << "Human player's turn." << std::endl;
      player1.playRound(deck, *player2);
    } else {
      // AI player's turn
      std::cout << "AI player's turn." << std::endl;
      player2->playRound(deck, player1);
    }

    turn++;  // Next turn
  }

  // Game over, calculate scores
  player1.calculateScore();
  player2->calculateScore();

  announceWinner();
}

// Check if the game is over (deck is empty)
bool Game::isGameOver() const { return deck.IsEmpty(); }

// Announces the winner based on final scores
void Game::announceWinner() {
  int score1 = player1.getScore();
  int score2 = player2->getScore();

  std::cout << "\n===== Final Scores =====\n";
  std::cout << "Player 1: " << score1 << std::endl;
  std::cout << "AI Player: " << score2 << std::endl;

  std::cout << "\n===== Result =====\n";
  if (score1 > score2) {
    std::cout << "Player 1 wins!" << std::endl;
  } else if (score2 > score1) {
    std::cout << "AI Player wins!" << std::endl;
  } else {
    std::cout << "It's a tie!" << std::endl;
  }

  std::cout << "\nThank you for playing Mission Control!" << std::endl;
}
