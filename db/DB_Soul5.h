#ifndef TEMPLET_DB_Soul5_H
#define TEMPLET_DB_Soul5_H
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <eosiolib/eosio.hpp>
using namespace std;
using namespace eosio;
struct DB_Soul5_Data
{
int id;
int Class;
int nameber;
int Gold;
};
class DB_Soul5;
static DB_Soul5* DB_Soul5_instanse = nullptr;
class DB_Soul5
{
public:
static DB_Soul5* getInstanse()
{
    if(DB_Soul5_instanse)
        return  DB_Soul5_instanse;
        DB_Soul5_instanse = new DB_Soul5();
    return  DB_Soul5_instanse;
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
const DB_Soul5_Data& getDataById(int id)
{
    auto iter = db_data.find(id);
    eosio_assert(iter==db_data.end(),"id is not exist");
    return iter->second;
};
private:
    map<int,DB_Soul5_Data> db_data;
public:
DB_Soul5()
{
    db_data[0] = {0,0,1,4000};
    db_data[1] = {1,1,1,4000};
    db_data[2] = {2,2,1,4000};
    db_data[3] = {3,3,1,4000};
    db_data[4] = {4,4,2,8000};
    db_data[5] = {5,5,3,12000};
    db_data[6] = {6,6,4,16000};
    db_data[7] = {7,7,5,20000};
    db_data[8] = {8,8,6,24000};
    db_data[9] = {9,9,7,28000};
    db_data[10] = {10,10,8,32000};
    db_data[11] = {11,11,9,36000};
    db_data[12] = {12,12,10,40000};
    db_data[13] = {13,13,11,44000};
    db_data[14] = {14,14,24,96000};
    db_data[15] = {15,15,26,104000};
    db_data[16] = {16,16,28,112000};
    db_data[17] = {17,17,30,120000};
    db_data[18] = {18,18,32,128000};
    db_data[19] = {19,19,34,136000};
    db_data[20] = {20,20,36,144000};
    db_data[21] = {21,21,38,152000};
    db_data[22] = {22,22,40,160000};
    db_data[23] = {23,23,42,168000};
    db_data[24] = {24,24,44,176000};
    db_data[25] = {25,25,46,184000};
    db_data[26] = {26,26,48,192000};
    db_data[27] = {27,27,50,200000};
    db_data[28] = {28,28,52,208000};
    db_data[29] = {29,29,54,216000};
    db_data[30] = {30,30,56,224000};
    db_data[31] = {31,31,58,232000};
    db_data[32] = {32,32,60,240000};
    db_data[33] = {33,33,62,248000};
    db_data[34] = {34,34,64,256000};
    db_data[35] = {35,35,66,264000};
    db_data[36] = {36,36,68,272000};
    db_data[37] = {37,37,70,280000};
    db_data[38] = {38,38,72,288000};
    db_data[39] = {39,39,74,296000};
    db_data[40] = {40,40,76,304000};
    db_data[41] = {41,41,78,312000};
    db_data[42] = {42,42,80,320000};
    db_data[43] = {43,43,82,328000};
    db_data[44] = {44,44,84,336000};
    db_data[45] = {45,45,86,344000};
    db_data[46] = {46,46,88,352000};
    db_data[47] = {47,47,90,360000};
    db_data[48] = {48,48,92,368000};
    db_data[49] = {49,49,94,376000};
    db_data[50] = {50,50,96,384000};
    db_data[51] = {51,51,98,392000};
    db_data[52] = {52,52,100,400000};
    db_data[53] = {53,53,102,408000};
    db_data[54] = {54,54,104,416000};
    db_data[55] = {55,55,106,424000};
    db_data[56] = {56,56,108,432000};
    db_data[57] = {57,57,110,440000};
    db_data[58] = {58,58,112,448000};
    db_data[59] = {59,59,114,456000};
    db_data[60] = {60,60,116,464000};
    db_data[61] = {61,61,118,472000};
    db_data[62] = {62,62,120,480000};
    db_data[63] = {63,63,122,488000};
    db_data[64] = {64,64,124,496000};
    db_data[65] = {65,65,126,504000};
    db_data[66] = {66,66,128,512000};
    db_data[67] = {67,67,130,520000};
    db_data[68] = {68,68,132,528000};
    db_data[69] = {69,69,134,536000};
    db_data[70] = {70,70,136,544000};
    db_data[71] = {71,71,138,552000};
    db_data[72] = {72,72,140,560000};
    db_data[73] = {73,73,142,568000};
    db_data[74] = {74,74,144,576000};
    db_data[75] = {75,75,146,584000};
    db_data[76] = {76,76,148,592000};
    db_data[77] = {77,77,150,600000};
    db_data[78] = {78,78,152,608000};
    db_data[79] = {79,79,154,616000};
    db_data[80] = {80,80,156,624000};
    db_data[81] = {81,81,158,632000};
    db_data[82] = {82,82,160,640000};
    db_data[83] = {83,83,162,648000};
    db_data[84] = {84,84,164,656000};
    db_data[85] = {85,85,166,664000};
    db_data[86] = {86,86,168,672000};
    db_data[87] = {87,87,170,680000};
    db_data[88] = {88,88,172,688000};
    db_data[89] = {89,89,174,696000};
    db_data[90] = {90,90,176,704000};
    db_data[91] = {91,91,178,712000};
    db_data[92] = {92,92,180,720000};
    db_data[93] = {93,93,182,728000};
    db_data[94] = {94,94,184,736000};
    db_data[95] = {95,95,186,744000};
    db_data[96] = {96,96,188,752000};
    db_data[97] = {97,97,190,760000};
    db_data[98] = {98,98,192,768000};
    db_data[99] = {99,99,194,776000};
    db_data[100] = {100,100,196,784000};
    db_data[101] = {101,101,232,792000};
    db_data[102] = {102,102,236,800000};
    db_data[103] = {103,103,240,808000};
    db_data[104] = {104,104,244,816000};
    db_data[105] = {105,105,248,824000};
    db_data[106] = {106,106,252,832000};
    db_data[107] = {107,107,256,840000};
    db_data[108] = {108,108,260,848000};
    db_data[109] = {109,109,264,856000};
    db_data[110] = {110,110,268,864000};
    db_data[111] = {111,111,272,872000};
    db_data[112] = {112,112,276,880000};
    db_data[113] = {113,113,280,888000};
    db_data[114] = {114,114,284,896000};
    db_data[115] = {115,115,0,0};
}
};
#endif //TEMPLET_DB_BATTLEAI_H
