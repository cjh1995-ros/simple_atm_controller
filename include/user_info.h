#pragma once

#include <string>
#include <vector>
#include "card.h"
#include "account.h"
#include "unordered_map"




namespace BearBank
{


struct BasicCardHash 
{
    size_t operator()(const BasicCard& card) const 
    {
        return std::hash<int>()(card.get_card_number());
    }
};





struct BasicUserInfo
{
public:
    BasicUserInfo() = default;
    
    BasicUserInfo(std::string name, int pin)
        : name_(name), pin_(pin)
    {}

    BasicUserInfo(const BasicUserInfo& other)
        : name_(other.name_), pin_(other.pin_), cards_(other.cards_), accounts_(other.accounts_), card_to_account_(other.card_to_account_)
    {}

    std::string get_name() const { return name_; }
    int get_pin() const { return pin_; }
    std::vector<BasicCard> get_cards() const { return cards_; }
    std::vector<BasicBankAccount> get_accounts() const { return accounts_; }

    void make_card_and_account(BasicCard card, BasicBankAccount account)
    {
        cards_.push_back(card);
        accounts_.push_back(account);
        card_to_account_[card] = account;
    }

    BasicBankAccount open_account_by_card(BasicCard card, int pin)
    {
        if (card.get_pin() != pin)
        {
            throw std::runtime_error("Pin does not match");
        }

        return card_to_account_[card];
    }

private:
    std::string name_;
    int pin_;
    std::vector<BasicCard> cards_;
    std::vector<BasicBankAccount> accounts_;
    std::unordered_map<BasicCard, BasicBankAccount, BasicCardHash> card_to_account_;


};

} // namespace BearBank