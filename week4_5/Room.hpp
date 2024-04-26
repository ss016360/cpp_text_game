#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.hpp"


class Room {
    private:
    std::string room_description; // Description of the room
    std::string room_name; // Name of the room
    std::map<std::string, Room*> exits; // Map of exits from the room
    std::vector<Item> Items; // Vector of items in the room

    public:
    Room(const std::string& description, const std::string& name); // Constructor for the room

    void addItem(const Item& item); // Add an item to the room
    void removeItem(const Item& item); // Remove an item from the room
    void setExit(const std::string& direction, Room* room); // Set an exit from the room

    std::vector<Item>& getItems(); // Get the items in the room
    std::string getDescription(); // Get the description of the room
    std::string getName(); // Get the name of the room
    Room* getExits(const std::string direction); // Get the exits from the room
};
#endif