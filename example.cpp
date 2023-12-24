#include "atm_machine.h"
#include "bank_system.h"
#include "user_info.h"
#include "account.h"




using namespace BearBank;


// Generate 5 different user info for example
std::vector<BasicUserInfo> generate_user_info()
{
    std::vector<BasicUserInfo> user_infos;

    std::string name1 = "CJH1";
    int pin1 = 12341;

    BasicUserInfo user_info1(name1, pin1);

    BasicCard card1(123456789, name1, 12, 2020, 123, pin1);
    BasicBankAccount account1(123456789, name1, pin1, 10000);
    
    user_info1.make_card_and_account(card1, account1);



    std::string name2 = "CJH2";
    int pin2 = 12345;

    BasicUserInfo user_info2(name2, pin2);

    BasicCard card2(123456789, name2, 12, 2020, 123, pin2);
    BasicBankAccount account2(123456789, name2, pin2, 100);
    
    user_info2.make_card_and_account(card2, account2);



    std::string name3 = "CJH3";
    int pin3 = 12346;

    BasicUserInfo user_info3(name3, pin3);

    BasicCard card3(131313, name3, 12, 2020, 123, pin3);
    BasicBankAccount account3(131313, name3, pin3, 100);
    
    user_info2.make_card_and_account(card3, account3);


    return user_infos;
}


int main(void)
{

    BasicATMMachine atm_machine(1000000);

    std::vector<BasicUserInfo> user_infos = generate_user_info();


    BasicBankSystem bank_system;

    for (auto& user_info : user_infos)
        bank_system.add_user(user_info);

    // Info the test case that you should insert.
    std::cout << "Card Number: 123456789\n";
    std::cout << "Pin: 1234\n";
    std::cout << "Amount: 1000\n";
    std::cout << "Owner: CJH\n";

    std::cout << "If you don't insert the above information, the test will fail.\n";

    std::cout << std::endl;

    atm_machine.run(bank_system);

    return 0;
}