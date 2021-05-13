#include "GeneSplicer.hpp"

using namespace pandemic;
using namespace std;

Player& GeneSplicer::discover_cure(Color color){
    // // No research station.
    const uint minimal_cards = 5;

    if(!board.hasResearch(curr_city)){
        throw std::invalid_argument("Unable to discover a cure in a city without a research staion.\n");
    }

    if(hand.size() < minimal_cards){
        throw std::invalid_argument("Unable to discover a cure with less then 5 cards.\n");
    }
    if(board.isCured(color)){
        return *this;
    }


        int min = 0;
        for(auto it = hand.begin() ; it !=hand.end(); min++){
            if(min == minimal_cards){break;}
                it = hand.erase(it);
        }
        board.markCure(color);
        std:: cout << "Cured discovered by GeneSplicer\n" ;



    return *this;

}
