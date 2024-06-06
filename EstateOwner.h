#ifndef ESTATE_OWNER_H
#define ESTATE_OWNER_H

#include "BusinessMediator.h"

class EstateOwner {
public:
    std::int32_t SetEstateRentPrice(std::int32_t price);
    BusinessMediator* SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator);

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t estateRentPrice_{ 10000 };
};

#endif // ESTATE_OWNER_H
