#ifndef TEMPLET_DB_OnLineReward_H
#define TEMPLET_DB_OnLineReward_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_OnLineReward_Data
{
int id;
int onLineTime;
string rewards;
};
class DB_OnLineReward;
static DB_OnLineReward* DB_OnLineReward_instanse = nullptr;
class DB_OnLineReward
{
public:
static DB_OnLineReward* getInstanse()
{
    if(DB_OnLineReward_instanse)
        return  DB_OnLineReward_instanse;
        DB_OnLineReward_instanse = new DB_OnLineReward();
    return  DB_OnLineReward_instanse;
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
const DB_OnLineReward_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_OnLineReward_Data> db_data;
public:
DB_OnLineReward()
{
    db_data[1] = {1,100,"2,50|1,40000|10000,2|16000,1|11000,2|18000,2"};
    db_data[2] = {2,250,"2,50|1,40000|10000,2|16000,1|11001,2|18000,2"};
    db_data[3] = {3,300,"2,50|1,40000|10000,2|16000,1|11002,2|18000,2"};
    db_data[4] = {4,400,"2,50|1,40000|10000,2|16000,1|11003,2|18000,2"};
    db_data[5] = {5,450,"2,50|1,40000|10000,2|16000,2|11004,2|18000,2"};
    db_data[6] = {6,500,"2,50|1,40000|10000,2|16000,2|11005,2|18000,2"};
    db_data[7] = {7,600,"2,100|1,100000|17000,2|16000,3|18000,2|14003,1"};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
