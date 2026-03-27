#include "Player.hpp"

#include <iostream>

// Creates a player with a given name
Player::Player(const std::string& playerName) : name(playerName), score(0) {}

// Draws a set number of cards from the deck
void Player::drawFromDeck(DrawDeck& deck, int numCards) {
  for (int i = 0; i < numCards; i++) {
    if (!deck.IsEmpty()) {
      std::shared_ptr<Card> card = deck.DrawCard();
      if (card) hand.AddCard(card);
    }
  }
}

// Asks an opponent for cards of a given type and value
bool Player::askForCard(Player& opponent, const std::string& byType,
                        const std::string& value) {
  bool success = false;

  std::vector<std::shared_ptr<Card>> given =
      opponent.getHand().GiveCard(byType, value);

  if (!given.empty()) {
    success = true;
    for (auto& card : given) {
      hand.AddCard(card);
    }
  }

  return success;
}

// Lays down a set of cards from the hand
void Player::layDownSet(const std::vector<std::shared_ptr<Card>>& cards) {
  CardSet newSet;
  for (auto& card : cards) {
    newSet.AddCard(card);
    hand.RemoveCard(card);
  }
  sets.push_back(newSet);
}

// Adds a bonus card to an existing set
void Player::addBonusToSet(std::shared_ptr<BonusCard> bonus, int setIndex) {
  if (setIndex >= 0 && setIndex < static_cast<int>(sets.size())) {
    sets[setIndex].AddCard(bonus);
  }
}

// Calculates the total score from all sets
void Player::calculateScore() {
  score = 0;
  for (auto& set : sets) {
    score += set.getScore();
  }
}

// Returns the player's current score
int Player::getScore() const { return score; }

// Returns the player's name
std::string Player::getName() const { return name; }

// Returns a reference to the player's hand
Hand& Player::getHand() { return hand; }

// Returns a reference to all sets the player has laid down
std::vector<CardSet>& Player::getSets() { return sets; }

// Plays one round for the player
void Player::playRound(DrawDeck& deck, Player& opponent) {
  std::cout << "\n===== " << name << "'s Turn =====\n";
  std::cout << "Human player turn logic should be implemented here.\n";
}
