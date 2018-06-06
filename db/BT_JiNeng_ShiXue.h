#ifndef TEMPLET_BT_JiNeng_ShiXue_H
#define TEMPLET_BT_JiNeng_ShiXue_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct BT_JiNeng_ShiXue_Data
{
int id;
int Class;
int daoju_id;
int nameber;
int Gold;
};
class BT_JiNeng_ShiXue;
static BT_JiNeng_ShiXue* BT_JiNeng_ShiXue_instanse = nullptr;
class BT_JiNeng_ShiXue
{
public:
static BT_JiNeng_ShiXue* getInstanse()
{
    if(BT_JiNeng_ShiXue_instanse)
        return  BT_JiNeng_ShiXue_instanse;
        BT_JiNeng_ShiXue_instanse = new BT_JiNeng_ShiXue();
    return  BT_JiNeng_ShiXue_instanse;
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
const BT_JiNeng_ShiXue_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,BT_JiNeng_ShiXue_Data> db_data;
public:
BT_JiNeng_ShiXue()
{
    db_data[0] = {0,0,14002,10,100000};
    db_data[1] = {1,1,14002,10,100000};
    db_data[2] = {2,2,14002,10,100000};
    db_data[3] = {3,3,14002,10,100000};
    db_data[4] = {4,4,14002,15,100000};
    db_data[5] = {5,5,14002,15,100000};
    db_data[6] = {6,6,14002,15,100000};
    db_data[7] = {7,7,14002,20,100000};
    db_data[8] = {8,8,14002,20,100000};
    db_data[9] = {9,9,14002,25,100000};
    db_data[10] = {10,10,14002,30,100000};
    db_data[11] = {11,11,14002,35,100000};
    db_data[12] = {12,12,14002,40,100000};
    db_data[13] = {13,13,14002,45,100000};
    db_data[14] = {14,14,14002,50,100000};
    db_data[15] = {15,15,14002,0,0};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
