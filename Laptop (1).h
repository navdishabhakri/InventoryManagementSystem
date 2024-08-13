///////////////////////////////////////////////////////////////////////////
// File Name: inventory.h
// Name: navdisha bhakri
// Seneca Email : nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#ifndef LAPTOP_H
#define LAPTOP_H

// This include the product  header file
#include "Product.h"
#include <iostream>

// TODO: in this file, declare the class Laptop, which is a derived (inherited) Product
// The class laptop derived from product
class Laptop : public Product
{
private:
    std::string cpu;
    int ram;

public:
    // default  contructor
    Laptop();

    // parmetrized constructor
    Laptop(
        const std::string& brand,
        const std::string& model,
        const double& basePrice,
        const std::string& serialNumber,
        const std::string& cpu,
        const int& ram);

    // cpu
    const std::string getCpu() const;
    void setCpu(const std::string& cpu);

    // ram
    const int getRam() const;
    void setRam(const int& ram);

    // price
    const double getPrice();
    double calculatePrice();

    // string operations
    operator std::string() override;
    void displayDetails();

    //miscaleanous
    const std::string getCategory() const override;
    bool operator==(const Product& other);

    //destructor
    ~Laptop();
};

// The implementation for the class Laptop should be in Laptop.cpp
// Read the assignment instructions carefully to know what you should do in this file
// Add your code here

#endif // LAPTOP_H
