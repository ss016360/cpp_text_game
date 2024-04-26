#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.hpp"
#include "Room.hpp"

class Character {
    private:
    std::string name; // Name of the character
    int health; // Health of the character

    //protected:
    std::vector<Item> Inventory; // Inventory of the character

    public:
    Character(const std::string& name, int health); // Constructor for the character
    void takeDamage(int Damage); // Take damage
    std::vector<Item>& getInventory(); // Get the inventory
    int getHealth(); // Get the health of the player
};

class Player : public Character{
    private:
    Room* location; // Room the player is in

    public:
    Player(const std::string& name, int initial_value); // Constructor for the player

    void pickUpItem(const Item& item); // Pick up an item
    void dropItem(const Item& item); // Drop an item
    void useItem(const Item& item); // Use an item
    void viewInventory(); // View the inventory

};
#endif