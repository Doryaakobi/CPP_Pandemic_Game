#include "Researcher.hpp"

using namespace pandemic;
using namespace std;

Player &Researcher::discover_cure(Color color){
    
    const uint minimal_cards = 5;
    int count = 0;
    for (const auto &card : hand){ // going through the player hand to check for 5 cards with same color.
        if (City_color.at(card) == color){
            count++;
        }
    }

    if (count >= minimal_cards){ // can have more than 5 of same color

        if (board.isCured(color)){ // if a cure was already discovered, the player doesn't need to discard any cards.
            return *this;
        }

        int min = 0;
        for (auto it = hand.begin(); it != hand.end(); min++){
            if (min == minimal_cards){
                break;
            }
            if (City_color.at(*it) == color){
                it = hand.erase(it);
            }
            else{
                ++it;
            }
        }
        board.markCure(color);
        std::cout << "Researcher discovered cure.\n";
    }
    else if (count < minimal_cards){
        throw std::invalid_argument("In order to discover color player needs at least 5 cards of same color!\n");
    }

    return *this;
}

