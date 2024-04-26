#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Area.hpp"
#include "Room.hpp"

Area::Area() {
    // Constructor for the area
    loadMapFromFile("game_map.txt");
    this->rooms = std::map<std::string, Room*>();
}

std::string Area::getOppositeDirection(std::string direction) {
    if (direction == "north") {
        return "south";
    } else if (direction == "south") {
        return "north";
    } else if (direction == "east") {
        return "west";
    } else if (direction == "west") {
        return "east";
    } else {
        return "Invalid direction";
    }

}

void Area::connectRooms(const std::string& room1, const std::string& room2, const std::string& direction) {
    // Connects two rooms with a string direction stored in direction
    rooms[room1]->setExit(direction, rooms[room2]);
    rooms[room2]->setExit(direction, rooms[room1]);
}

void Area::addRoom(const std::string& room_name, Room* room) {
    // Adds a room to the map
    rooms[room_name] = room;
}

Room* Area::getRoom(const std::string& room_name) {
    // Returns a room from the map
    auto it = rooms.find(room_name);
    if (it != rooms.end()) {
        // Room found, return the pointer to the room
        return it->second;
    }
    else {
        // Room not found, return nullptr
        return nullptr;
    }
}

//look at this tomorrow
void Area::loadMapFromFile(const std::string& file_name) { 
    // Loads a map from a file
    // give an exapmle of how to use the function
    std::ifstream inputFile(file_name); // Open the file for reading
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string room1Name, room2Name, direction;

        std::getline(lineStream, room1Name, '|');
        std::getline(lineStream, room2Name, '|');
        std::getline(lineStream, direction);

        // Connect rooms
        std::string oppositeDirection = getOppositeDirection(direction);
        connectRooms(room1Name, room2Name, direction);
        connectRooms(room2Name, room1Name, oppositeDirection);
    }

    inputFile.close(); // Close the file

}
