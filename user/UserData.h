//
// Created by lwd on 2018/5/31.
//

#ifndef TEMPLET_USERDATA_H
#define TEMPLET_USERDATA_H

#include <eosiolib/eosio.hpp>
#include <map>
#include <db/DB_Require.h>

using namespace eosio;

namespace user
{
    struct userEquip
    {
        uint8_t equip1;
        uint8_t equip2;
        uint8_t equip3;
        uint8_t equip4;
        uint8_t equip5;
        uint8_t equip6;
    };
    struct userSoul
    {
        uint8_t soul1;
        uint8_t soul2;
        uint8_t soul3;
        uint8_t soul4;
        uint8_t soul5;
        uint8_t soul6;
    };
    struct userSkill
    {
        uint8_t skill1;
        uint8_t skill2;
        uint8_t skill3;
        uint8_t skill4;
        uint8_t skill5;
    };
    struct studyItem
    {
        uint8_t attack_level;
        uint8_t lift_level;
        uint8_t defense_level;
    };
    struct userStudy
    {
        studyItem hero;
        studyItem pos1;
        studyItem pos2;
        studyItem pos3;
    };
    struct userHero
    {
        uint16_t hero1;
        uint16_t hero2;
        uint16_t hero3;
    };
    struct userPet
    {
        uint32_t pet1;
        uint32_t pet2;
        uint32_t pet3;
        uint32_t pet4;
        uint32_t pet5;
    };
    struct userInfo
    {
        uint8_t user_icon;
        uint8_t level;
        uint64_t gold;
        uint32_t diamand;
        uint32_t exp;
        uint16_t strength;
        uint16_t copyPassNum;
        uint32_t last_sign_time;
        userEquip equips;
        userSoul souls;
        userSkill skills;
        userStudy studys;
        userHero heros;
        userPet pets;
        uint64_t primary_key()const { return 1; }
    };
    typedef eosio::multi_index<N(userInfos), userInfo> userInfos;
    //using: userInfos a(_self,user_account))
    struct bagInfo
    {
        uint16_t item_id;
        uint16_t item_num;
        uint64_t primary_key()const { return item_id; }
        EOSLIB_SERIALIZE( bagInfo, (item_id)(item_num) )
    };
    typedef eosio::multi_index<N(bagInfo),bagInfo> bagInfos;
    //using: bagInfos a(_self,user_account))
    struct heroInfo
    {
        uint16_t hero_itemid;
        uint16_t hero_num;
        uint64_t primary_key()const { return hero_itemid; }
    };
    typedef eosio::multi_index<N(heroInfo),heroInfo> heroInfos;
    //using: heroInfos a(_self,user_account));
    struct petInfo
    {
        uint32_t pet_id;
        uint16_t pet_itemid;
        uint8_t pet_level;
        uint8_t pet_streng;
        uint64_t primary_key()const { return pet_id; }
    };
    typedef eosio::multi_index<N(petInfo),petInfo> petInfos;
    //using: petInfos a(_self,user_account))
    struct resetInfo
    {
        uint8_t day_sign_status;
        uint8_t strength_get_status;
        uint8_t online_times;
        uint8_t arena_times;
        uint8_t copy_gold_times;
        uint8_t copy_equip_times;
        uint8_t copy_skill1_times;
        uint8_t copy_skill2_times;
        uint8_t copy_skill3_times;
        uint64_t primary_key()const { return 1; }
    };
    typedef eosio::multi_index<N(resetInfo),resetInfo> resetInfos;
    //using: resetInfos a(_self,user_account))
    struct configInfo
    {
        uint8_t item_1_buy_times;
        uint64_t primary_key()const { return 1; }
    };
    typedef eosio::multi_index<N(configInfo),configInfo> configInfos;
    //using: configInfos a(_self,user_account))

    typedef std::map<uint16_t ,uint16_t> BagType;
    typedef std::map<uint32_t ,uint16_t> HeroType;
    typedef std::map<uint32_t ,petInfo> PetType;
    typedef HeroType PetStatusType;

    class UserData:public contract
    {
    public:
        UserData(account_name accout,account_name user):contract(accout),user_account(user) {}
        void saveUserData();
    private:
        //proterty
        account_name user_account;
        bool m_userinfo_read_status = false;
//        bool m_userinfo_save_status = true;
        userInfo m_userinfo;
        BagType m_bag;
        BagType m_bag_status; // m_bag_status  : 0 is not modify,1 need to change table.
        bool  m_bag_read_status = false;
        HeroType m_heroinfo;
        HeroType m_heroinfo_status;
        bool m_heroinfo_read_status = false;
        PetType m_petinfo;
        PetStatusType m_petinfo_status;
        bool m_petinfo__read_status = false;
        resetInfo m_resetinfo;
        bool m_resetinfo_read_status = false;
        bool m_resetinfo_save_status = false;
        configInfo m_configinfo;
        bool m_configinfo_read_status = false;
        bool m_configinfo_save_status = false;
    public:
        void setUserIcon(uint8_t icon);
        void addGold(uint64_t num);
        void subGold(uint64_t num);
        void addDiamand(uint32_t num);
        void subDiamand(uint32_t num);
        void levelUp();
        void addExp(uint32_t num);
        void subExp(uint32_t num);
        void addStrength(uint32_t num);
        void subStrength(uint32_t num);
        void setCopyPassNum(uint16_t num);
        void setLastSignTime(uint32_t time);
        void addItem(uint16_t itemid,uint16_t item_num);
        void subItem(uint16_t itemid,uint16_t item_num);
        userEquip& getEquips()
        {
            auto &userinfo = getUserInfo();
            return userinfo.equips;
        }
        userSoul& getSouls()
        {
            auto &userinfo = getUserInfo();
            return userinfo.souls;
        }
        userSkill& getSkills()
        {
            auto &userinfo = getUserInfo();
            return userinfo.skills;
        }
        userStudy& getStudys()
        {
            auto &userinfo = getUserInfo();
            return userinfo.studys;
        }
        userHero& getHeros()
        {
            auto &userinfo = getUserInfo();
            return userinfo.heros;
        }
        userPet& getPets()
        {
            auto &userinfo = getUserInfo();
            return userinfo.pets;
        }
    private:
        userInfo& getUserInfo();
        BagType& getBagInfo();
        BagType& getBagInfoStatus();
    public:
        const userInfo& c_getUserInfo() {return getUserInfo();}
        const BagType& c_getBagInfo() {return getBagInfo();}
        HeroType& getHeroInfo();
        HeroType& getHeroInfoStatus();
        PetType& getPetInfo();
        PetStatusType& getPetInfoStatus();
        resetInfo& getResetInfo();
        void setResetSaveStatus() {m_resetinfo_save_status = true;}
        configInfo& getConfigInfo();
        void setConfigSaveStatus() {m_configinfo_save_status = true;}
    };
}
#endif //TEMPLET_USERDATA_H
