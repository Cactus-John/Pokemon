#ifndef RAYQUAZA_H
#define RAYQUAZA_H

#include <string>
using namespace std;

class Rayquaza : public Pokemon {
public:
    Rayquaza(string name, double iv_attack, double iv_defense,
             double iv_stamina, double level) {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
        base_attack = 284;
        base_defense = 170;
        base_stamina = 213;
        Type1 = "Dragon";
        Type2 = "Flying";
    }
};
#endif // RAYQUAZA_H
