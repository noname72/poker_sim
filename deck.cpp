#include "deck.h"

#define DECK_SIZE 52
#define VALS 14

Deck::Deck() {
    for(int i=0; i<suits.size(); i++) {
        Card::Suit s = suits[i];
        for (int j=2; j <= VALS; j++) {
            Card* c = new Card(j, s);
            deck.push_back(c);
        }
    }
}

size_t Deck::remainingCards() {
    return deck.size();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

Card* Deck::deal() {
    Card* c = deck.front();
    deck.erase(deck.begin());

    return c;
}
