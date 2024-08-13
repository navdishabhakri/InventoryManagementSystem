 ///////////////////////////////////////////////////////////////////////////
// File Name: product.cpp
// Group Number: 14
// Group Members Names : iqreet kaur, navdisha bhakri
// Group Members Seneca Email : ikaur80@myseneca.ca, nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#include <iostream>
#include "Product.h"
using namespace std;

// Default constructor
Product::Product() {
	brand = "";
	model = "";
	price = 0;
	serialNumber = "";
}

// Parameterized constructor
Product::Product(const string& brand, const string& model, const double& price, const string& serialNumber) {
	this->brand = brand;
	this->model = model;
	this->price = price;
	this->serialNumber = serialNumber;
}

// Getter method for brand
const string Product::getBrand() const{
	return brand;
}

// Getter method for model
const string Product::getModel() const {
	return model;
}

// Getter method for price
const double Product::getPrice() {
	return price;
}

// Getter method for serial number
const string Product::getSerialNumber() const {
	return serialNumber;
}

// Setter method for brand
void Product::setBrand(const string& brand) {
	this->brand = brand;
}

// Setter method for model
void Product::setModel(const string& model) {
	this->model = model;
}

// Setter method for price
void Product::setPrice(const double& price) {
	this->price = price;
}

// Setter method for price
void Product::setSerialNumber(const string& serialNumber) {
	this->serialNumber = serialNumber;
}

// Overloaded equality operator to compare Product objects
bool Product::operator==(const Product& other) {
	bool retval = true;

	if (this->brand != other.brand) { retval = false; }
	if (this->model != other.model) { retval = false; }
	if (this->serialNumber != other.serialNumber) { retval = false; }

	return retval;
}

// Destructor
Product::~Product() {
	brand = "";
	model = "";
	price = 0;
	serialNumber = "";
}