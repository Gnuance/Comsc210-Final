/*
    Coffee Booth: Utilizes linked list to hold values
*/

#ifndef COFFEEBOOTH_H
#define COFFEEBOOTH_H
#include <iostream>
#include <list>
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

    // Customer queue
    list<Customer> queue;

public:
    CoffeeBooth() {}
    CoffeeBooth(string[], string[]) {}

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