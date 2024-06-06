#include <iostream>
#include "BusinessMediator.h"
#include "EstateOwner.h"
#include "GroceryStore.h"
#include "Restaraunt.h"

void BuyFood(Restaraunt& restaraunt) {
    auto price = restaraunt.CookFood();
    if (price >= 0) {
        std::cout << "[BuyFood] The price of food: " << price << std::endl;
    } else {
        std::cout << "[BuyFood] Restaraunt was closed because groceries are lack." << std::endl;
    }
}

void SupplyGrocery(GroceryStore& groceryStore, std::uint16_t count) {
    auto newCount = groceryStore.Supply(count);
    auto oldCount = newCount - count;
    std::cout << "Grocery Stock Changes: " << oldCount << " -> " << newCount << std::endl;
}

void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange) {
    auto newPrice = groceryStore.AlterPrice(priceChange);
    auto oldPrice = newPrice - priceChange;
    std::cout << "Grocery Price Changes: " << oldPrice << " -> " << newPrice << std::endl;
}

void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice) {
    auto oldPrice = estateOwner.SetEstateRentPrice(newPrice);
    std::cout << "EstateRentPrice Changes: " << oldPrice << " -> " << newPrice << std::endl;
}

int main() {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaraunt restaraunt;

    BusinessMediator mediator(estateOwner, groceryStore, restaraunt);

    SupplyGrocery(groceryStore, 2);
    groceryStore.Sell();
    BuyFood(restaraunt);
    BuyFood(restaraunt);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeEstateRentPrice(estateOwner, 1000);
    BuyFood(restaraunt);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaraunt;
    ChangeEstateRentPrice(estateOwner, 100000);
    BuyFood(restaraunt);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeGroceryPrice(groceryStore, 100);
    BuyFood(restaraunt);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaraunt);
    ChangeGroceryPrice(groceryStore, -100);
    BuyFood(restaraunt);
    BuyFood(restaraunt);
}
