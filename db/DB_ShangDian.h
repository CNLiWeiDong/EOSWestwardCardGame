#ifndef TEMPLET_DB_ShangDian_H
#define TEMPLET_DB_ShangDian_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_ShangDian_Data
{
int id;
int type;
int goldtype;
int price;
int number;
int itemnum;
int vip;
};
class DB_ShangDian;
static DB_ShangDian* DB_ShangDian_instanse = nullptr;
class DB_ShangDian
{
public:
static DB_ShangDian* getInstanse()
{
    if(DB_ShangDian_instanse)
        return  DB_ShangDian_instanse;
        DB_ShangDian_instanse = new DB_ShangDian();
    return  DB_ShangDian_instanse;
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
const DB_ShangDian_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_ShangDian_Data> db_data;
public:
DB_ShangDian()
{
    db_data[1] = {1,1,2,100,99,100000,0};
    db_data[5] = {5,1,2,500,99,500000,0};
    db_data[3] = {3,1,2,200,5,25,0};
    db_data[20000] = {20000,2,2,480,35,1,1};
    db_data[18000] = {18000,1,1,50000,99,1,0};
    db_data[10000] = {10000,1,2,20,5,1,0};
    db_data[11003] = {11003,1,2,20,5,1,0};
    db_data[14003] = {14003,1,2,200,1,1,0};
    db_data[13000] = {13000,2,2,6980,1,1,1};
    db_data[13003] = {13003,2,2,15920,1,1,1};
    db_data[13004] = {13004,2,2,19800,1,1,1};
    db_data[13005] = {13005,2,2,19800,1,1,1};
    db_data[30002] = {30002,2,2,6000,1,1,1};
    db_data[13007] = {13007,2,2,40000,1,1,1};
    db_data[13008] = {13008,2,2,60000,1,1,1};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
