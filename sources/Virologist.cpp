#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

Player &Virologist::treat(City city){
    if (hand.count(city) > 0){

        if (board[city] == 0){
            throw std::invalid_argument("Current city" + cityString(curr_city) + "has a disease level of 0\n");
        }
        else if (board.isCured(City_color.at(curr_city))){
            // If the city color disease was discovered, treat action will drop level to 0
            board[city] = 0;
        }
        else{
            board[city]--; // No cure was discovered therefore disease level decreases by 1.
        } 
        hand.erase(city);

        // std::cout << "Virologist treated " + cityString(curr_city) + "\n";
    }
    else { return Player::treat(city);}
    return *this;

}
