#pragma once

#include "card.h"
#include "user_info.h"
#include "bank_system.h"



namespace BearBank
{

class BasicATMMachine
{

public:
    BasicATMMachine() = default;
    BasicATMMachine(int money_in_machine)
        : money_in_machine_(money_in_machine)
    {}

    void run(BasicBankSystem& bank_system);

private:
    void query_user_info();
    BasicCard ask_insert_card();
    bool lock();
    bool validate_card(BasicCard& card);

private:
    int money_in_machine_;
    int shutdown_time_ = 0; // lock down time


};




} // namespace BearBank