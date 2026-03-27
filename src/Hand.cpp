#include "Hand.hpp"

#include <iostream>

#include "Card.hpp"

void Hand::Display() const {
  if (cards_.empty()) {
    std::cout << "Your hand is empty.\n";
    return;
  }

  std::cout << "Your cards:\n";
  for (const auto& card : cards_) {
    std::cout << "- " << card->toString() << "\n";
  }
}

std::vector<std::shared_ptr<Card>> Hand::GiveCard(const std::string&,
                                                  const std::string& value) {
  std::vector<std::shared_ptr<Card>> given;

  auto it = cards_.begin();
  while (it != cards_.end()) {
    if ((*it)->getName().find(value) != std::string::npos) {
      given.push_back(*it);
      it = cards_.erase(it);
    } else {
      ++it;
    }
  }

  return given;
}
