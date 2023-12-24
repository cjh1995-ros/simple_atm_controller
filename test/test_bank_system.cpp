#include "gtest/gtest.h"
#include "bank_system.h"

using namespace BearBank;

BasicUserInfo test_case() 
{
    BasicUserInfo user_info("CJH", 1234);
    
    BasicCard card1(123456789, "CJH", 12, 2020, 123, 1234);
    BasicCard card2(987654321, "CJH", 12, 2020, 123, 1234);

    BasicBankAccount account1(123456789, "CJH", 1234, 10000);
    BasicBankAccount account2(987654321, "CJH", 1234, 900);

    user_info.make_card_and_account(card1, account1);
    user_info.make_card_and_account(card2, account2);    

    return user_info;
}


TEST(BankSystemTest, BasicInitialization)
{
    BasicBankSystem bank_system;

    BasicUserInfo user = test_case();

    bank_system.add_user(user);

    EXPECT_EQ(bank_system.validate_card(123456789), true);
    EXPECT_EQ(bank_system.validate_card(987654321), true);
}


TEST(BankSystemTest, FindCard)
{
    BasicBankSystem bank_system;

    BasicUserInfo user = test_case();

    bank_system.add_user(user);

    BasicCard card = bank_system.find_card(123456789);

    EXPECT_EQ(card.get_card_number(), 123456789);
    EXPECT_EQ(card.get_card_holder_name(), "CJH");
}


TEST(BankSystemTest, GetAccountByCard)
{
    BasicBankSystem bank_system;

    BasicUserInfo user = test_case();

    bank_system.add_user(user);

    BasicCard card(123456789, "CJH", 12, 2020, 123, 1234);

    BasicBankAccount account = bank_system.get_account_by_card(card, 1234);

    EXPECT_EQ(account.get_account_number(), 123456789);
    EXPECT_EQ(account.get_account_holder_name(), "CJH");
    EXPECT_EQ(account.get_pin(), 1234);
    EXPECT_EQ(account.get_balance(), 10000);
}