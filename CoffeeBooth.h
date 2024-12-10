/*
    Coffee Booth: Creates rand() customers and drinks. Utilizes linked list to hold values.
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
    // Vectors and arrays to populate customer info
    static vector<string> firstNames;
    static vector<string> lastNames;
    static const int DRINK_LIST_SIZE = 8;
    const string DRINK_LIST[DRINK_LIST_SIZE] = {"Tea", "Coffee", "Sprite", "Milk", "Orange Juice", "Pepsi", "Grape Drink", "Pocari Sweat"};

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

public:
    // Constructor with name vectors to dynamically create customers
    CoffeeBooth(const vector<string> &fNames, const vector<string> &lNames)
    {
        CoffeeBooth::firstNames = fNames;
        CoffeeBooth::lastNames = lNames;
        for (size_t i = 0; i < 3; i++)
        {
            addRandCustomer();
        }
    }

    // Adds a random customer
    void addRandCustomer()
    {
        // Create customer name and drink
        customer.name = CoffeeBooth::firstNames.at(rand() % CoffeeBooth::firstNames.size()) + " " + CoffeeBooth::lastNames.at(rand() % CoffeeBooth::lastNames.size());
        customer.drinkName = DRINK_LIST[rand() % DRINK_LIST_SIZE];

        queue.push_back(customer);
    }

    // Iterates one round of service
    void iterate()
    {
        // Front customer always get's served and 50% chance of new customer added
        if (!queue.empty())
        {
            queue.pop_front();
        }
        if ((rand() % 100) >= 50) // 50% chance of adding customer
        {
            addRandCustomer();
        }
    }

    // Setters and getters
    string queueToString() const
    {
        string output = "Coffee Booth Queue:";
        for (Customer c : queue)
        {
            output += "\n\t" + c.name + " (" + c.drinkName + ")";
        }
        return output;
    }

    // Write overloaded < operator for the std::list
    // Necessary for set to compare objects
    // bool operator<(const Goat &g) const { return name < g.name; }
};

#endif