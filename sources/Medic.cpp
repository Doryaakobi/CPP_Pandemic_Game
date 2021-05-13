#include "Medic.hpp"

using namespace pandemic;
using namespace std;

Player &Medic::treat(City city){
    if (curr_city != city){
        throw std::invalid_argument("To treat a player current city " + cityString(curr_city) + " must be same as "
         + cityString(city) + "\n");
    }
    if (board[city] == 0){
        throw std::invalid_argument("Current city" + cityString(curr_city) + "has a disease level of 0\n");
    }
    
        board[city] = 0;
    

    std::cout << "Medic treated " + cityString(curr_city) + "\n";
    return *this;
}

// Player& Medic::drive(City dst){

//     Player::fly_direct(dst);
//     if(board.isCured(City_color.at(dst)) > 0){
//         board[dst] = 0;
//     }
//     return *this;
// }

// Player& Medic::fly_charter(City dst){
    
//     Player::fly_charter(dst);
//     if(board.isCured(City_color.at(dst)) > 0){
//         board[dst] = 0;
//     }
//     return *this;  
// }
// Player& Medic::fly_shuttle(City dst){
    
//     Player::fly_shuttle(dst);
//     if(board.isCured(City_color.at(dst)) > 0){
//         board[dst] = 0;
//     }
//     return *this;  
// }


// Player& Medic::fly_direct(City dst){
    
//     Player::fly_direct(dst);
//     if(board.isCured(City_color.at(dst)) > 0){
//         board[dst] = 0;
//     }
//     return *this; 
// }


void Medic::autoHeal(){

    if(board.isCured(City_color.at(curr_city))){
        board[curr_city] = 0;
    }

}
