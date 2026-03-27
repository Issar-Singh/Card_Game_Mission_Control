#ifndef CARD_HPP
#define CARD_HPP

#include <string>

/// Base class for all cards (Crew and Bonus)
class Card {
 protected:
  std::string name;  // Card name (e.g., "KJ Orbiter", "Mars-1")

 public:
  /// Constructor
  explicit Card(const std::string& n);

  /// Virtual destructor
  virtual ~Card();

  /// Returns the card name
  std::string getName() const;

  /// Returns a string version of the card details
  virtual std::string toString() const = 0;
};

#endif
