#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include <memory>

#include "DrawDeck.hpp"
#include "Player.hpp"

// AIPlayer class represents a computer-controlled player
// It inherits from Player and overrides playRound() to implement AI actions
class AIPlayer : public Player {
 public:
  // Constructor: set the AI player's name
  AIPlayer(const std::string& name);

  // Perform one turn for the AI player
  void playRound(DrawDeck& deck, Player& opponent) override;

 private:
  // Helper methods for AI strategy:
  // Draw cards from the deck automatically

  void drawFromDeckStrategy(DrawDeck& deck);

  // Ask the opponent for a card matching a rank

  void requestCardByRank(Player& opponent);

  // Ask the opponent for a card matching a mission

  void requestCardByMission(Player& opponent);

  // Lay down all possible sets automatically

  void layDownSetsAutomatically();
};

#endif
