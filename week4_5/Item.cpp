#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.hpp"


Item::Item(const std::string& name, const std::string& description) {
    this->item_name = name;
    this->item_description = description;
}


std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Item Name: " << item.getName();
    // Add more item details to output as needed
    return os;
}

void Item::interact() { // Interact with the item
        std::cout << "You have interacted with " << item_name << ". It is: " << item_description << std::endl;
};

std::string Item::getName() const { // Get the name of the item
    return item_name;
};