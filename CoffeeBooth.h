/*  
    Coffee Booth: Utilizes linked list to hold values
*/

#ifndef COFFEEBOOTH_H
#define COFFEEBOOTH_H
#include <iostream>
using namespace std;

class CoffeeBooth {
private:
    struct Node
    {
        string name;
        string drinkName;
    };
public: 
    CoffeeBooth()                              { name = ""; age = 0; color = ""; }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    // necessary for set to compare objects
    bool operator<(const Goat &g) const   { return name < g.name; }
};

#endif