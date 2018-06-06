//
// Created by lwd on 2018/5/31.
//

#include "UserData.h"

namespace user
{
    userInfo &UserData::getUserInfo()
    {
        if (m_userinfo_read_status)
            return m_userinfo;
        //user
        userInfos user_info(_self, user_account);
        eosio_assert(user_info.begin() != user_info.end(), "user is not existed");
        m_userinfo = *(user_info.begin());
        m_userinfo_read_status = true;
        return m_userinfo;
    }

    BagType &UserData::getBagInfo()
    {
        if (m_bag_read_status)
            return m_bag;
        //bag
        bagInfos bag(_self, user_account);
        for (auto &it : bag)
        {
            m_bag[it.item_id] = it.item_num;
            m_bag_status[it.item_id] = 0;
        }
        return m_bag;
    }

    BagType& UserData::getBagInfoStatus()
    {
        return m_bag_status;
    }
    HeroType& UserData::getHeroInfo()
    {
        if(m_heroinfo_read_status)
            return m_heroinfo;
        heroInfos hero(_self,user_account);
        for(auto &it : hero)
        {
            m_heroinfo[it.hero_itemid] = it.hero_num;
            m_heroinfo_status[it.hero_itemid] = 0;
        }
        return m_heroinfo;
    }
    HeroType& UserData::getHeroInfoStatus()
    {
        return m_heroinfo_status;
    }
    PetType& UserData::getPetInfo()
    {
        if(m_petinfo__read_status)
            return m_petinfo;
        petInfos pet(_self,user_account);
        for(auto& it : pet)
        {
            m_petinfo[it.pet_id] = it;
            m_petinfo_status[it.pet_id] = 0;
        }
        return m_petinfo;
    }
    PetStatusType& UserData::getPetInfoStatus()
    {
        return m_petinfo_status;
    }
    resetInfo& UserData::getResetInfo()
    {
        if(m_resetinfo_read_status)
            return m_resetinfo;
        resetInfos reset(_self,user_account);
        if(reset.begin()==reset.end())
            m_resetinfo = {0};
        else
            m_resetinfo = *reset.begin();
        m_resetinfo_read_status = true;
        return m_resetinfo;
    }
    configInfo& UserData::getConfigInfo()
    {
        if(m_configinfo_read_status)
            return m_configinfo;
        configInfos config(_self,user_account);
        if(config.begin()==config.end())
            m_configinfo = {0};
        else
            m_configinfo = *config.begin();
        m_configinfo_read_status = true;
        return m_configinfo;
    }
    void UserData::saveUserData()
    {
        if(m_userinfo_read_status)
        {
            userInfos user_info(_self, user_account);
            user_info.modify(user_info.begin(),user_account,[&](auto &user){
                user = this->getUserInfo();
            });
        }
        if(m_resetinfo_save_status)
        {
            resetInfos reset(_self,user_account);
            if(reset.begin()==reset.end())
                reset.emplace(user_account,[&](auto& info){
                    info = this->getResetInfo();
                });
            else
                reset.modify(reset.begin(),user_account,[&](auto& info){
                   info = this->getResetInfo();
                });
        }
        if(m_configinfo_save_status)
        {
            configInfos config(_self,user_account);
            if(config.begin()==config.end())
                config.emplace(user_account,[&](auto& info){
                    info = this->getConfigInfo();
                });
            else
                config.modify(config.begin(),user_account,[&](auto& info){
                    info = this->getConfigInfo();
                });
        }
        if(m_bag_read_status)
        {
            bagInfos bags(_self, user_account);
            auto &bag_cache = m_bag;
            for(auto& it:m_bag_status)
            {
                if(it.second==1)
                {
                    auto iter = bags.find(it.first);
                    if(iter==bags.end())
                    {
                        if (bag_cache[it.first] > 0)
                            bags.emplace(user_account, [&](auto &item)
                            {
                                item.item_id = it.first;
                                item.item_num = bag_cache[it.first];
                            });
                    }
                    else
                    {
                        if (bag_cache[it.first] > 0)
                            bags.modify(iter, user_account, [&](auto &item)
                            {
                                item.item_id = it.first;
                                item.item_num = bag_cache[it.first];
                            });
                        else
                            bags.erase(iter);
                    }
                }
            }
        }

    }

    /* UserData property opertion*/
    void UserData::setUserIcon(uint8_t icon)
    {
        auto &userinfo = getUserInfo();
        userinfo.user_icon = icon;
    }
    void UserData::addGold(uint64_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        auto old_gold = userinfo.gold;
        userinfo.gold += num;
        eosio_assert(userinfo.gold>old_gold,"the gold overflow");
    }
    void UserData::subGold(uint64_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.gold>num,"remain gold num less");
        userinfo.gold -= num;
    }
    void UserData::addDiamand(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        auto old_diamand = userinfo.diamand;
        userinfo.diamand += num;
        eosio_assert(userinfo.diamand>old_diamand,"the diamand overflow");
    }
    void UserData::subDiamand(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.diamand>num,"remain diamand num less");
        userinfo.diamand -= num;
    }
    void UserData::levelUp()
    {
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.level<75,"user level is max");
        userinfo.level++;
        userinfo.exp = 0;
        addGold(200000);
        addDiamand(100);
    }
    void UserData::addExp(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        auto old_exp = userinfo.exp;
        userinfo.exp += num;
        eosio_assert(userinfo.diamand>old_exp,"the exp overflow");
        auto & db = *DB_ShuXingChongWu::getInstanse();
        auto &item = db.getDataById(userinfo.level);
        if(item.Experience>0&&userinfo.exp>=item.Experience)
            levelUp();
    }
    void UserData::subExp(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.exp>num,"remain exp num less");
        userinfo.exp -= num;
    }
    void UserData::addStrength(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        auto old_strength = userinfo.strength;
        userinfo.strength += num;
        eosio_assert(userinfo.strength>old_strength,"the strength overflow");
    }
    void UserData::subStrength(uint32_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.strength>num,"remain strength num less");
        userinfo.strength -= num;
    }
    void UserData::setCopyPassNum(uint16_t num)
    {
        auto &userinfo = getUserInfo();
        eosio_assert(userinfo.copyPassNum+1<=num,"copy pass error");
        if(num>userinfo.copyPassNum)
        {
            userinfo.copyPassNum = num;
        }
    }
    void UserData::setLastSignTime(uint32_t time)
    {
        auto &userinfo = getUserInfo();
        userinfo.last_sign_time = time/86400*86400;
    }
    void UserData::addItem(uint16_t itemid,uint16_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &items = getBagInfo();
        auto &items_status = getBagInfoStatus();
        auto old_num = items[itemid];
        items[itemid] += num;
        items_status[itemid] = 1;
        eosio_assert(items[itemid]>old_num,"the num overflow");
    }
    void UserData::subItem(uint16_t itemid,uint16_t num)
    {
        eosio_assert(num>0,"num less 0");
        auto &items = getBagInfo();
        auto &items_status = getBagInfoStatus();
        eosio_assert(items[itemid]>num,"remain num less");
        items[itemid] -= num;
        items_status[itemid] = 1;
    }
}