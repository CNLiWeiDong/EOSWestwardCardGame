//
// Created by lwd on 2018/6/4.
//

#ifndef TEMPLET_GAMEDATA_H
#define TEMPLET_GAMEDATA_H


#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <map>

using namespace eosio;

namespace game
{
    const account_name ceo_account = N(westceo);
    const account_name admin_account = N(westadmin);
    const account_name heros_admin_account = N(westherosadm);
    const account_name pets_admin_account = N(westpetadmin);

    struct gameInfo
    {
        uint8_t pause_status = 0;
        uint32_t user_count = 0;
        uint32_t game_day_time;
        uint16_t eos_price;
        uint64_t primary_key()const { return 1; }
    };
    typedef eosio::multi_index<N(gameInfo), gameInfo> gameInfos;
    struct marketPet
    {
        uint32_t pet_id;
        uint16_t pet_itemid;
        uint8_t pet_level;
        uint8_t pet_streng;
        account_name account;
        asset sale_ammount;
        uint64_t primary_key()const { return pet_id; }
    };
    typedef eosio::multi_index<N(marketPet), marketPet> marketPets;
    struct marketHero
    {
        uint64_t key;
        uint16_t hero_itemid;
        account_name account;
        asset sale_ammount;
        uint64_t primary_key()const { return key; }
    };
    struct arenaRankInfo
    {
        uint32_t arena_rank;
        account_name user_id;
        uint64_t primary_key()const { return arena_rank; }
        uint64_t user_key() const { return user_id; }
    };
    typedef eosio::multi_index<N(arenaRankInf),arenaRankInfo,
            eosio::indexed_by<N(arenaUserId), eosio::const_mem_fun<arenaRankInfo, uint64_t, &arenaRankInfo::user_key> >> arenaRankInfos;
    //using: arenaRankInfos a(_self,N(arenaRankInf))
    class GameData:public contract
    {
    public:
        GameData(account_name accout):contract(accout) {}

    };
}

#endif //TEMPLET_GAMEDATA_H
