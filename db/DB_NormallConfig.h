#ifndef TEMPLET_DB_NormallConfig_H
#define TEMPLET_DB_NormallConfig_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_NormallConfig_Data
{
int id;
int adshopGold;
int resetBattleTimes;
int battleExpBase;
int battleGoldBase;
};
class DB_NormallConfig;
static DB_NormallConfig* DB_NormallConfig_instanse = nullptr;
class DB_NormallConfig
{
public:
static DB_NormallConfig* getInstanse()
{
    if(DB_NormallConfig_instanse)
        return  DB_NormallConfig_instanse;
        DB_NormallConfig_instanse = new DB_NormallConfig();
    return  DB_NormallConfig_instanse;
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
const DB_NormallConfig_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_NormallConfig_Data> db_data;
public:
DB_NormallConfig()
{
    db_data[1] = {1,10000,40,5,8000};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
