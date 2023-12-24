#pragma once


#include "account.h"
#include "card.h"
#include "user_info.h"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>




namespace BearBank
{



class BasicBankSystem
{
public:
    BasicBankSystem() = default;

    bool validate_card(int card_number);
    BasicCard find_card(int card_number);

    BasicBankAccount get_account_by_card(BasicCard card, int pin);

    void add_user(BasicUserInfo user)
    {
        user_info_[user.get_name()] = user;
    }

private:
    // std::unordered_map<int, BasicATMMachine> atm_machines_; // atm_id, atm
    std::unordered_map<std::string, BasicUserInfo> user_info_; // user_name, user



}; // class BasicBankSystem




} // namespace BearBank