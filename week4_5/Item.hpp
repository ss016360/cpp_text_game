#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>

class Item {
    private:
    std::string item_name; // Name of the item
    std::string item_description; // Description of the item

    public:
    Item(const std::string& name, const std::string& description); // Constructor for the item
    bool operator==(const Item& other) const { // Overload the == operator
        return item_name == other.item_name;
    };
    void interact(); // Interact with the item
    std::string getName() const; // Get the name of the item
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};
#endif