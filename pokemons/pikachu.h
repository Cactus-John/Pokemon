
#include "pokemon.h"

#ifndef POKEMON_MEWTWO_H
#define POKEMON_MEWTWO_H

#endif //POKEMON_MEWTWO_H

class Pikachu : public Pokemon {
public:
    Pikachu(string name, double iv_attack, double iv_defense,
           double iv_stamina, double level)
    {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
        base_attack = 112;
        base_defense = 96;
        base_stamina = 111;
        Type1 = "Electric";
    }
};
