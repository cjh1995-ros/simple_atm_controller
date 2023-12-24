#include <gtest/gtest.h>
#include "user_info.h"

#include <vector>



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



TEST(UserInfoTest, BasicInitialization) 
{
    BasicUserInfo user = test_case();

    EXPECT_EQ(user.get_name(), "CJH");
    EXPECT_EQ(user.get_pin(), 1234);

    std::vector<BasicCard> cards = user.get_cards();
    EXPECT_EQ(cards.size(), 2);
    EXPECT_EQ(cards[0].get_card_number(), 123456789);
    EXPECT_EQ(cards[1].get_card_number(), 987654321);

    std::vector<BasicBankAccount> accounts = user.get_accounts();
    EXPECT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0].get_account_number(), 123456789);
}



TEST(UserInfoTest, OpenAccountByCard)
{
    BasicUserInfo user = test_case();

    BasicCard card(123456789, "CJH", 12, 2020, 123, 1234);

    BasicBankAccount account = user.open_account_by_card(card, 1234);

    EXPECT_EQ(account.get_account_number(), 123456789);
    EXPECT_EQ(account.get_account_holder_name(), "CJH");
    EXPECT_EQ(account.get_pin(), 1234);
    EXPECT_EQ(account.get_balance(), 10000);
}