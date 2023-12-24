#pragma once

#include <vector>
#include <string>
#include <memory>





namespace BearBank 
{


struct BasicCard
{
public:
    BasicCard() = default;

    BasicCard(int card_number, std::string card_holder_name, int expiration_month, 
         int expiration_year, int cvv, int pin)
        : card_number_(card_number), card_holder_name_(card_holder_name), 
        expiration_month_(expiration_month), expiration_year_(expiration_year), 
        cvv_(cvv), pin_(pin)
    {}

    int get_card_number() const { return card_number_; }
    std::string get_card_holder_name() const { return card_holder_name_; }
    int get_expiration_month() const { return expiration_month_; }
    int get_expiration_year() const { return expiration_year_; }
    int get_cvv() const { return cvv_; }
    int get_pin() const { return pin_; }


    bool operator==(const BasicCard& other) const
    {
        return card_number_ == other.card_number_ && card_holder_name_ == other.card_holder_name_ &&
            expiration_month_ == other.expiration_month_ && expiration_year_ == other.expiration_year_ &&
            cvv_ == other.cvv_ && pin_ == other.pin_;
    }

private:
    int             card_number_;
    std::string     card_holder_name_;
    int             expiration_month_;
    int             expiration_year_;
    int             cvv_;
    int             pin_;
};




} // namespace BearBank