///////////////////////////////////////////////////////////////////////////
// File Name: utilities.h
// Group Number: 14
// Group Members Names : iqreet kaur, navdisha bhakri
// Group Members Seneca Email : ikaur80@myseneca.ca, nbhakri@myseneca.ca
// Date : 31 march 2024
// Authenticity Declaration :
// I declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//////////////////////////////

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Inventory.h"
using namespace std;

//// Forward declaration of Product class
class Product;

// Function to create a product based on category and data
Product* createProduct(const std::string& category, const std::string& data);

// Function template to process a file and populate inventory
template<typename T>
void processFile(Inventory<T>& inventory, const std::string& filePath, const std::string& category) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        T product = createProduct(line, category);
        if (product == nullptr) {
            std::cerr << "Failed to create product from line: " << line << std::endl;
            continue;
        }
        inventory + product;
    }

    file.close();
}

#endif // !UTILITIES_H