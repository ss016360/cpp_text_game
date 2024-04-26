#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.hpp"

Room::Room(const std::string& description, const std::string& name) {
    this->room_description = description;
    this->room_name = name;
    this->exits = std::map<std::string, Room*>();
}

void Room::setExit(const std::string& direction, Room* room) {
    // Set the exit of the room in the specified direction
    exits[direction] = room;
}

void Room::addItem(const Item& item) { // Add an item to the room
    Items.push_back(item);
};

void Room::removeItem(const Item& item) { // Remove an item from the inventory
    for (int i = 0; i < Items.size(); i++) {
        if (Items[i] == item) {
            Items.erase(Items.begin() + i);
        };
    };
};

std::vector<Item>& Room::getItems() { // Get the items vector from that specific room
    return Items;
};

std::string Room::getDescription() { // Get the description of the room
    return room_description;
};

std::string Room::getName() { // Get the name of the room
    return room_name;
};

Room* Room::getExits(const std::string direction) { // Get the exits for the room
    std::map<std::string, Room*>::iterator it = exits.find(direction);
    std::cout << "You have chosen to go " << direction << std::endl;
    std::cout << "Exit: " << exits[direction] << std::endl;
    //std::cout << "Exit 1: " << exits[0] << std::endl;
    if (it == exits.end()) {
        std::cout << "There is no exit in that direction." << std::endl;
        return nullptr;
    }
    else {
        std::cout << "You have chosen to go " << direction << std::endl;
        std::cout << "Exits!: " << exits[direction] << std::endl;
        return exits[direction];
    }
};