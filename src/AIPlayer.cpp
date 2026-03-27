#include "AIPlayer.hpp"

#include <iostream>

#include "BonusCard.hpp"
#include "CrewCard.hpp"

// Creates an AI player with the given name
AIPlayer::AIPlayer(const std::string& name) : Player(name) {}

// Performs one full turn for the AI player
void AIPlayer::playRound(DrawDeck& deck, Player& opponent) {
  std::cout << "\n===== " << name << "'s Turn =====\n";

  static int turnCount = 1;

  if (turnCount % 2 == 1) {
    drawFromDeckStrategy(deck);
  } else if (turnCount % 4 == 0) {
    requestCardByRank(opponent);
  } else {
    requestCardByMission(opponent);
  }

  layDownSetsAutomatically();
  turnCount++;
}

// Draws 3 cards from the deck
void AIPlayer::drawFromDeckStrategy(DrawDeck& deck) {
  std::cout << "AI draws 3 cards from the deck.\n";
  drawFromDeck(deck, 3);
}

// Requests a card by rank from the opponent
void AIPlayer::requestCardByRank(Player& opponent) {
  if (hand.GetCards().empty()) return;

  std::shared_ptr<Card> firstCard = hand.GetCards().front();
  std::shared_ptr<CrewCard> crew =
      std::dynamic_pointer_cast<CrewCard>(firstCard);

  if (!crew) {
    std::cout << "AI has no CrewCard to request by rank.\n";
    return;
  }

  int rank = crew->getRank();
  std::cout << "AI requests a card of rank " << rank << " from opponent.\n";

  askForCard(opponent, "rank", std::to_string(rank));
}

// Requests a card by mission/type from the opponent
void AIPlayer::requestCardByMission(Player& opponent) {
  if (hand.GetCards().empty()) return;

  std::shared_ptr<Card> firstCard = hand.GetCards().front();
  std::shared_ptr<BonusCard> bonus =
      std::dynamic_pointer_cast<BonusCard>(firstCard);

  if (!bonus) {
    std::cout << "AI has no BonusCard to request by mission.\n";
    return;
  }

  std::string mission = bonus->getType();
  std::cout << "AI requests a card of mission " << mission
            << " from opponent.\n";

  askForCard(opponent, "mission", mission);
}

// Lays down possible sets automatically
void AIPlayer::layDownSetsAutomatically() {
  std::cout << "AI lays down all possible sets.\n";

  if (hand.GetCards().size() >= 2) {
    std::vector<std::shared_ptr<Card>> setCards;
    setCards.push_back(hand.GetCards()[0]);
    setCards.push_back(hand.GetCards()[1]);
    layDownSet(setCards);
  }
}
