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

            Player& take_card(City city);
            Player& drive(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            void show_hand();
            std::string role(){return expertise;}
            
            // These functions are virtual due to the reason each player had different capabilities using the same method
            // therefore we need to override these functions for the different characters of the game.
            virtual Player& fly_direct(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City city);
            virtual void check(){};

            ~Player();
    };

}
