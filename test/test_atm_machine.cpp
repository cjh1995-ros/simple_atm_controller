#include "gtest/gtest.h"
#include "atm_machine.h"
#include "bank_system.h"
#include "user_info.h"





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


TEST(ATMMachineTest, BasicInitialization)
{
    BasicATMMachine atm_machine(1000000);

    BasicUserInfo user = test_case();

    BasicBankSystem bank_system;

    bank_system.add_user(user);

    // Info the test case that you should insert.
    std::cout << "Card Number: 123456789\n";
    std::cout << "Pin: 1234\n";
    std::cout << "Amount: 1000\n";
    std::cout << "Owner: CJH\n";

    std::cout << "If you don't insert the above information, the test will fail.\n";

    std::cout << std::endl;

    atm_machine.run(bank_system);
}