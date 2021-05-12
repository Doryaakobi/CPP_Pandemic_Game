#include "Researcher.hpp"

using namespace pandemic;
using namespace std;

Player &Researcher::discover_cure(Color color){

    int count = 0;
    for (auto &card : hand){ // going through the player hand to check for 5 cards with same color.
        if (City_color.at(card) == color){
            count++;
        }
    }

    if (count >= 5){ // can have more than 5 of same color

        if (board.isCured(color)){ // if a cure was already discovered, the player doesn't need to discard any cards.
            return *this;
        }

        int min = 0;
        for (auto it = hand.begin(); it != hand.end(); min++){
            if (min == 5){
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
        // std::cout << "Researcher discovered cure.\n";
    }
    else if (count < 5){
        throw std::invalid_argument("In order to discover color player needs at least 5 cards of same color!\n");
    }

    return *this;
}

