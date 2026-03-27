#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <memory>
#include <vector>

#include "Card.hpp"

class Collection {
 public:
  Collection() = default;
  virtual ~Collection() = default;

  // Add a card to the collection.
  virtual void AddCard(std::shared_ptr<Card> card);

  // Remove a specific card (returns true if found and removed).
  virtual bool RemoveCard(const std::shared_ptr<Card>& card);

  // Returns true if collection is empty.
  virtual bool IsEmpty() const;

  // Returns number of cards in the collection.
  virtual int Size() const;

  // Clears all cards.
  virtual void Clear();

  // Returns const reference to internal cards.
  virtual const std::vector<std::shared_ptr<Card>>& GetCards() const;

 protected:
  std::vector<std::shared_ptr<Card>> cards_;
};

#endif
