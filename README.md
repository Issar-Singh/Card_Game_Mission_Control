# 🚀 Mission Control Card Game

Mission Control is a C++ card game project built using object-oriented programming principles. The game features a human player, an AI-controlled opponent, a shuffled draw deck, set-building mechanics, and score-based winner calculation.

This project also reflects my practical use of AI-assisted coding tools to improve development speed while maintaining control through step-by-step review and testing.

---

## 📌 Overview

This project was designed to practice modular C++ development by modeling cards, players, collections, hands, the draw deck, and overall game flow through separate classes.

The game includes:
- Human vs AI gameplay
- Crew and bonus cards
- Shuffled draw deck
- Turn-based actions
- Set creation and scoring
- Final winner announcement

---

## ✨ Features

- Object-oriented C++ design
- Modular class structure
- AI-controlled opponent
- Deck shuffling and card drawing
- Set-based scoring system
- Build and quality-check workflow with Makefile, cpplint, cppcheck, and valgrind

---

## 🛠️ Tech Stack

- C++
- C++14
- g++
- Makefile
- cpplint
- cppcheck
- valgrind

---

## 📂 Project Structure

```text
card-game-mission-control/
│
├── include/
│   ├── AIPlayer.hpp
│   ├── BonusCard.hpp
│   ├── Card.hpp
│   ├── CardSet.hpp
│   ├── Collection.hpp
│   ├── CrewCard.hpp
│   ├── DrawDeck.hpp
│   ├── Game.hpp
│   ├── Hand.hpp
│   └── Player.hpp
│
├── src/
│   ├── AIPlayer.cpp
│   ├── BonusCard.cpp
│   ├── Card.cpp
│   ├── CardSet.cpp
│   ├── Collection.cpp
│   ├── CrewCard.cpp
│   ├── DrawDeck.cpp
│   ├── Game.cpp
│   ├── Hand.cpp
│   └── Player.cpp
│
├── Makefile
├── CPPLINT.cfg
├── .gitlab-ci.yml
└── README.md
```
## ▶️ Build and Run

### Build
```bash
make
make static
make style
make memcheck
