#ifndef TEMPLET_DB_Plan_H
#define TEMPLET_DB_Plan_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_Plan_Data
{
int id;
int battle_id;
};
class DB_Plan;
static DB_Plan* DB_Plan_instanse = nullptr;
class DB_Plan
{
public:
static DB_Plan* getInstanse()
{
    if(DB_Plan_instanse)
        return  DB_Plan_instanse;
        DB_Plan_instanse = new DB_Plan();
    return  DB_Plan_instanse;
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
const DB_Plan_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_Plan_Data> db_data;
public:
DB_Plan()
{
    db_data[30001] = {30001,1};
    db_data[30002] = {30002,2};
    db_data[30003] = {30003,3};
    db_data[30004] = {30004,100};
    db_data[30005] = {30005,5};
    db_data[30006] = {30006,6};
    db_data[30007] = {30007,102};
    db_data[30008] = {30008,101};
    db_data[30009] = {30009,100};
    db_data[30010] = {30010,102};
    db_data[30011] = {30011,101};
    db_data[30021] = {30021,200};
    db_data[30022] = {30022,201};
    db_data[30023] = {30023,201};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
