#ifndef DRAWDECK_HPP
#define DRAWDECK_HPP

#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "Card.hpp"

/// Singleton random generator (Nicole Wilson’s concept)
class RandomGenerator {
 public:
  // Returns the single instance of RandomGenerator (thread-safe and leak-free)
  static RandomGenerator* getInstance() {
    static RandomGenerator instance;  // Meyers Singleton
    return &instance;
  }

  // Returns a random integer between 0 and max - 1
  int getValue(int max) {
    std::uniform_int_distribution<int> dist(0, max - 1);
    return dist(_generator);
  }

 private:
  RandomGenerator() {
    _seed = static_cast<unsigned int>(time(nullptr));
    _generator.seed(_seed);
  }

  ~RandomGenerator() = default;

  unsigned int _seed;
  std::default_random_engine _generator;
};

/// Represents the deck of cards used for drawing and shuffling
class DrawDeck {
 private:
  std::vector<std::shared_ptr<Card>> cards_;  // All cards in the deck
  RandomGenerator* rng_;                      // Random number generator

  /// Loads all Crew and Orbiter cards into the deck
  void LoadCards();

 public:
  /// Constructor initializes RNG and loads cards
  DrawDeck();

  /// Destructor
  ~DrawDeck() = default;

  /// Shuffle the deck using the random generator
  void Shuffle();

  /// Draw a random card from the deck
  std::shared_ptr<Card> DrawCard();

  /// Returns true if the deck is empty
  bool IsEmpty() const { return cards_.empty(); }

  /// Returns total number of cards
  int Size() const { return static_cast<int>(cards_.size()); }
};

#endif
