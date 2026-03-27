#include "Card.hpp"

// Constructor
Card::Card(const std::string& n) : name(n) {}

// Virtual destructor
Card::~Card() = default;

// Return the card name
std::string Card::getName() const { return name; }
