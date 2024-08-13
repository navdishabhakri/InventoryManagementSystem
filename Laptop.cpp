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

#include "Laptop.h"
#include <iostream>
#include <sstream>
#include <iomanip>

//Default Constructor
Laptop::Laptop() : Product::Product()
{
    this->setBrand("");
    this->setModel("");
    this->setPrice(0.0);
    this->setSerialNumber("");
    cpu = "";
    ram = 0;
}

// Parameterized constructor
Laptop::Laptop(
    const std::string &brand,
    const std::string &model,
    const double &basePrice,
    const std::string &serialNumber,
    const std::string &cpu,
    const int &ram) : Product::Product(brand, model, basePrice, serialNumber) {

    this->cpu = cpu;
    this->ram = ram;
}

// Getter and setter methods for CPU
const std::string Laptop::getCpu() const
{
    return cpu;
}
void Laptop::setCpu(const std::string &cpu)
{
    this->cpu = cpu;
}

// Getter and setter methods for RAM
const int Laptop::getRam() const
{
    return ram;
}
void Laptop::setRam(const int &ram)
{
    this->ram = ram;
}

// Calculate price method for a laptop, considering RAM
double Laptop::calculatePrice()
{
    return (Product::getPrice() + (this->ram * 20));
}
// Getter method for price, utilizing calculatePrice()
const double Laptop::getPrice()
{
    return calculatePrice();
}

// Conversion operator to convert Laptop object to string for display
Laptop::operator std::string()
{
    std::stringstream ss;
    ss << "| " << std::setw(10) << std::left << this->getBrand() << " | "
       << std::setw(20) << std::left << this->getModel() << " | "
       << std::setw(8) << std::right << std::fixed << std::setprecision(2) << this->calculatePrice() << " | "
       << std::setw(10) << std::right << this->getSerialNumber() << " | "
       << std::setw(15) << std::right << this->getCpu() << " | "
       << std::setw(10) << std::right << this->getRam() << "GB |\n";

    return ss.str();
}

// Display details of Laptop object
void Laptop::displayDetails()
{
    std::cout << std::string(*this);
}

// Getter method for category
const std::string Laptop::getCategory() const
{
    return "Laptop";
}

// Overloaded equality operator to compare Laptop objects
bool Laptop::operator==(const Product &other)
{
    const Laptop otherLaptop = dynamic_cast<const Laptop&>(other);
    
    if (Product::operator==(other) &&
        this->cpu == otherLaptop.cpu &&
        this->ram == otherLaptop.ram) {return true;}
        
    else {return false;}
}

// Destructor
Laptop::~Laptop()
{
    cpu = "";
    ram = 0;
}
