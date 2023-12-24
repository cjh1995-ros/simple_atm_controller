#include "atm_machine.h"


namespace BearBank
{


void BasicATMMachine::run(BasicBankSystem& bank_system)
{
    std::cout << "This is BearBank ATM Machine" << std::endl;

    // Insert Card
    std::cout << "Please insert your card" << std::endl;
    std::cout << "Card number(This is bcz we don't have real card): "; 
    int card_number;
    std::cin >> card_number;

    // Check if card is in DB
    if (!bank_system.validate_card(card_number))
    {
        std::cout << "Card is not in DB. Please check the card is real.\n\n" << std::endl;
        return;
    }

    // Find the card in user_info_
    BasicCard card = bank_system.find_card(card_number);

    std::cout << "Pin: ";
    int pin;
    std::cin >> pin;

    // Check if pin is correct
    if (card.get_pin() != pin)
    {
        std::cout << "Pin does not match\n\n" << std::endl;
        return;
    }

    BasicBankAccount account = bank_system.get_account_by_card(card, pin);


    bool running = true;

    while (running)
    {
        // Select action
        std::cout << "Please select action" << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Show Balance" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Action: ";
        int action;
        std::cin >> action;

        int amount;

        bool is_okay = false;

        switch (action)
        {
        case 1:
            std::cout << "Please enter amount to deposit: ";
            std::cin >> amount;
            account.deposit(amount);
            account.show_balance();
            break;
        case 2:
            std::cout << "Please enter amount to withdraw: ";
            std::cin >> amount;
            is_okay = account.withdraw(amount);
            if (!is_okay)
            {
                std::cout << "Not enough balance. You can't withdraw that much\n\n" ;
                std::cout << "Your balance: " << account.get_balance() << "\n\n";
            }
            account.show_balance();
            break;
        case 3:
            account.show_balance();
            break;
        case 4:
            std::cout << "Thank you for using BearBank ATM Machine" << std::endl;
            running = false;
            break;
        default:
            std::cout << "Invalid action" << std::endl;
            break;
        }
    }
}




} // namespace BearBank