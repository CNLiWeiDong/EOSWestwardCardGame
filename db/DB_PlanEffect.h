#ifndef TEMPLET_DB_PlanEffect_H
#define TEMPLET_DB_PlanEffect_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_PlanEffect_Data
{
};
class DB_PlanEffect;
static DB_PlanEffect* DB_PlanEffect_instanse = nullptr;
class DB_PlanEffect
{
public:
static DB_PlanEffect* getInstanse()
{
    if(DB_PlanEffect_instanse)
        return  DB_PlanEffect_instanse;
        DB_PlanEffect_instanse = new DB_PlanEffect();
    return  DB_PlanEffect_instanse;
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
const DB_PlanEffect_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_PlanEffect_Data> db_data;
public:
DB_PlanEffect()
{
    db_data[20001] = {};
    db_data[20002] = {};
    db_data[20003] = {};
    db_data[20004] = {};
    db_data[20005] = {};
    db_data[20006] = {};
    db_data[20007] = {};
    db_data[20008] = {};
    db_data[20009] = {};
    db_data[20010] = {};
    db_data[30001] = {};
    db_data[30002] = {};
    db_data[30003] = {};
    db_data[30004] = {};
    db_data[30005] = {};
    db_data[30006] = {};
    db_data[30007] = {};
    db_data[30008] = {};
    db_data[30009] = {};
    db_data[30010] = {};
    db_data[30011] = {};
    db_data[30012] = {};
    db_data[10001] = {};
    db_data[10002] = {};
    db_data[10003] = {};
    db_data[10004] = {};
    db_data[10005] = {};
    db_data[10006] = {};
    db_data[10007] = {};
    db_data[10008] = {};
    db_data[10009] = {};
    db_data[10010] = {};
    db_data[10011] = {};
    db_data[10012] = {};
    db_data[10013] = {};
    db_data[10014] = {};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
