//
// Created by Dan Orel on 1/3/19.
//

#include "War.h"

int Fighter::get_attack_power() {
    return attack_power;
}

int Fighter::get_health_level() {
    return health_level;
}

std::string Fighter::get_title() {
    return title;
}

Fighter::Fighter(std::string title, int health_level, int attack_power) {
    this->title = title;
    this->health_level = health_level;
    this->attack_power = attack_power;
}

void Fighter::attack(Fighter *enemy) {
    enemy->get_damage(attack_power);
}

void Fighter::get_damage(int attack_power) {
    health_level -= attack_power;
}

Fighter::~Fighter() {

}
