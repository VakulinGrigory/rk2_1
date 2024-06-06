#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H

#include "BusinessMediator.h"
#include <stdexcept>

class GroceryStore {
public:
    std::int32_t Supply(std::uint16_t count);
    std::int32_t Sell();
    std::int32_t AlterPrice(std::int32_t priceChange);
    BusinessMediator* SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator);

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t stock_{ 0 };
    std::int32_t price_{ 100 };
};

#endif // GROCERY_STORE_H
