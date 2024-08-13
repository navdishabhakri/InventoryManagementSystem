///////////////////////////////////////////////////////////////////////////
// File Name: utilities.cpp
// Group Number: 14
// Group Members Names : iqreet kaur, navdisha bhakri
// Group Members Seneca Email : ikaur80@myseneca.ca, nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#include <sstream>
#include <vector>
#include "Product.h"
#include "Laptop.h"
#include "Smartphone.h"

// Function to create a product based on category and data
Product* createProduct(const std::string& data, const std::string& category)
{
    std::istringstream iss(data);
    if (category == "Laptop")
    {
        std::string brand, model, price, serialNumber, cpu, ram;
        std::getline(iss, brand, ',');
        std::getline(iss, model, ',');
        std::getline(iss, price, ',');
        std::getline(iss, serialNumber, ',');
        std::getline(iss, cpu, ',');
        std::getline(iss, ram, ',');

        return new Laptop(brand, model, std::stod(price), serialNumber, cpu, std::stoi(ram));
    }

    else if (category == "Smartphone")
    {
        std::string brand, model, price, serialNumber, operatingSystem, storageCapacity, batteryCapacity;
        std::getline(iss, brand, ',');
        std::getline(iss, model, ',');
        std::getline(iss, price, ',');
        std::getline(iss, serialNumber, ',');
        std::getline(iss, operatingSystem, ',');
        std::getline(iss, storageCapacity, ',');
        std::getline(iss, batteryCapacity, ',');

        return new Smartphone(brand, model, std::stod(price), serialNumber, operatingSystem, std::stoi(storageCapacity), std::stoi(batteryCapacity));
    }

    else
    {
        return nullptr;
    }
}