#ifndef TEMPLET_DB_Heros_H
#define TEMPLET_DB_Heros_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_Heros_Data
{
};
class DB_Heros;
static DB_Heros* DB_Heros_instanse = nullptr;
class DB_Heros
{
public:
static DB_Heros* getInstanse()
{
    if(DB_Heros_instanse)
        return  DB_Heros_instanse;
        DB_Heros_instanse = new DB_Heros();
    return  DB_Heros_instanse;
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
const DB_Heros_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_Heros_Data> db_data;
public:
DB_Heros()
{
    db_data[1] = {};
    db_data[2] = {};
    db_data[3] = {};
    db_data[4] = {};
    db_data[5] = {};
    db_data[6] = {};
    db_data[7] = {};
    db_data[8] = {};
    db_data[9] = {};
    db_data[10] = {};
    db_data[11] = {};
    db_data[12] = {};
    db_data[13] = {};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
