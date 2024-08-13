///////////////////////////////////////////////////////////////////////////
// File Name: smartphone.cpp
// Group Number: 14
// Group Members Names : iqreet kaur, navdisha bhakri
// Group Members Seneca Email : ikaur80@myseneca.ca, nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#include "Smartphone.h"
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

//Default Constructor
Smartphone::Smartphone() : Product::Product() {
    operatingSystem = "";
    storageCapacity = 0;
    batteryCapacity = 0;

} 

// Parameterized constructor
Smartphone::Smartphone(
    const std::string& brand, 
    const std::string& model, 
    const double& basePrice, 
    const std::string& serialNumber, 
    const std::string& operatingSystem, 
    const int& storageCapacity, 
    const int& batteryCapacity) : Product::Product(brand, model, basePrice, serialNumber) {
    
    this->operatingSystem = operatingSystem;
    this->storageCapacity = storageCapacity;
    this->batteryCapacity = batteryCapacity;
}

// Getter method for price, utilizing calculatePrice()
const double Smartphone::getPrice() {
    return calculatePrice();
}

// Calculate price method for a smartphone, considering storage and battery capacities
double Smartphone::calculatePrice() {
    return (Product::getPrice() + (this->storageCapacity * 0.75) + (this->batteryCapacity * 0.05));
}

// Overloaded equality operator to compare Smartphone objects
bool Smartphone::operator==(const Product& other) {

    Smartphone otherSmartphone = dynamic_cast<const Smartphone&>(other);
    if (Product::operator==(other) &&
        this->operatingSystem == otherSmartphone.operatingSystem &&
        this->storageCapacity == otherSmartphone.storageCapacity &&
        this->batteryCapacity == otherSmartphone.batteryCapacity) {return true;}
    else {return false;}
}

// Getter method for category
const std::string Smartphone::getCategory() const {
    return "Smartphone";
}

// Conversion operator to convert Smartphone object to string for display
Smartphone::operator string()
{
    stringstream ss;
    ss << "| " << setw(10) << left << Product::getBrand() << " | " 
    << setw(20) << left << Product::getModel() << " | " 
    << setw(8) << right << fixed << setprecision(2) << this->getPrice() << " | " 
    << setw(10) << right << Product::getSerialNumber() << " | " 
    << setw(15) << right << operatingSystem << " | " 
    << setw(10) << right << storageCapacity << "GB | " 
    << setw(10) << right << batteryCapacity << "mAh|" << endl;

    return ss.str();
}

// Display details of Smartphone object
void Smartphone::displayDetails()
{
    cout << string(*this);
}

// Getter and setter methods for operating system
const std::string Smartphone::getOperatingSystem() const {
    return operatingSystem;
}
void Smartphone::setOperatingSystem(const std::string& operatingSystem) {
    this->operatingSystem = operatingSystem;
}

// Getter and setter methods for storage capacity
const int Smartphone::getStorageCapacity() const {
    return storageCapacity;
}
void Smartphone::setStorageCapacity(const int& storageCapacity) {
    this->storageCapacity = storageCapacity;
}

// Getter and setter methods for battery capacity
const int Smartphone::getBatteryCapacity() const {
    return batteryCapacity;
}
void Smartphone::setBatteryCapacity(const int& batteryCapacity) {
    this->batteryCapacity = batteryCapacity;
}

// Destructor 
Smartphone::~Smartphone() {
    this->operatingSystem = "";
    this->storageCapacity = 0;
    this->batteryCapacity = 0;
}