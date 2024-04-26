#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Character.hpp"

Character::Character(const std::string& name, int initial_value) {
    this->name = name;
    this->health = initial_value;
};

std::vector<Item>& Character::getInventory() {
    return Inventory;
    // Return the inventory
}

int Character::getHealth() {
    return health;
}

void Character::takeDamage(int Damage) { // Take damage
    int health;
    health -= Damage;

    std::cout << "You have taken " << Damage << " damage. Your health is now " << health << std::endl;
};

Player::Player(const std::string& name, int initial_value) : Character(name, initial_value) {
    // Constructor for the player
    this->location = nullptr;
}

void Player::pickUpItem(const Item& item) {
    // Implementation for picking up an item
    getInventory().push_back(item);
    std::cout << "You have picked up " << item.getName() << ".\n";
}

void Player::dropItem(const Item& item) {
    // Implementation for dropping an item
    std::vector<Item> Inventory = getInventory();
    for (int i = 0; i < Inventory.size(); i++) {
        if (Inventory[i] == item) {
            Inventory.erase(Inventory.begin() + i);
            std::cout << "You have dropped " << item.getName() << ".\n";
        };
    };
}

void Player::useItem(const Item& item) {
    // Implementation for using an item
}

void Player::viewInventory() {
    // Implementation for viewing the inventory
    std::vector<Item> Inventory = getInventory();

    // Check if the inventory is empty
    if (Inventory.empty()) {
        std::cout << "Inventory is empty.\n";
    } else {
        std::cout << "Items:\n";
        for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
            const Item& item = *it;
            std::cout << "- " << item.getName() << "\n";
        }
    }
}
