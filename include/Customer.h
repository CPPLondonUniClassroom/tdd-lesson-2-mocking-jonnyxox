#pragma once

#include "interface/ICustomer.h"

class Customer : public ICustomer {
public:
    std::string name;
    std::string address;
    std::vector<std::unique_ptr<IRentable>> rented;
    Money balance{0,0};

    Customer(std::string _name, std::string _address);

    const std::string& Name() const override;
    const std::string& Address() const override;
    Money Balance() const override;
    const std::vector<std::unique_ptr<IRentable>>& Rentals()const override;

    void AssignRental(std::unique_ptr<IRentable> item) override;

    std::unique_ptr<IRentable> RemoveRental(size_t i) override;

    void AdjustBalance(Money amount) override;
};