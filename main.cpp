/*
    Final:
        1. Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure.
            The linked list's struct should be a node that contains the customer's name and drink order.
            Create data arrays with names and drink orders from which to randomly create customer data.
            Run the simulation for 10 rounds. Initialize the queue with 3 customers.
            For any given round, there's a 50% probability that someone will join the queue.
            The customer at the head of the queue is always served in each round.
            If the queue is currently empty, no customer is served, but there is still a 50% probability that someone will join the queue.
        2. Now there's another vendor selling muffins in the next booth over. Add code to simulate that booth's queue.
            This time, use an std::deque. Incorporate this new booth into the 10-round simulation. The probabilities are the same.
        3. Now there's a third vendor selling friendship bracelets in the next booth over. Add this simulation as well using an std::vector.
        4. Now, there's a fourth vendor selling something of your choice;
            add this using a data structure of your choice that hasn't yet been used in this project.
        5. At this point, each round should show queue activity for all four booths.
        6. Invent data to populate the data structures, and use a struct as your object in the non-linked-list data structures
            (similar to the linked list struct, just this one will have no pointer at all).
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include <vector>
#include "CoffeeBooth.h"
#include "MuffinBooth.h"
#include "BraceletBooth.h"
#include "KnickKnackBooth.h"
using namespace std;

// Values to populate
const vector<string> FIRST_NAMES = {"Emma", "Olivia", "Ava", "Sophia", "Mia", "James", "Lucas", "Ethan", "Mason", "Liam"};
const vector<string> LAST_NAMES = {"Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas"};

int main()
{
    // Create a CoffeeBooth and pass names to populate data
    CoffeeBooth coffeeBooth(FIRST_NAMES, LAST_NAMES);
    // Create a MuffinBooth and pass names to populate data
    MuffinBooth muffinBooth(FIRST_NAMES, LAST_NAMES);
    // Create a BraceletBooth and pass names to populate data
    BraceletBooth braceletBooth(FIRST_NAMES, LAST_NAMES);
    // Create a KnickKnackBooth and pass names to populate data
    KnickKnackBooth knickKnackBooth(FIRST_NAMES, LAST_NAMES);

    // Run iterations
    for (size_t i = 0; i < 10; i++)
    {
        cout << "========== ITERATION " << i + 1 << " ==========\n";
        // Output coffee booth queue and iterate
        cout << coffeeBooth.queueToString() << "\n"
             << endl;
        coffeeBooth.iterate();
        // Output muffin booth queue and iterate
        cout << muffinBooth.queueToString() << "\n"
             << endl;
        muffinBooth.iterate();
        // Output bracelet booth queue and iterate
        cout << braceletBooth.queueToString() << "\n"
             << endl;
        braceletBooth.iterate();
        // Output knick knack booth queue and iterate
        cout << knickKnackBooth.queueToString() << "\n"
             << endl;
        knickKnackBooth.iterate();
    }

    return 0;
}