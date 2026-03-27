#include "CrewCard.hpp"

#include <sstream>

#include "CrewCard.hpp"

// Constructor
CrewCard::CrewCard(const std::string& name, const std::string& mission,
                   int rank)
    : Card(name), mission(mission), rank(rank) {}

// Get mission
std::string CrewCard::getMission() const { return mission; }

// Get rank
int CrewCard::getRank() const { return rank; }

// Card info as text
std::string CrewCard::toString() const {
  std::ostringstream out;
  out << name << " - Mission: " << mission << ", Rank: " << rank;
  return out.str();
}
