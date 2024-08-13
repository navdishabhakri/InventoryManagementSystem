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

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product
{
public:
	
	//Constructors
	Product();
	Product(
		const string &brand,
		const string &model,
		const double &price,
		const string &serialNumber);

	// Getters
	const string getBrand() const;
	const string getModel() const;
	virtual const double getPrice();
	const string getSerialNumber() const;

	//Setters
	void setBrand(const string &brand);
	void setModel(const string &model);
	void setPrice(const double &price);
	void setSerialNumber(const string &serialNumber);

	//Comparison operator
	virtual bool operator==(const Product &other);

	//Conversion Operator
	virtual operator string() = 0;

	//Destructor
	virtual ~Product();

	//Get category method
	virtual const string getCategory() const = 0;

private:
	//Member variables
	string brand;
	string model;
	double price;
	string serialNumber;
};

#endif // PRODUCT_H
