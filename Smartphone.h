///////////////////////////////////////////////////////////////////////////
// File Name: smartphone.h
// Group Number: 14
// Group Members Names : iqreet kaur, navdisha bhakri
// Group Members Seneca Email : ikaur80@myseneca.ca, nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include "Product.h"
using namespace std;


class Smartphone : public Product
{
private:
    string operatingSystem;
    int storageCapacity;
    int batteryCapacity;

public:

    //Constructors
    Smartphone();
    Smartphone(
        const string& brand,
        const string& model,
        const double& basePrice,
        const string& serialNumber,
        const string& operatingSystem,
        const int& storageCapacity,
        const int& batteryCapacity);

    // Getter method for price, utilizing calculatePrice()
    const double getPrice();
    double calculatePrice();

    // Overloaded equality operator to compare Smartphone objects
    bool operator==(const Product& other);
    const string getCategory() const override;

    // Conversion operator to convert Smartphone object to string for display
    operator string() override;
    void displayDetails();

   // Getter and setter methods for operating system
    const string getOperatingSystem() const;
    void setOperatingSystem(const string& operatingSystem);

    // Getter and setter methods for storage capacity
    const int getStorageCapacity() const;
    void setStorageCapacity(const int& storageCapacity);

    // Getter and setter methods for battery capacity
    const int getBatteryCapacity() const;
    void setBatteryCapacity(const int& batteryCapacity);

    // Destructor
    ~Smartphone();
};

#endif // SMARTPHONE_H