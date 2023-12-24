#include <gtest/gtest.h>
#include "card.h"

#include <vector>


using namespace BearBank;

TEST(CardTest, BasicInitialization) 
{
    BasicCard card(123456789, "CJH", 12, 2020, 123, 1234);
    EXPECT_EQ(card.get_card_number(), 123456789);
    EXPECT_EQ(card.get_card_holder_name(), "CJH");
    EXPECT_EQ(card.get_expiration_month(), 12);
    EXPECT_EQ(card.get_expiration_year(), 2020);
    EXPECT_EQ(card.get_cvv(), 123);
    EXPECT_EQ(card.get_pin(), 1234);
}
