#ifndef BUSINESS_MEDIATOR_H
#define BUSINESS_MEDIATOR_H

#include <cstdint>

namespace design {
    template <typename T>
    class AccessKey {
        friend T;
        AccessKey() {}
    };
}

class EstateOwner;
class GroceryStore;
class Restaurant;

class BusinessMediator {
public:
    BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant);

    void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void GroceryStockChanged(std::int32_t currentStock);
    void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void FoodIsCooked();

private:
    EstateOwner& estateOwner_;
    GroceryStore& groceryStore_;
    Restaurant& restaurant_;
};

#endif // BUSINESS_MEDIATOR_H
