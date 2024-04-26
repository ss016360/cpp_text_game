#ifndef AREA_HPP
#define AREA_HPP
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.hpp"
#include "Character.hpp"
#include "Room.hpp"

class Area {
    private:
    std::map <std::string, Room*> rooms; // Map to hold room objects
    std::string getOppositeDirection(std::string direction);

    public:
    Area(); // Constructor for the area
    void addRoom(const std::string& room_name, Room* room); // Adds a room to the map
    Room* getRoom(const std::string& room_name); // Returns a room from the map
    void connectRooms(const std::string& room1, const std::string& room2, const std::string& direction); // Connects two rooms with a string direction stored in direction
    void loadMapFromFile(const std::string& file_name); // Loads a map from a file
};
#endif