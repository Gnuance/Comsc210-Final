/*
    Bracelet Booth: Creates rand() customers and bracelets. Utilizes vector to hold values.
*/

#ifndef BRACELETBOOTH_H
#define BRACELETBOOTH_H
#include <iostream>
#include <vector>
using namespace std;

class BraceletBooth
{
private:
    // Vectors and arrays to populate customer info
    vector<string> firstNames;
    vector<string> lastNames;
    static const int BRACELET_LIST_SIZE = 8;
    const string BRACELET_LIST[BRACELET_LIST_SIZE] = {"Charm Bracelet", "Bangle", "Cuff Bracelet", "Friendship Bracelet", "Beaded Bracelet", "Leather Bracelet", "Tennis Bracelet", "Hinged Bracelet"};

    // Struct representing individual customer
    struct Customer
    {
        string name;
        string braceletName;
    };

    // Representing a Customer
    Customer customer;
    // Customer queue
    vector<Customer> queue;

public:
    // Constructor with name vectors to dynamically create customers
    BraceletBooth(const vector<string> &fNames, const vector<string> &lNames)
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
        customer.braceletName = BRACELET_LIST[rand() % BRACELET_LIST_SIZE];

        queue.push_back(customer);
    }

    // Iterates one round of service
    void iterate()
    {
        // Front customer always get's served and 50% chance of new customer added
        if (!queue.empty())
        {
            queue.erase(queue.begin());
        }
        if ((rand() % 100) >= 50) // 50% chance of adding customer
        {
            addRandCustomer();
        }
    }

    // Setters and getters
    string queueToString() const
    {
        string output = "Bracelet Booth Queue:";
        for (Customer c : queue)
        {
            output += "\n\t" + c.name + " (" + c.braceletName + ")";
        }
        return output;
    }

    // Write overloaded < operator for the std::list
    // Necessary for set to compare objects
    // bool operator<(const Goat &g) const { return name < g.name; }
};

#endif