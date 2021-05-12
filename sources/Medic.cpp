#include "Medic.hpp"

using namespace pandemic;
using namespace std;

Player &Medic::treat(City city){
    if (curr_city != city){
        throw std::invalid_argument("To treat a player current city must be same as" + cityString(city) + "\n");
    }
    else if (board[city] == 0){
        throw std::invalid_argument("Current city" + cityString(curr_city) + "has a disease level of 0\n");
    }
    else{
        board[city] = 0;
    }

    // std::cout << "Medic treated " + cityString(curr_city) + "\n";
    return *this;
}

// Player& Medic::fly_direct(City city) {

//     Player::fly_direct(city);
//     if(cure) {b[city] = 0}
// }

void Medic::check(){

    if(board.isCured(City_color.at(curr_city))){
        board[curr_city] = 0;
    }

}
