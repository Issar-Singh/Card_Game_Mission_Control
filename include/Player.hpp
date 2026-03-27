#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <string>
#include <vector>

#include "BonusCard.hpp"
#include "Card.hpp"
#include "CardSet.hpp"
#include "DrawDeck.hpp"
#include "Hand.hpp"

// Player class represents a human or AI player in the card game
class Player {
 protected:
  std::string name;           // Player's name
  Hand hand;                  // Player's hand of cards
  std::vector<CardSet> sets;  // Completed sets of cards
  int score;                  // Player's score

 public:
  // Constructor: creates a player with a given name
  Player(const std::string& playerName);

  // Virtual destructor for proper cleanup in subclasses
  virtual ~Player() = default;

  // Draw cards from the deck and add them to the player's hand
  void drawFromDeck(DrawDeck& deck, int numCards);

  // Ask an opponent for cards of a given type/value
  bool askForCard(Player& opponent, const std::string& byType,
                  const std::string& value);

  // Lay down a set of cards from the hand
  void layDownSet(const std::vector<std::shared_ptr<Card>>& cards);

  // Add a bonus card to an existing set
  void addBonusToSet(std::shared_ptr<BonusCard> bonus, int setIndex);

  // Calculate the player's total score from all sets
  void calculateScore();

  // Return the player's current score
  int getScore() const;

  // Return the player's name
  std::string getName() const;

  // Return reference to the player's hand
  Hand& getHand();

  // Return reference to all sets the player has laid down
  std::vector<CardSet>& getSets();

  // Virtual function to perform a player's turn (AI will override this)
  virtual void playRound(DrawDeck& deck, Player& opponent);
};

#endif
