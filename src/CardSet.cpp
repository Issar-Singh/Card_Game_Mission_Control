#include "CardSet.hpp"

#include <memory>

#include "BonusCard.hpp"
#include "CrewCard.hpp"

int CardSet::getScore() const {
  int score = 0;
  bool hasOrbiter = false;

  for (const auto& card : cards_) {
    if (auto crew = std::dynamic_pointer_cast<CrewCard>(card)) {
      score += crew->getRank();
    } else if (std::dynamic_pointer_cast<BonusCard>(card)) {
      // Treat any BonusCard as an Orbiter (doubles the set).
      hasOrbiter = true;
    }
  }

  if (hasOrbiter) {
    score *= 2;
  }

  return score;
}
