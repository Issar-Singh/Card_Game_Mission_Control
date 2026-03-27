#include <iostream>

#include "Game.hpp"

int main() {
  std::cout << "Welcome to Mission Control Card Game!" << std::endl;

  // Create the game object
  Game game;

  // Set up the game: shuffle deck and deal initial cards
  game.setup();

  // Start the main game loop
  game.play();

  std::cout << "Thank you for playing Mission Control!" << std::endl;

  return 0;
}
