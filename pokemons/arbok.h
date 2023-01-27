
#include "pokemon.h"

#ifndef POKEMON_MEWTWO_H
#define POKEMON_MEWTWO_H

#endif //POKEMON_MEWTWO_H

class Arbok : public Pokemon {
public:
    Arbok(string name, double iv_attack, double iv_defense,
            double iv_stamina, double level)
    {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
        base_attack = 167;
        base_defense = 153;
        base_stamina = 155;
        Type1 = "Poison";
    }
};
