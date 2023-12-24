#include <gtest/gtest.h>
#include "account.h"

#include <vector>


using namespace BearBank;

TEST(AccountTest, BasicInitialization) 
{
    BasicBankAccount account(123456789, "CJH", 1234, 1000);
    EXPECT_EQ(account.get_account_number(), 123456789);
    EXPECT_EQ(account.get_account_holder_name(), "CJH");
    EXPECT_EQ(account.get_pin(), 1234);
    EXPECT_EQ(account.get_balance(), 1000);
}

TEST(AccountTest, BasicWithdrawal) 
{
    BasicBankAccount account(123456789, "CJH", 1234, 1000);

    int withdraw_amount = 100;
    account.withdraw(withdraw_amount);

    EXPECT_EQ(account.get_balance(), 900);
}

TEST(AccountTest, BasicDeposit) 
{
    BasicBankAccount account(123456789, "CJH", 1234, 1000);

    int deposit_amount = 100;
    account.deposit(deposit_amount);

    EXPECT_EQ(account.get_balance(), 1100);
}

