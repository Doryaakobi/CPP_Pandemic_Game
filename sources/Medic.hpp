#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& board, City city): Player(board, city,"Medic") {}
            Player& treat(City city) override;
            void autoHeal() override;

            ~Medic(){}
    };

}