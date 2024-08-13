
// To test and run your code on the virtual machine using the command line, you can use the following steps.
// First, make sure you are in the correct directory, then compile the code using the following commands
// to compile and then run your code.
// To Compile: g++ -Wall -std=c++17 -g -o a1 Product.cpp Smartphone.cpp Laptop.cpp Utilities.cpp Inventory.h a1main.cpp
// To Run: ./a1
// After compiling and testing your code, run your program as following
// to check for possible memory leaks (assuming your executable name is a1):
// To check memory leaks: valgrind --leak-check=yes ./a1

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

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Product.h"
#include "Smartphone.h"
#include "Laptop.h"

/**
 * This is the main function that processes the data files and displays the inventory
 * This function is partially implemented, and it is your task to complete the implementation
 * read the TODOs in the main function and complete the implementation
 * It is important to read the lab instructions to understand the program's functionality
 * It is important to study the sample output to understand the expected program output
 */

int main()
{

    // Create an inventory to store the products (Already implemented for you do not modify)
    Inventory<Product *> inventory;
    // Process Laptops and Smartphones data files
    processFile(inventory, "laptops_data.txt", "Laptop");         // Already implemented for you do not modify
    processFile(inventory, "smartphones_data.txt", "Smartphone"); // Already implemented for you do not modify

    // TODO: Check the sample output and complete the implementation of the main function
    // TODO: Display the inventory total value, the number of laptops and smartphones in the inventory
    // The inventory total value should be displayed  with two decimal places

    cout << "-----------------------------------------" << endl;
    cout << "Total inventory value: $" << fixed << setprecision(2) << inventory.calculateTotalValue() << endl;
    cout << "Number of laptops: " << inventory.countByCategory("Laptop") << endl;
    cout << "Number of smartphones: " << inventory.countByCategory("Smartphone") << endl;
    cout << "-----------------------------------------" << endl;

    // TODO: display the list of laptops and smartphones in the inventory
    //  Check the sample output for the expected output to verify your implementation

    // Display the laptops in the inventory
    std::cout << "-----------------------------------------\n";
    std::cout << "Laptops in the inventory:\n";
    std::cout << "-----------------------------------------\n";
    // TODO:  display the list of laptops in the inventory

    inventory.displayInventoryByCategory("Laptop");

    // display the smartphones in the inventory
    std::cout << "-----------------------------------------\n";
    std::cout << "Smartphones in the inventory:\n";
    std::cout << "-----------------------------------------\n";
    // TODO: display the list of smartphones in the inventory

    inventory.displayInventoryByCategory("Smartphone");

    std::cout << "-----------------------------------------\n";

    // TODO: create a new product and add it to the inventory
    // TODO: Create a new laptop with the following data: "Dell,XPS 15,1500.00,SN87654321,Intel Core i7,16"
    // TODO: Create a new smartphone with the following data: "Samsung,Galaxy S20,999.99,SN12345678,Android,128,3000"
    // TODO: Add the new laptop and smartphone to the inventory
    // TODO: Display the inventory total value, the number of laptops and smartphones in the inventory
    // After adding the newly created products (Check the sample output) to verify your implementation

    Product *newLaptop = new Laptop("Dell", "XPS 15", 1500.00, "SN87654321", "Intel Core i7", 16);
    Product *newPhone = new Smartphone("Samsung", "Galaxy S20", 999.99, "SN12345678", "Android", 128, 3000);

    inventory + newLaptop;
    inventory + newPhone;

    cout << "-----------------------------------------" << endl;
    cout << "Total inventory value: $" << fixed << setprecision(2) << inventory.calculateTotalValue() << endl;
    cout << "Number of laptops: " << inventory.countByCategory("Laptop") << endl;
    cout << "Number of smartphones: " << inventory.countByCategory("Smartphone") << endl;
    cout << "-----------------------------------------" << endl;

    // TODO: Remove a product from the inventory
    // TODO: Create a laptop object with the following "Lenovo,ThinkPad X1 Carbon,1800.00,SN200003,Intel Core i7,16"
    // Then remove the newly created laptop from the inventory
    // TODO: display the inventory total value, the number of laptops in the inventory
    // TODO: display the list of laptops in the inventory
    // It is important to check the sample output to verify your implementation

    Product *laptopToRemove = new Laptop("Lenovo", "ThinkPad X1 Carbon", 1800.00, "SN200003", "Intel Core i7", 16);
    inventory - laptopToRemove;

    cout << "-----------------------------------------" << endl;
    cout << "Total inventory value: $" << fixed << setprecision(2) << inventory.calculateTotalValue() << endl;
    cout << "Number of laptops: " << inventory.countByCategory("Laptop") << endl;
    cout << "-----------------------------------------" << endl;

    inventory.displayInventoryByCategory("Laptop");

    // TODO: Create a new product and remove it from the inventory
    // TODO: Create a new smartphone with the following data: "Google,Pixel 5,699.99,SN112233,Android,128,4080"
    // Then remove the newly created smartphone from the inventory
    // TODO: display the inventory total value, the number of smartphones in the inventory
    // TODO: display the list of smartphones in the inventory
    // It is important to check the sample output to verify your implementation

    Product *phoneToRemove = new Smartphone("Google", " Pixel 5", 699.99, "SN112233", "Android", 128, 4080);
    inventory - phoneToRemove;

    cout << "-----------------------------------------" << endl;
    cout << "Total inventory value: $" << fixed << setprecision(2) << inventory.calculateTotalValue() << endl;
    cout << "Number of smartphones: " << inventory.countByCategory("Smartphone") << endl;
    cout << "-----------------------------------------" << endl;

    inventory.displayInventoryByCategory("Smartphone");

    // TODO: make sure you carefully manage the memory allocation and deallocation
    // to avoid any memory leaks

    return 0;
}

