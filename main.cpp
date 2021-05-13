// #include "sources/City.hpp"
// #include "sources/Color.hpp"
#include "sources/Board.hpp"
#include "sources/Player.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/Medic.hpp"
#include "sources/Virologist.hpp"


using namespace pandemic;
using namespace std;

#include <vector>
#include <iostream>
#include <stdexcept>

Player& take_5Blue_cards(Player& p){
    
     return p.take_card(City::Atlanta),
     p.take_card(City::Essen),
     p.take_card(City::Chicago),
     p.take_card(City::London),
     p.take_card(City::Madrid);
}



int main(){
     
    Board b;

    Player p{b,City::Atlanta};
    p.take_card(City::Atlanta).build();
    take_5Blue_cards(p);
    cout << p << endl;
    std:: cout << p.role() << "\n";
    b[City::Atlanta] = 5;
    b[City::Algiers] = 5;
    b[City::Baghdad] = 5;
    b[City::BuenosAires] = 5;
    b[City::Chicago] = 5;
    b[City::Johannesburg] = 5;
    b[City::Madrid] = 5;
    b[City::Jakarta] = 5;
    b[City::Madrid] = 5;
    b[City::Montreal] = 5;

    std::cout << "b[City::Atlanta] = " << b[City::Atlanta] << "\n";
    p.discover_cure(Color::Blue);
    p.treat(City::Atlanta);
    std::cout << "b[City::Atlanta] = " << b[City::Atlanta] << "\n";

    cout << b << endl;














    return 0;
}



// clear && clang-9 -o run main.cpp -lstdc++ && ./run
// clang++-9 -o main main.cpp Board.o 
// make clean ; make ;clear && clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run
// clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run
// clang++-9 -std=c++2a -o main main.cpp objects/*.o