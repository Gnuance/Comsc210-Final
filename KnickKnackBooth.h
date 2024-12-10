/*
    Coffee Booth: Creates rand() customers and drinks. Utilizes linked list to hold values.
*/

#ifndef KNICKKNACKBOOTH_H
#define KNICKKNACKBOOTH_H
#include <iostream>
#include <list>
#include <vector>
#include <forward_list>
using namespace std;

class KnickKnackBooth
{
private:
    // Vectors and arrays to populate customer info
    vector<string> firstNames;
    vector<string> lastNames;
    static const int KNICK_KNACK_LIST_SIZE = 8;
    const string KNICK_KNACK_LIST[KNICK_KNACK_LIST_SIZE] = {"Figurine", "Snow Globe", "Vase", "Picture Frame", "Trinket Box", "Keychain", "Coaster", "Candlestick"};

    // Struct representing individual customer
    struct Customer
    {
        string name;
        string knickKnackName;
    };

    // Representing a Customer
    Customer customer;
    // Customer queue
    forward_list<Customer> queue;

public:
    // Constructor with name vectors to dynamically create customers
    KnickKnackBooth(const vector<string> &fNames, const vector<string> &lNames)
    {
        firstNames = fNames;
        lastNames = lNames;
        for (size_t i = 0; i < 3; i++)
        {
            addRandCustomer();
        }
    }

    // Adds a random customer
    void addRandCustomer()
    {
        // Create customer name and drink
        customer.name = firstNames.at(rand() % firstNames.size()) + " " + lastNames.at(rand() % lastNames.size());
        customer.knickKnackName = KNICK_KNACK_LIST[rand() % KNICK_KNACK_LIST_SIZE];

        queue.push_front(customer);
    }

    // Iterates one round of service
    void iterate()
    {
        // Front customer always get's served and 50% chance of new customer added
        if (!queue.empty())
        {
            // auto it = queue.begin();  
            // while (it != queue.end())
            // {
            //     it++;
            // }
            // prev(it);                      
            // queue.remove(*it);
        }
        if ((rand() % 100) >= 50) // 50% chance of adding customer
        {
            addRandCustomer();
        }
    }

    // Setters and getters
    string queueToString() const
    {
        string output = "Knick Knack Booth Queue:";
        for (auto it = queue.cbegin(); it != queue.cend(); it++)
        {
            output += "\n\t" + it->name + " (" + it->knickKnackName + ")";
        }
        return output;
    }

    // Write overloaded < operator for the std::list
    // Necessary for set to compare objects
    // bool operator<(const Goat &g) const { return name < g.name; }
};

#endif