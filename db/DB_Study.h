#ifndef TEMPLET_DB_Study_H
#define TEMPLET_DB_Study_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_Study_Data
{
int id;
string price;
};
class DB_Study;
static DB_Study* DB_Study_instanse = nullptr;
class DB_Study
{
public:
static DB_Study* getInstanse()
{
    if(DB_Study_instanse)
        return  DB_Study_instanse;
        DB_Study_instanse = new DB_Study();
    return  DB_Study_instanse;
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
const DB_Study_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_Study_Data> db_data;
public:
DB_Study()
{
    db_data[1] = {1,"500000|2000000|5000000|0"};
    db_data[2] = {2,"500000|2000000|5000000|0"};
    db_data[3] = {3,"500000|2000000|5000000|0"};
    db_data[4] = {4,"500000|2000000|5000000|0"};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
