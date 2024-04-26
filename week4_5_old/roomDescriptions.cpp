#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Room.hpp"
#include "Item.hpp"


std::vector<std::string> loadItemInformation(std::string Item_name){ // the function with the Item_name entered
    //open file with items and their information
    // search for the item name in the file
    // return the information of the item, both item name and item description
    std::vector<std::string> itemInfo;
    std::ifstream Item_file;
    Item_file.open("allItems.txt", std::ios::in);
    if (!Item_file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }
    std::string line;
    while (std::getline(Item_file, line)) {
        if (line.find(Item_name) != std::string::npos) {
            size_t semicolon = line.find(";");
            if (semicolon != std::string::npos) {
                std::string item_name = Item_name;
                std::string item_description = line.substr(semicolon + 1);
                itemInfo.push_back(item_name);
                itemInfo.push_back(item_description);
                return itemInfo;
            }
        }
    }
    std::cerr << "Item not found!" << std::endl;
    return itemInfo;
}

std::vector<std::string> loadRoomInformation(std::string Room_name){ // the function with the room name entered
    //open file with rooms and their information
    // search for the room name in the file
    // return the information of the room, both room name and room description
    //I may need area for the direction, I will see if I need to add it
    std::vector<std::string> roomInfo;
    std::ifstream Room_file;
    Room_file.open("allRooms.txt", std::ios::in);
    if (!Room_file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }
    std::string line;
    while (std::getline(Room_file, line)) {
        if (line.find(Room_name) != std::string::npos) { // Correctly checks if Room_name is in the line
            size_t semicolon = line.find(";");
            if (semicolon != std::string::npos) { // Also check if the semicolon is found to avoid potential errors
                std::string room_name = Room_name;
                std::string room_description = line.substr(semicolon + 1);
                roomInfo.push_back(room_name);
                roomInfo.push_back(room_description);
                return roomInfo;
            }
        }
    }
    std::cerr << "Room not found!" << std::endl;
    return roomInfo;
}

Item createItem(std::string Item_name){ //the function with the Item_name entered

    std::vector<std::string> itemInfo = loadItemInformation(Item_name); // vector of the information of the item
    std::string item_name = itemInfo[0];
    std::string item_description = itemInfo[1];

    Item item(item_name, item_description); // create object of item
    return item; // return object
}


Room createRoom(std::vector<Item> roomItems, std::string Room_name){ // the function with the roomItems entered for item in each room
    std::vector<std::string> roomInfo = loadRoomInformation(Room_name);
    std::string room_name = roomInfo[0];
    std::string room_description = roomInfo[1];

    Room room(room_description, room_name); // create object of room

    for (const auto& item : roomItems) {
        room.addItem(item);
    } // load the items for this room
    // then loop through through vector provided and add each item to the room
    return room; // return the room
}
//now use Area to be able to add room objects to the map
// std::map <std::string, Room*> rooms; // Map to hold room objects I need to add the room objects to the map
//use function addRoom to add the room objects to the map
//you will likely need to edit Area.cpp to make sure that the directions are loaded correctly

//I will also want to create a file to create a counter of the ammount of times entered a room which uses a map
    // I also want to make a kill count to see how many times the user has killed
//I want to create a file that will be header and then cpp for actions like, attack sequence or adding, removing, or using items, or recieving damage

//figure out how the direction and map thingy work and try to get the code to work a bit