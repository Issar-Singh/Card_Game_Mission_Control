#ifndef HAND_HPP
#define HAND_HPP

#include <iostream>

#include "Collection.hpp"

class Hand : public Collection {
 public:
  Hand() = default;
  ~Hand() = default;

  // Displays all cards currently in the player's hand.
  void Display() const;

  // Removes and returns cards that match a specific property (rank or mission).
  std::vector<std::shared_ptr<Card>> GiveCard(const std::string& byType,
                                              const std::string& value);
};

#endif
