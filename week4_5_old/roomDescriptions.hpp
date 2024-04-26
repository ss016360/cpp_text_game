#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Room.hpp"
#include "Area.hpp"

// A function to open allRooms.txt and load the rooms into the map
std::vector<std::string> loadItemInformation(std::string Item_name);
std::vector<std::string> loadRoomInformation(std::string Room_name);
Item createItem(std::string Item_name);
Room createRoom(std::vector<Item> roomItems, std::string Room_name);
