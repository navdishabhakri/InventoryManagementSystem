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

#ifndef INVENTORY_H
#define INVENTORY_H


#include <iostream>
#include <string>

#include "Laptop.h"
#include "Smartphone.h"


template <typename T>
class Inventory {
private:
    T* items;
    int capacity;
    int count;

public:

    //Constructor
    Inventory() {
        capacity = 4;
        count = 0;
        items = new T[capacity];
    }

    //Destructor
    ~Inventory() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
        delete[] items;
        capacity = 4;
        count = 0;
        items = nullptr;
    }

    // Overloaded operator + to add an item to inventory
    Inventory& operator+(const T item) {
        if (count < capacity) {
            items[count] = item;
            count++;
        }
        else {
            capacity = capacity * 2;
            T* temp = new T[capacity];
            for (int i = 0; i < count; i++) {
                temp[i] = items[i];
            }
            if (count < capacity) {
                temp[count] = item;
                count++;
            }
            delete[] items;
            items = temp;
        }
        return *this;
    }


    // Overloaded operator - to remove an item from inventory
    Inventory& operator-(const T itemToRemove) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getCategory() == itemToRemove->getCategory()) {
                if (items[i]->operator==(*itemToRemove)) {
                    
                    delete items[i];
                    items[i] = nullptr;

                    for (int j = i; j < count - 1; j++) {
                        items[j] = items[j + 1];
                    }
                    count--;
                    break;
                }
            }
        }
        return *this;

    }

     // Count items by category
    int countByCategory(const std::string& category) const {
        int count = 0;
        for (int i = 0; i < this->count; i++) {
            if (items[i]->getCategory() == category) {
                count++;
            }
        }
        return count;
    }

     // Calculate total value of items in inventory
    double calculateTotalValue() const {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->getPrice();
        }
        return total;
    }

    // Get current size of inventory
    int size() const {
        return count;
    }

    // Display inventory items by category
    void displayInventoryByCategory(const std::string& category) const {
        for (int i = 0; i < count; i++) {
            if (items[i]->getCategory() == category) {
                std::cout << (std::string)*items[i] << std::endl;
            }
        }
    }
};



#endif // INVENTORY_H
