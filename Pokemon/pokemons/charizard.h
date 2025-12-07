#ifndef CHARIZARD_H
#define CHARIZARD_H

#include <string>
#include "pokemon.h"

using namespace std;

class Charizard : public Pokemon {
public:
    Charizard(string name, double iv_attack, double iv_defense,
              double iv_stamina, double level) {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
        base_attack = 223;
        base_defense = 173;
        base_stamina = 186;
        Type1 = "Fire";
        Type2 = "Flying";
    }
};
#endif // CHARIZARD_H
