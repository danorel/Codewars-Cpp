#include "War.h"

std::string declareWinner(Fighter *, Fighter *, std::string);

int main() {
    Fighter *fighter1 = new Fighter("Jerry", 30, 3);
    Fighter *fighter2 = new Fighter("Harald", 20, 5);
    std::cout << "Winner is " << declareWinner(fighter1, fighter2, "Jerry") << std::endl;
    return 0;
}

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
    while(fighter1->get_health_level() >= 0 && fighter2->get_health_level() >= 0){
        firstAttacker == fighter1->get_title() ? fighter1->attack(fighter2) : fighter2->attack(fighter1);
        if(fighter1->get_health_level() <= 0){
            return fighter2->get_title();
        }
        firstAttacker == fighter1->get_title() ? fighter2->attack(fighter1) : fighter1->attack(fighter2);
        if(fighter2->get_health_level() <= 0){
            return fighter1->get_title();
        }
    }
}