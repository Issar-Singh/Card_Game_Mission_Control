#ifndef CREWCARD_HPP
#define CREWCARD_HPP

#include "Card.hpp"

/// Represents a crew member card with a mission and rank
class CrewCard : public Card {
 private:
  std::string mission;  // Mission name (e.g., "Mars Recon")
  int rank;             // Rank number (1–4)

 public:
  /// Constructor
  explicit CrewCard(const std::string& name, const std::string& mission,
                    int rank);

  /// Get mission
  std::string getMission() const;

  /// Get rank
  int getRank() const;

  /// Card info as text
  std::string toString() const override;
};

#endif
