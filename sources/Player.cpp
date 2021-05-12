#include "Player.hpp"


namespace pandemic{

        // Player can take as many cards as he want (no two of the same city).                                                         
        Player& Player::take_card(City city){
            hand.insert(city);
            // std::cout << "Player Took " + cityString(city) + " card.\n";
            return *this; 
        }


        // To navigate between two cities they must be neighbours.
        Player& Player::drive(City city){
            if(curr_city == city){
                throw std::invalid_argument("you dumb fuck\n");
            }
            City temp;
            if(board.isConnected(curr_city,city)){
                temp= curr_city;
                curr_city = city;
                std::cout << "Player drove from" + cityString(temp) + " to " + cityString(city) +  ".\n";
            }else{

                std:: cout << "curr_city =  " + cityString(curr_city) + " city = " + cityString(city) + "\n"; 


                throw std::invalid_argument("Unable to drive between not neighbor cities!\n");
            }
            check();
            return *this;
        }

        // To fly direct player must hold the destination city card.
        Player& Player::fly_direct(City dst){

            if(curr_city == dst){
                throw std::invalid_argument("Player is already in " + cityString(dst) + "\n");
            }

            if(hand.count(dst) == 0){
                throw std::invalid_argument("Player doesn't hold card for" + cityString(dst) + "\n");
            }

            curr_city = dst;
            hand.erase(dst);
            // std::cout << "Player flew direct to" + cityString(dst) + ".\n";
            check();
            return *this;
        }

        // To fly charter player must hold the current city card.
        Player& Player::fly_charter(City dst){

            if(hand.count(curr_city) > 0){
                hand.erase(curr_city);
                curr_city = dst;
            }else throw std::invalid_argument("Player doesn't obtain current city card to fly charter\n");
            // std::cout << "Player flew charter to" + cityString(dst) + ".\n";
            check();
            return *this;
        }

        // To fly shuttle both cities must have research stations.
        Player& Player::fly_shuttle(City dst){

            if(curr_city == dst){
                throw std::invalid_argument("Cannot fly from a city to itself! \n");
            }

            if(board.hasResearch(curr_city) && board.hasResearch(dst)){
                curr_city = dst;
            }else throw std::invalid_argument("No research station in both cities!\n");
            
            // std::cout << "Player flew shuttle to " + cityString(dst) + ".\n";
            check();
            return *this;
        }

        Player& Player::build(){

            // Player which has the city card and perform build (in a city without a research station) is required to discard the card.
            if(hand.count(curr_city) > 0){
                if(!board.hasResearch(curr_city)){
                board.buildResearch(curr_city);
                hand.erase(curr_city);
                // std::cout << "Player threw " + cityString(curr_city) + " card.\n";
                return *this;
                }
            }else if(hand.count(curr_city) == 0){ // If the player doesn't hold the current city card cannot perform build.
                throw std::invalid_argument("Must obtain " + cityString(curr_city) + " in order to build.\n");
            }

            // Player which has the city card and perform build (in a city with a research station) is not required to discard the card.
            if(hand.count(curr_city) > 0){  
                if(board.hasResearch(curr_city)){
                    return *this;
                }
            }


            // std::cout << "Player built research station in " + cityString(curr_city) + ".\n";
            return *this;
        }


        Player& Player::treat(City city){

            if(curr_city != city){
            // A player cannot treat a city he's not currently in (Unless he's a Virologist)
                throw std::invalid_argument("To treat a player current city must be same as " + cityString(city) + "\n");
            }else if(board[city] == 0){
                throw std::invalid_argument("Current city " + cityString(curr_city) + " has a disease level of 0\n");
            }else if(board.isCured(City_color.at(curr_city))){
                // If the city color disease was discovered treat action will drop level to 0
                board[city] = 0;
                // std:: cout << "treated " + cityString(curr_city) + " with cure.\n";
            }
            else {
                
                board[city]--;} // no cure discovered therefore disease level decreases by 1.

            // std::cout << "Player treated " + cityString(curr_city) + "\n";
            return *this;
        }


        // To discover a cure player must have 5 of same color cards and current city with research station.
        Player& Player::discover_cure(Color color){
            const uint minimal_cards = 5;
            // // No research station.
            if(!board.hasResearch(curr_city)){
                throw std::invalid_argument("Unable to discover a cure in a city without a research staion.\n");
            }

            int count = 0;
            for(auto& card : hand){ // going through the player hand to check for 5 cards with same color.
                if(City_color.at(card) == color){
                    count++; 
                }
            }

            if(count >= minimal_cards){ // can have more than 5 of same color

                if(board.isCured(color)){ // if a cure was already discovered, the player doesn't need to discard any cards.
                    return *this;
                }
                
                int min = 0;
                for(auto it = hand.begin() ; it !=hand.end(); min++){
                    if(min == minimal_cards){break;}
                    if(City_color.at(*it) == color){
                        it = hand.erase(it);
                    }
                    else {
                        ++it;
                    }

                }
                board.markCure(color);
                // std:: cout << "Cured discovered\n" ;

            }else if(count < 5 ){
                throw std::invalid_argument("In order to discover color player needs at least 5 cards of same color!\n");
            }

            return *this;
        }

        void Player::show_hand(){
            std:: cout << "{";
            for(auto& card : hand){
                std:: cout << cityString(card) + ",";
            }
            std:: cout << "}\n";

        }




        Player::~Player(){}

}