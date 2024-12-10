/*
    Coffee Booth: Utilizes linked list to hold values
*/

#ifndef COFFEEBOOTH_H
#define COFFEEBOOTH_H
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class CoffeeBooth
{
private:
    // Struct representing individual customer
    struct Customer
    {
        string name;
        string drinkName;
    };

    // Representing a Customer
    Customer customer;
    // Customer queue
    list<Customer> queue;
    // Vectors and arrays to populate customer info
    vector<string> firstNames;
    vector<string> lastNames;
    const string drinkList[8] = {"Tea", "Coffee", "Sprite", "Milk", "Orange Juice", "Pepsi", "Grape Drink", "Pocari Sweat"};

public:
    CoffeeBooth() {}
    // Constructor with name vectors to dynamically create customers
    CoffeeBooth(const vector<string> &fNames, const vector<string> &lNames)
    {
        firstNames = fNames;
        lastNames = lNames;
    }

    void addRandCustomer()
    {
        // Create customer name and drink
        customer.name = firstNames.at(rand() % firstNames.size()) + lastNames.at(rand() % lastNames.size());
        customer.drinkName = drinkList[rand() % 8];

        queue.push_back(customer);
    }

    // Setters and getters
    string queueToString() const
    {
        string output = "Coffee Booth Queue:";
        for (Customer c : queue)
        {
            output += "\n" + c.name + " (" + c.drinkName + ")";
        }
        return output;
    }

    // Write overloaded < operator for the std::list
    // Necessary for set to compare objects
    // bool operator<(const Goat &g) const { return name < g.name; }
};

#endif