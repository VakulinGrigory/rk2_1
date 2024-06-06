#include "BusinessMediator.h"
#include "EstateOwner.h"
#include "GroceryStore.h"
#include "Restaraunt.h"

BusinessMediator::BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaraunt& restaraunt)
    : estateOwner_(estateOwner), groceryStore_(groceryStore), restaraunt_(restaraunt) {
    estateOwner_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
    groceryStore_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
    restaraunt_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
}

void BusinessMediator::EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    groceryStore_.AlterPrice((newPrice - oldPrice) / 10000);
    restaraunt_.AlterPrice((newPrice - oldPrice) / 1000);
}

void BusinessMediator::GroceryStockChanged(std::int32_t currentStock) {
    if (currentStock > 0) {
        restaraunt_.SetIsOpened(design::AccessKey<BusinessMediator>(), true);
    } else {
        restaraunt_.SetIsOpened(design::AccessKey<BusinessMediator>(), false);
    }
}

void BusinessMediator::GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    restaraunt_.AlterPrice(newPrice - oldPrice);
}

void BusinessMediator::FoodIsCooked() {
    groceryStore_.Sell();
}
