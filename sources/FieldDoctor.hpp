#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class FieldDoctor: public Player {
        
        public:
            FieldDoctor(pandemic::Board& board, City city): Player(board, city,"FieldDoctor") {}
            Player& treat(City c) override;
            ~FieldDoctor(){}
    };

}