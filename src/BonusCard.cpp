#include "BonusCard.hpp"

#include <sstream>

// Constructor
BonusCard::BonusCard(const std::string& name, const std::string& type)
    : Card(name), type(type) {}

// Get type
std::string BonusCard::getType() const { return type; }

// Card info as text
std::string BonusCard::toString() const {
  std::ostringstream out;
  out << name << " (Orbiter Type: " << type << ")";
  return out.str();
}
