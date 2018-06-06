#ifndef TEMPLET_DB_DaoJu_H
#define TEMPLET_DB_DaoJu_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_DaoJu_Data
{
int id;
int type;
int use;
int wayuse;
string getgoods;
};
class DB_DaoJu;
static DB_DaoJu* DB_DaoJu_instanse = nullptr;
class DB_DaoJu
{
public:
static DB_DaoJu* getInstanse()
{
    if(DB_DaoJu_instanse)
        return  DB_DaoJu_instanse;
        DB_DaoJu_instanse = new DB_DaoJu();
    return  DB_DaoJu_instanse;
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
const DB_DaoJu_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_DaoJu_Data> db_data;
public:
DB_DaoJu()
{
    db_data[1] = {1,3,0,0,""};
    db_data[2] = {2,3,0,0,""};
    db_data[3] = {3,3,0,0,""};
    db_data[4] = {4,3,0,0,""};
    db_data[5] = {5,3,0,0,""};
    db_data[10000] = {10000,2,0,0,""};
    db_data[11000] = {11000,2,0,0,""};
    db_data[11001] = {11001,2,0,0,""};
    db_data[11002] = {11002,2,0,0,""};
    db_data[11003] = {11003,2,0,0,""};
    db_data[11004] = {11004,2,0,0,""};
    db_data[11005] = {11005,2,0,0,""};
    db_data[12000] = {12000,1,1,2,"4,15"};
    db_data[13000] = {13000,1,1,1,"12000,500|15001,100|17000,100|18000,1000"};
    db_data[13003] = {13003,1,1,1,"14000,35|14001,35|14002,35|14003,35|14004,35|18000,1000"};
    db_data[13004] = {13004,1,1,1,"10000,18000|18000,1000"};
    db_data[13005] = {13005,1,1,1,"11000,3000|11001,3000|11002,3000|11003,3000|11004,3000|11005,3000|18000,1000"};
    db_data[13006] = {13006,1,1,1,"14000,20|14002,20|20000,10|30003,1|18000,1000"};
    db_data[13007] = {13007,1,1,1,"1,1000000|2,50000|18000,2000"};
    db_data[13008] = {13008,1,1,1,"1,2000000|2,70000|18000,3000"};
    db_data[14000] = {14000,2,0,0,""};
    db_data[14001] = {14001,2,0,0,""};
    db_data[14002] = {14002,2,0,0,""};
    db_data[14003] = {14003,2,0,0,""};
    db_data[14004] = {14004,2,0,0,""};
    db_data[15001] = {15001,1,1,2,"1,80000"};
    db_data[16000] = {16000,1,0,0,""};
    db_data[17000] = {17000,1,1,2,"3,5"};
    db_data[18000] = {18000,1,0,0,""};
    db_data[20000] = {20000,1,0,0,""};
    db_data[20001] = {20001,1,0,0,""};
    db_data[20101] = {20101,1,0,0,""};
    db_data[30001] = {30001,1,0,0,""};
    db_data[30002] = {30002,1,0,0,""};
    db_data[30003] = {30003,1,0,0,""};
    db_data[30004] = {30004,1,0,0,""};
    db_data[30005] = {30005,1,0,0,""};
    db_data[30006] = {30006,1,0,0,""};
    db_data[30007] = {30007,1,0,0,""};
    db_data[30008] = {30008,1,0,0,""};
    db_data[30009] = {30009,1,0,0,""};
    db_data[30010] = {30010,1,0,0,""};
    db_data[30011] = {30011,1,0,0,""};
    db_data[30021] = {30021,1,0,0,""};
    db_data[30022] = {30022,1,0,0,""};
    db_data[30023] = {30023,1,0,0,""};
    db_data[40001] = {40001,1,0,0,""};
    db_data[40002] = {40002,1,0,0,""};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
