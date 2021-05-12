#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Scientist: public Player {
        int num;
        std::string expertise;


        public:
            Scientist(Board& board, City city, int num): Player(board, city, "Scientist"), num(num){}
            Player& discover_cure(Color color) override;
            ~Scientist(){}
    };

}