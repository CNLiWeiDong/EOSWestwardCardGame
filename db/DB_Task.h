#ifndef TEMPLET_DB_Task_H
#define TEMPLET_DB_Task_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_Task_Data
{
int id;
string taskRewards;
};
class DB_Task;
static DB_Task* DB_Task_instanse = nullptr;
class DB_Task
{
public:
static DB_Task* getInstanse()
{
    if(DB_Task_instanse)
        return  DB_Task_instanse;
        DB_Task_instanse = new DB_Task();
    return  DB_Task_instanse;
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
const DB_Task_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_Task_Data> db_data;
public:
DB_Task()
{
    db_data[1] = {1,"1,50000|16000,1|10000,3|11000,3"};
    db_data[2] = {2,"1,50000|18000,2|10000,3|11001,3"};
    db_data[3] = {3,"1,50000|2,50|10000,3|11002,3"};
    db_data[4] = {4,"1,50000|2,50|10000,3|11003,3"};
    db_data[5] = {5,"1,50000|2,50|10000,3|11004,3"};
    db_data[6] = {6,"1,50000|18000,2|10000,3|11005,3"};
    db_data[7] = {7,"1,50000|2,50|10000,3|11000,3"};
    db_data[8] = {8,"1,50000|18000,2|10000,3|11001,3"};
    db_data[9] = {9,"1,50000|16000,2|10000,3|11002,3"};
    db_data[10] = {10,"1,50000|16000,2|10000,3|11003,3"};
    db_data[11] = {11,"1,50000|2,50|10000,3|11004,3"};
    db_data[12] = {12,"1,50000|18000,2|10000,3|11005,3"};
    db_data[13] = {13,"1,100000|2,100|17000,1|10000,3"};
    db_data[14] = {14,"1,50000|2,50|17000,1|10000,3"};
    db_data[15] = {15,"1,50000|12000,1|17000,1|10000,3"};
    db_data[16] = {16,"1,50000|2,50|17000,1|10000,3"};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
