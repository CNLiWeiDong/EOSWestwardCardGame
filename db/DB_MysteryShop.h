#ifndef TEMPLET_DB_MysteryShop_H
#define TEMPLET_DB_MysteryShop_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_MysteryShop_Data
{
int id;
int itemid;
int itemnum;
int diamand;
};
class DB_MysteryShop;
static DB_MysteryShop* DB_MysteryShop_instanse = nullptr;
class DB_MysteryShop
{
public:
static DB_MysteryShop* getInstanse()
{
    if(DB_MysteryShop_instanse)
        return  DB_MysteryShop_instanse;
        DB_MysteryShop_instanse = new DB_MysteryShop();
    return  DB_MysteryShop_instanse;
}
int getCount()
{
    return db_data.size();
}
vector<int> getAllIds()
{
    vector<int> ids;
    for(auto &it : db_data)
    {
        ids.push_back(it.first);
    }
    return ids;
}
const DB_MysteryShop_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_MysteryShop_Data> db_data;
public:
DB_MysteryShop()
{
    db_data[1] = {1,30007,1,32000};
    db_data[2] = {2,30007,1,32000};
    db_data[3] = {3,30007,1,32000};
    db_data[4] = {4,30007,1,32000};
    db_data[5] = {5,20000,1,480};
    db_data[6] = {6,30007,1,32000};
    db_data[7] = {7,14000,10,3600};
    db_data[8] = {8,30007,1,32000};
    db_data[9] = {9,10000,500,6000};
    db_data[10] = {10,12000,100,3200};
    db_data[11] = {11,14000,10,3600};
    db_data[12] = {12,14002,10,3600};
    db_data[13] = {13,12000,100,3200};
    db_data[14] = {14,14001,20,3200};
    db_data[15] = {15,14003,20,3200};
    db_data[16] = {16,14004,20,3200};
    db_data[17] = {17,11000,200,2400};
    db_data[18] = {18,12000,100,3200};
    db_data[19] = {19,11002,200,2400};
    db_data[20] = {20,11003,200,2400};
    db_data[21] = {21,11004,200,2400};
    db_data[22] = {22,11005,200,2400};
    db_data[23] = {23,14000,10,3600};
    db_data[24] = {24,11001,200,2400};
    db_data[25] = {25,30007,1,32000};
    db_data[26] = {26,14000,10,3600};
    db_data[27] = {27,14002,10,3600};
    db_data[28] = {28,12000,100,3200};
    db_data[29] = {29,10000,500,6000};
    db_data[30] = {30,14001,20,3200};
    db_data[31] = {31,14003,20,3200};
    db_data[32] = {32,14004,20,3200};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
