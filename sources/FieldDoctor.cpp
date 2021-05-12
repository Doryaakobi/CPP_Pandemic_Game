#include "FieldDoctor.hpp"

using namespace pandemic;
using namespace std;

Player& FieldDoctor::treat(City city){

    if(board.isConnected(curr_city,city)){
        if(board[city] == 0){
                throw std::invalid_argument("Current city" + cityString(curr_city) + "has a disease level of 0\n");
            }else if(board.isCured(City_color.at(city))){
                // If the city color disease was discovered treat action will drop level to 0
                board[city] = 0;
            }
            else {
                
                board[city]--;} // no cure discovered therefore disease level decreases by 1.

            // std::cout << "Player treated " + cityString(curr_city) + "\n";
        }
        else{
            Player::treat(city);
        }
    
    return *this;

    }
    
