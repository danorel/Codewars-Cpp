//
// Created by Dan Orel on 1/3/19.
//
#include <iostream>
#ifndef WAR_WAR_H
#define WAR_WAR_H
class Fighter{
public:
    Fighter(std::string, int, int);
    std::string get_title();
    int get_health_level();
    int get_attack_power();
    void attack(Fighter *);
    void get_damage(int attack_power);
    ~Fighter();
private:
    std::string title;
    int health_level;
    int attack_power;
};
#endif //WAR_WAR_H
