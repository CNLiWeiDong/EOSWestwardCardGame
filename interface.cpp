//
// Created by lwd on 2018/5/16.
//

#include "interface.h"

#include <vector>
#include <eosiolib/print.hpp>
#include <eosiolib/contract.hpp>
#include <eosiolib/dispatcher.hpp>
#include "eosiolib/token.hpp"
#include "db/DB_Require.h"
#include <eosiolib/currency.hpp>

using namespace eosio;

class interface:public contract
{
public:
    interface(account_name accout):contract(accout){

    }
    // @abi action
    void registUser(account_name user ) {
        require_auth( user );
        eosio::print( "hi, ", name{user});
    }
    // @abi action
    void doAction (uint64_t num) {
        eosio::print( "abinum: ",num );
    }

//    typedef eosio::multi_index<N(accounts), account> accounts;
//    currency::inline_transfer( from, _this_contract, quantity, "deposit" );
};

EOSIO_ABI(interface, (registUser)(doAction))