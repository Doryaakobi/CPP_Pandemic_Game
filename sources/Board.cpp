#include "Board.hpp"

using namespace std;
namespace pandemic
{

    int& Board::operator[](City city){
        return disease_level[city];
    }

    bool Board::is_clean(){
        for (auto &city : disease_level){
            if (city.second > 0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        cured.clear();
    }

    bool Board::isConnected(City& src, City& dst){
        return(board_graph.at(src).count(dst) > 0);
    }

    bool Board::isCured(Color c){
        return(cured.count(c) > 0);
    }

    void Board::markCure(Color c){
        cured.insert(c);
    }

    void Board::buildResearch(City& city){
        research_stations.insert(city);
    }

    bool Board::hasResearch(City& city){
        return(research_stations.count(city) > 0);
    }

    std::ostream &operator<<(std::ostream& out, const Board& board)
    {
        out << "******** Board **********\n" << endl;
        for(const auto& city : board.disease_level){
            out << cityString(city.first) + " Disease Level: " << city.second << endl;
        }
        out << "******** End Board ********\n" << endl;
        out << "******** Research Stations ********\n" << endl;
        out << "[";
        for(const auto& city : board.research_stations){
            if(city != *board.research_stations.rbegin()){
                out << cityString(city) + ",";
            }
            out << cityString(city);
        }
        out << "]\n";
        
        out << "********Cures Discovered********\n" << endl;
        out << "[";
        for(const auto& color : board.cured){
            if(color != *board.cured.rbegin()){
             out << colorString(color) + ",";
            }
            out << colorString(color);
        }
        out << "]\n";
        
        return out;
    }



    map<City,set<City>> Board::board_graph{

        {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing, {Shanghai, Seoul}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg, {Kinshasa, Khartoum}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity,HongKong, Sydney}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
        {Milan, {Essen, Paris, Istanbul}},
        {Montreal, {Chicago, Washington, NewYork}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Karachi, Delhi, Chennai}},
        {NewYork, {Montreal, Washington, London, Madrid}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago, {Lima}},
        {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, Manila, LosAngeles}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
        {Washington, {Atlanta, NewYork, Montreal, Miami}}};
}