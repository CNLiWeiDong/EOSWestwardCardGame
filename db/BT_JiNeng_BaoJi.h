#ifndef TEMPLET_BT_JiNeng_BaoJi_H
#define TEMPLET_BT_JiNeng_BaoJi_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct BT_JiNeng_BaoJi_Data
{
int id;
int Class;
int daoju_id;
int nameber;
int Gold;
};
class BT_JiNeng_BaoJi;
static BT_JiNeng_BaoJi* BT_JiNeng_BaoJi_instanse = nullptr;
class BT_JiNeng_BaoJi
{
public:
static BT_JiNeng_BaoJi* getInstanse()
{
    if(BT_JiNeng_BaoJi_instanse)
        return  BT_JiNeng_BaoJi_instanse;
        BT_JiNeng_BaoJi_instanse = new BT_JiNeng_BaoJi();
    return  BT_JiNeng_BaoJi_instanse;
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
const BT_JiNeng_BaoJi_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,BT_JiNeng_BaoJi_Data> db_data;
public:
BT_JiNeng_BaoJi()
{
    db_data[0] = {0,0,14000,10,100000};
    db_data[1] = {1,1,14000,10,100000};
    db_data[2] = {2,2,14000,10,100000};
    db_data[3] = {3,3,14000,10,100000};
    db_data[4] = {4,4,14000,15,100000};
    db_data[5] = {5,5,14000,15,100000};
    db_data[6] = {6,6,14000,15,100000};
    db_data[7] = {7,7,14000,20,100000};
    db_data[8] = {8,8,14000,20,100000};
    db_data[9] = {9,9,14000,25,100000};
    db_data[10] = {10,10,14000,30,100000};
    db_data[11] = {11,11,14000,35,100000};
    db_data[12] = {12,12,14000,40,100000};
    db_data[13] = {13,13,14000,45,100000};
    db_data[14] = {14,14,14000,50,100000};
    db_data[15] = {15,15,14000,0,0};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
