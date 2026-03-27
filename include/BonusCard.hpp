#ifndef BONUSCARD_HPP
#define BONUSCARD_HPP

#include "Card.hpp"

/// Represents a bonus Orbiter card that boosts mission scores
class BonusCard : public Card {
 private:
  std::string type;  // Type (e.g., "KJ Orbiter")

 public:
  /// Constructor
  explicit BonusCard(const std::string& name, const std::string& type);
  /// Get type
  std::string getType() const;

  /// Card info as text
  std::string toString() const override;
};

#endif
