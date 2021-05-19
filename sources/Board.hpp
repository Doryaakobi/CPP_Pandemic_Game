#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>


namespace pandemic{

    class Board{
        
        static std::map<City,std::set<City>> board_graph;
        std::map<City,int> disease_level;
        std::set<Color> cured;
        std::set<City> research_stations;
        // std::set<pandemic::Player> players;

        public:
        
        Board(){}
        ~Board(){}
        

        bool is_clean();
        void remove_cures();
        // void addplayer(pandemic::Player);
        int& operator[](City);
        static bool isConnected(City&,City&);
        void markCure(Color);
        bool isCured(Color);
        bool hasResearch(City&);
        void buildResearch(City&);
        friend std::ostream& operator<<(std::ostream&, const Board&);



    };
}