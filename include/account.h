#pragma once
#include <iostream>
#include <string>
#include <memory>


namespace BearBank
{


struct BasicBankAccount
{
public:
    BasicBankAccount() = default;

    BasicBankAccount(int account_number, std::string account_holder_name, int pin, int balance)
        : account_number_(account_number), account_holder_name_(account_holder_name), 
        pin_(pin), balance_(balance)
    {}

    int get_account_number() const { return account_number_; }
    std::string get_account_holder_name() const { return account_holder_name_; }
    int get_pin() const { return pin_; }
    int get_balance() const { return balance_; }

    void deposit(int amount)
    {
        balance_ += amount;
    }

    bool withdraw(int amount)
    {
        if (amount > balance_)
            return false;
        balance_ -= amount;
        return true;
    }

    void show_info()
    {
        std::cout << "Account Number: " << account_number_ << std::endl;
        std::cout << "Account Holder Name: " << account_holder_name_ << std::endl;
        std::cout << "Pin Number: " << pin_ << std::endl;
        std::cout << "Balance: " << balance_ << "\n\n";
    }

    void show_balance()
    {
        std::cout << "Balance: " << balance_ << "\n\n";
    }

private:
    int             account_number_;
    std::string     account_holder_name_;
    int             pin_;
    int             balance_;
};




} // namespace BearBank