/**
 * @file DrawDeck.cpp
 * @author Issar
 * @date 2025-10
 * @brief Implements the DrawDeck class using Nicole Wilson's random generator.
 */

#include "DrawDeck.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

#include "BonusCard.hpp"
#include "CrewCard.hpp"

DrawDeck::DrawDeck() : rng_(nullptr) {
  rng_ = RandomGenerator::getInstance();
  LoadCards();  // Load all cards when deck is created
}

DrawDeck::~DrawDeck() = default;

void DrawDeck::Shuffle() {
  if (cards_.empty()) {
    std::cerr << "Deck is empty! Cannot shuffle.\n";
    return;
  }

  for (int i = static_cast<int>(cards_.size()) - 1; i > 0; --i) {
    int j = rng_->getValue(i + 1);
    std::swap(cards_[i], cards_[j]);
  }
}

std::shared_ptr<Card> DrawDeck::DrawCard() {
  if (cards_.empty()) {
    std::cerr << "Deck is empty! Returning nullptr.\n";
    return nullptr;
  }

  int index = rng_->getValue(static_cast<int>(cards_.size()));
  auto drawn = cards_[index];
  cards_.erase(cards_.begin() + index);
  return drawn;
}

void DrawDeck::LoadCards() {
  // 16 Crew cards: 4 missions × 4 ranks
  const std::string missions[] = {"Mars Recon", "ISS Resupply", "Moon Far Side",
                                  "Ganymede Recon"};
  for (const auto& mission : missions) {
    for (int rank = 1; rank <= 4; ++rank) {
      std::string name =
          mission.substr(0, 1) + std::to_string(rank);  // e.g., M1, I2, etc.
      cards_.push_back(std::make_shared<CrewCard>(name, mission, rank));
    }
  }

  // 3 Orbiter bonus cards
  cards_.push_back(
      std::make_shared<BonusCard>("KJ Orbiter", "Katherine Johnson"));
  cards_.push_back(
      std::make_shared<BonusCard>("DV Orbiter", "Dorothy Vaughan"));
  cards_.push_back(std::make_shared<BonusCard>("MJ Orbiter", "Mary Jackson"));
}
