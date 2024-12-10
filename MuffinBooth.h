/*
    Muffin Booth: Creates rand() customers and muffins. Utilizes deque to hold values.
*/

#ifndef MUFFINBOOTH_H
#define MUFFINBOOTH_H
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class MuffinBooth
{
private:
    // Vectors and arrays to populate customer info
    vector<string> firstNamesMuffin;
    vector<string> lastNamesMuffin;
    static const int MUFFIN_LIST_SIZE = 8;
    const string MUFFIN_LIST[MUFFIN_LIST_SIZE] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Lemon Poppy Seed", "Cranberry Orange", "Apple Cinnamon", "Pumpkin Spice", "Zucchini"};

    // Struct representing individual customer
    struct Customer
    {
        string name;
        string muffinName;
    };

    // Representing a Customer
    Customer customer;
    // Customer queue
    deque<Customer> queue;

public:
    // Constructor with name vectors to dynamically create customers
    MuffinBooth(const vector<string> &fNames, const vector<string> &lNames)
    {
        firstNamesMuffin = fNames;
        lastNamesMuffin = lNames;
        for (size_t i = 0; i < 3; i++)
        {
            addRandCustomer();
        }
    }

    // Adds a random customer
    void addRandCustomer()
    {
        // Create customer name and drink
        customer.name = firstNamesMuffin.at(rand() % firstNamesMuffin.size()) + " " + lastNamesMuffin.at(rand() % lastNamesMuffin.size());
        customer.muffinName = MUFFIN_LIST[rand() % MUFFIN_LIST_SIZE];

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
        string output = "Muffin Booth Queue:";
        for (Customer c : queue)
        {
            output += "\n\t" + c.name + " (" + c.muffinName + ")";
        }
        return output;
    }

    // Write overloaded < operator for the std::list
    // Necessary for set to compare objects
    // bool operator<(const Goat &g) const { return name < g.name; }
};

#endif