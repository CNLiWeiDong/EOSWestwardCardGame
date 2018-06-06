#ifndef TEMPLET_DB_ShuXingChongWu_H
#define TEMPLET_DB_ShuXingChongWu_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_ShuXingChongWu_Data
{
int id;
int Class;
int Experience;
};
class DB_ShuXingChongWu;
static DB_ShuXingChongWu* DB_ShuXingChongWu_instanse = nullptr;
class DB_ShuXingChongWu
{
public:
static DB_ShuXingChongWu* getInstanse()
{
    if(DB_ShuXingChongWu_instanse)
        return  DB_ShuXingChongWu_instanse;
        DB_ShuXingChongWu_instanse = new DB_ShuXingChongWu();
    return  DB_ShuXingChongWu_instanse;
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
const DB_ShuXingChongWu_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_ShuXingChongWu_Data> db_data;
public:
DB_ShuXingChongWu()
{
    db_data[0] = {0,0,0};
    db_data[1] = {1,1,3};
    db_data[2] = {2,2,3};
    db_data[3] = {3,3,3};
    db_data[4] = {4,4,3};
    db_data[5] = {5,5,7};
    db_data[6] = {6,6,10};
    db_data[7] = {7,7,14};
    db_data[8] = {8,8,17};
    db_data[9] = {9,9,21};
    db_data[10] = {10,10,24};
    db_data[11] = {11,11,28};
    db_data[12] = {12,12,31};
    db_data[13] = {13,13,35};
    db_data[14] = {14,14,38};
    db_data[15] = {15,15,84};
    db_data[16] = {16,16,91};
    db_data[17] = {17,17,98};
    db_data[18] = {18,18,105};
    db_data[19] = {19,19,112};
    db_data[20] = {20,20,119};
    db_data[21] = {21,21,126};
    db_data[22] = {22,22,133};
    db_data[23] = {23,23,140};
    db_data[24] = {24,24,147};
    db_data[25] = {25,25,154};
    db_data[26] = {26,26,161};
    db_data[27] = {27,27,168};
    db_data[28] = {28,28,175};
    db_data[29] = {29,29,182};
    db_data[30] = {30,30,189};
    db_data[31] = {31,31,196};
    db_data[32] = {32,32,203};
    db_data[33] = {33,33,210};
    db_data[34] = {34,34,217};
    db_data[35] = {35,35,224};
    db_data[36] = {36,36,330};
    db_data[37] = {37,37,340};
    db_data[38] = {38,38,350};
    db_data[39] = {39,39,360};
    db_data[40] = {40,40,370};
    db_data[41] = {41,41,380};
    db_data[42] = {42,42,390};
    db_data[43] = {43,43,400};
    db_data[44] = {44,44,410};
    db_data[45] = {45,45,420};
    db_data[46] = {46,46,430};
    db_data[47] = {47,47,440};
    db_data[48] = {48,48,450};
    db_data[49] = {49,49,460};
    db_data[50] = {50,50,470};
    db_data[51] = {51,51,960};
    db_data[52] = {52,52,980};
    db_data[53] = {53,53,1000};
    db_data[54] = {54,54,1020};
    db_data[55] = {55,55,1040};
    db_data[56] = {56,56,1060};
    db_data[57] = {57,57,1080};
    db_data[58] = {58,58,1100};
    db_data[59] = {59,59,1120};
    db_data[60] = {60,60,2280};
    db_data[61] = {61,61,2320};
    db_data[62] = {62,62,2360};
    db_data[63] = {63,63,2400};
    db_data[64] = {64,64,2440};
    db_data[65] = {65,65,49600};
    db_data[66] = {66,66,50400};
    db_data[67] = {67,67,51200};
    db_data[68] = {68,68,52000};
    db_data[69] = {69,69,52800};
    db_data[70] = {70,70,268000};
    db_data[71] = {71,71,272000};
    db_data[72] = {72,72,276000};
    db_data[73] = {73,73,280000};
    db_data[74] = {74,74,284000};
    db_data[75] = {75,75,0};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
