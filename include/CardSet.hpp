#ifndef CARDSET_HPP
#define CARDSET_HPP

#include <memory>

#include "Collection.hpp"

class CardSet : public Collection {
 public:
  // Calculates the total score of the card set.
  int getScore() const;
};

#endif
