#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic{

    class Player{

        protected:

            Board& board;
            std::set<City> hand;
            City curr_city;
            std::string expertise;
        

        public:

            Player(Board& board, City city , std::string exp = "Default"): board(board), curr_city(city) , expertise(exp){}

            Player& take_card(City);
            Player& drive(City);
            Player& fly_charter(City);
            Player& fly_shuttle(City);
            void show_hand();
            std::string role(){return "Player expertise: " + expertise + "\n";}
            friend std::ostream& operator<<(std::ostream&, const Player&);

            
            // These functions are virtual due to the reason each player had different capabilities using the same method
            // therefore we need to override these functions for the different characters of the game.
            virtual Player& fly_direct(City);
            virtual Player& build();
            virtual Player& discover_cure(Color);
            virtual Player& treat(City);
            virtual void autoHeal(){};

            ~Player();
    };

}
