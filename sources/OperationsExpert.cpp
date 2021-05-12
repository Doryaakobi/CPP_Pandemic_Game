#include "OperationsExpert.hpp"

using namespace pandemic;
using namespace std;

Player &OperationsExpert::build(){
    
    board.buildResearch(curr_city);
    // std::cout << "OperationsExpert built research station in " + cityString(curr_city) + ".\n";
    return *this;
}
