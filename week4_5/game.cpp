#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Character.hpp"
#include "Room.hpp"
#include "Item.hpp"
#include "Area.hpp"
#include "roomDescriptions.hpp"

#include <iostream> // Include the necessary header file for the 'Player' class

void mainActionSequence(Player& player, Area& area, Room* room) {
    std::cout << "Player's health: " << player.Player::getHealth() << std::endl;

    std::vector<Item> inventory = player.Player::getInventory();

    std::cout << "Player's inventory: " << std::endl;
    std::copy(inventory.begin(), inventory.end(), std::ostream_iterator<Item>(std::cout, "\n"));

    std::cout << "You are currently in the - " << room->getName() << ": " << std::endl;
    std::cout << room->getDescription() << std::endl;

    std::vector<Item> items = room->getItems();
    std::cout << "\n Items in the room: " << std::endl;
    std::copy(items.begin(), items.end(), std::ostream_iterator<Item>(std::cout, "\n"));

    std::vector<std::string> directions = {"north", "south", "east", "west"};
    std::vector<std::string> exits_options;
    std::cout << "Exits: " << std::endl;
    for (int i = 0; i < directions.size(); i++) {
        Room* exit = room->getExits(directions[i]);
        if (exit != nullptr) {
            std::cout << directions[i] << " - " << exit->getName() << std::endl;
            exits_options.push_back(directions[i]);
        }
    }

    std::string choice;
    std::cout << "Would you like to: A - change room; B - Interact with inventory; C - Interact with room items; D - do nothing; E - quit. " << std::endl;
    std::cin >> choice;

    if (choice == "A") {
        std::cout << "You have chosen to change rooms." << std::endl;
    } else if (choice == "B") {
        std::cout << "You have chosen to interact with your inventory." << std::endl;
    } else if (choice == "C") {
        std::cout << "You have chosen to interact with the room items." << std::endl;
    } else if (choice == "D") {
        std::cout << "You have chosen to do nothing." << std::endl;
        mainActionSequence(player, area, room);
    } else if (choice == "E") {
        std::cout << "You have chosen to quit." << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter a letter, either A, B, C, D or E." << std::endl;
        mainActionSequence(player, area, room);
    }

}

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    Player player(name, 100);
    Area area;

    // Create Rooms
    std::vector<std::vector<std::string> > item_names = {{"Ethereal Whisperer", "Chronicles of Eternity"}, {"Crystalline Bloom", "Veil of Shadows"}, {"Whispering Grove Sapling"}, {"Inferno Blade", "Sentinel's Eye"}, {"Alehorn of Endless Revelry", "Scepter of Kings"}, {"Cursed Gold"}, {"Coral Whisperer", "Pearl of Tides"}, {"Seaweed Shroud", "Trident of the Depths"}, {"Siren's Lullaby"}, {"Warrior's Fury Gauntlets", "Totem of the Ancestors"}, {"Alehorn of Valor", "Shaman's Vision Staff"}, {"Flameforged Battleaxe"}};
    std::vector<std::string> room_names = {"Room of Tranquility", "Library of Wisdom", "Garden of Serenity", "Forge Hall", "Treasure Vault", "Feasting Hall", "Coral Sanctuary", "Pearl Chamber", "Seaweed Garden", "Training Grounds", "Shamanic Shrine", "Feast Hall"};

    std::vector<Room> rooms;

    for (int i = 0; i < room_names.size(); i++) {
        std::vector<Item> items;
        for (int j = 0; j < item_names[i].size(); j++) {
            items.push_back(createItem(item_names[i][j]));
        }
        rooms.push_back(createRoom(items, room_names[i]));
        //std::cout << room_names[i] << " created." << std::endl;

        //std::cout << "Room - " << rooms[i].getName() << " :  " << rooms[1].getDescription() << " created." << std::endl;
    }

    for (int i = 0; i < (rooms.size() - 1); i++) {
        area.addRoom(room_names[i], &rooms[i]);
    }

    //area.loadMapFromFile("game_map.txt");

    std::string startingRoomName = room_names[0]; // Set the starting room name to the first room in the list
    std::string endingRoom = room_names[3]; // Set the ending room to the last room in the list

    std::cout << "Starting room: " << startingRoomName << std::endl; // Print the starting room name

    mainActionSequence(player, area, area.getRoom(startingRoomName)); // Call the main action sequence function with the starting room name

    return 0;

}
