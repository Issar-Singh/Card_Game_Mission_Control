#include "Collection.hpp"

#include <iostream>

// Adds a card to the collection.
void Collection::AddCard(std::shared_ptr<Card> card) { cards_.push_back(card); }

// Removes a specific card (returns true if found and removed).
bool Collection::RemoveCard(const std::shared_ptr<Card>& card) {
  for (auto it = cards_.begin(); it != cards_.end(); ++it) {
    if (*it == card) {  // Compares the actual Card objects
      cards_.erase(it);
      return true;
    }
  }
  return false;
}

// Returns true if the collection is empty.
bool Collection::IsEmpty() const { return cards_.empty(); }

// Returns number of cards in the collection.
int Collection::Size() const { return static_cast<int>(cards_.size()); }

// Clears all cards.
void Collection::Clear() { cards_.clear(); }

// Returns const reference to internal cards.
const std::vector<std::shared_ptr<Card>>& Collection::GetCards() const {
  return cards_;
}
