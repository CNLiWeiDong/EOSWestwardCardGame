#ifndef TEMPLET_DB_HeroUpgrade_H
#define TEMPLET_DB_HeroUpgrade_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_HeroUpgrade_Data
{
int id;
int level;
int food;
int gold;
int exp;
};
class DB_HeroUpgrade;
static DB_HeroUpgrade* DB_HeroUpgrade_instanse = nullptr;
class DB_HeroUpgrade
{
public:
static DB_HeroUpgrade* getInstanse()
{
    if(DB_HeroUpgrade_instanse)
        return  DB_HeroUpgrade_instanse;
        DB_HeroUpgrade_instanse = new DB_HeroUpgrade();
    return  DB_HeroUpgrade_instanse;
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
const DB_HeroUpgrade_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_HeroUpgrade_Data> db_data;
public:
DB_HeroUpgrade()
{
    db_data[1] = {1,1,12,16000,15};
    db_data[2] = {2,2,12,16000,15};
    db_data[3] = {3,3,12,16000,15};
    db_data[4] = {4,4,24,32000,15};
    db_data[5] = {5,5,36,48000,15};
    db_data[6] = {6,6,48,64000,15};
    db_data[7] = {7,7,60,80000,20};
    db_data[8] = {8,8,72,96000,25};
    db_data[9] = {9,9,84,112000,30};
    db_data[10] = {10,10,96,128000,35};
    db_data[11] = {11,11,108,144000,40};
    db_data[12] = {12,12,120,160000,45};
    db_data[13] = {13,13,132,176000,50};
    db_data[14] = {14,14,288,384000,55};
    db_data[15] = {15,15,312,416000,60};
    db_data[16] = {16,16,336,448000,65};
    db_data[17] = {17,17,360,480000,70};
    db_data[18] = {18,18,384,512000,75};
    db_data[19] = {19,19,408,544000,80};
    db_data[20] = {20,20,432,576000,85};
    db_data[21] = {21,21,456,608000,90};
    db_data[22] = {22,22,480,640000,95};
    db_data[23] = {23,23,504,672000,100};
    db_data[24] = {24,24,528,704000,105};
    db_data[25] = {25,25,552,736000,110};
    db_data[26] = {26,26,576,768000,115};
    db_data[27] = {27,27,600,800000,120};
    db_data[28] = {28,28,624,832000,125};
    db_data[29] = {29,29,648,864000,130};
    db_data[30] = {30,30,672,896000,135};
    db_data[31] = {31,31,696,928000,140};
    db_data[32] = {32,32,720,960000,145};
    db_data[33] = {33,33,744,992000,150};
    db_data[34] = {34,34,768,1024000,155};
    db_data[35] = {35,35,792,1056000,160};
    db_data[36] = {36,36,816,1088000,165};
    db_data[37] = {37,37,840,1120000,170};
    db_data[38] = {38,38,864,1152000,175};
    db_data[39] = {39,39,888,1184000,180};
    db_data[40] = {40,40,912,1216000,185};
    db_data[41] = {41,41,936,1248000,190};
    db_data[42] = {42,42,960,1280000,195};
    db_data[43] = {43,43,984,1312000,200};
    db_data[44] = {44,44,1008,1344000,205};
    db_data[45] = {45,45,1032,1376000,210};
    db_data[46] = {46,46,1056,1408000,215};
    db_data[47] = {47,47,1080,1440000,220};
    db_data[48] = {48,48,1104,1472000,225};
    db_data[49] = {49,49,1128,1504000,230};
    db_data[50] = {50,50,1152,1536000,235};
    db_data[51] = {51,51,1176,1568000,480};
    db_data[52] = {52,52,1200,1600000,490};
    db_data[53] = {53,53,1224,1632000,500};
    db_data[54] = {54,54,1248,1664000,510};
    db_data[55] = {55,55,1272,1696000,520};
    db_data[56] = {56,56,1296,1728000,530};
    db_data[57] = {57,57,1320,1760000,540};
    db_data[58] = {58,58,1344,1792000,550};
    db_data[59] = {59,59,1368,1824000,560};
    db_data[60] = {60,60,2784,3712000,1140};
    db_data[61] = {61,61,2832,3776000,1160};
    db_data[62] = {62,62,2880,3840000,1180};
    db_data[63] = {63,63,2928,3904000,1200};
    db_data[64] = {64,64,2976,3968000,1220};
    db_data[65] = {65,65,3024,4032000,24800};
    db_data[66] = {66,66,3072,4096000,25200};
    db_data[67] = {67,67,3120,4160000,25600};
    db_data[68] = {68,68,3168,4224000,26000};
    db_data[69] = {69,69,3216,4288000,52800};
    db_data[70] = {70,70,3264,4352000,134000};
    db_data[71] = {71,71,3312,4416000,136000};
    db_data[72] = {72,72,3360,4480000,138000};
    db_data[73] = {73,73,3408,4544000,140000};
    db_data[74] = {74,74,3456,4608000,142000};
    db_data[75] = {75,75,0,0,0};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
