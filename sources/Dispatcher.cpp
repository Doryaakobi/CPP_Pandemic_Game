#include "Dispatcher.hpp"

using namespace pandemic;
using namespace std;


Player& Dispatcher::fly_direct(City dst){
    if(curr_city != dst && board.hasResearch(curr_city)){
        curr_city = dst;
    }
    else{
        return Player::fly_direct(dst);
    }
    return *this;
}