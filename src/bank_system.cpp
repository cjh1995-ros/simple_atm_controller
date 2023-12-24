#include "bank_system.h"

namespace BearBank
{


bool BasicBankSystem::validate_card(int card_number)
{
    if (card_number < 0)
    {
        throw std::runtime_error("Invalid card number");
    }

    for (auto& user : user_info_)
    {
        for (auto& card : user.second.get_cards())
        {
            if (card.get_card_number() == card_number)
            {
                return true;
            }
        }
    }

    return false;
};

BasicCard BasicBankSystem::find_card(int card_number)
{
    if (card_number < 0)
    {
        throw std::runtime_error("Invalid card number");
    }

    for (auto& user : user_info_)
    {
        for (auto& card : user.second.get_cards())
        {
            if (card.get_card_number() == card_number)
            {
                return card;
            }
        }
    }

    throw std::runtime_error("Card not found");
};

BasicBankAccount BasicBankSystem::get_account_by_card(BasicCard card, int pin)
{
    for (auto& user : user_info_)
    {
        if (user.second.get_name() == card.get_card_holder_name())
        {
            return user.second.open_account_by_card(card, pin);
        }
    }

    throw std::runtime_error("User not found");
};

} // namespace BearBank