#ifndef TEMPLET_DB_JiNengZongBiao_H
#define TEMPLET_DB_JiNengZongBiao_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_JiNengZongBiao_Data
{
};
class DB_JiNengZongBiao;
static DB_JiNengZongBiao* DB_JiNengZongBiao_instanse = nullptr;
class DB_JiNengZongBiao
{
public:
static DB_JiNengZongBiao* getInstanse()
{
    if(DB_JiNengZongBiao_instanse)
        return  DB_JiNengZongBiao_instanse;
        DB_JiNengZongBiao_instanse = new DB_JiNengZongBiao();
    return  DB_JiNengZongBiao_instanse;
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
const DB_JiNengZongBiao_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_JiNengZongBiao_Data> db_data;
public:
DB_JiNengZongBiao()
{
    db_data[1] = {};
    db_data[2] = {};
    db_data[3] = {};
    db_data[4] = {};
    db_data[5] = {};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
