
#include "pokemon.h"

#ifndef POKEMON_MEWTWO_H
#define POKEMON_MEWTWO_H

#endif //POKEMON_MEWTWO_H

class Nidoking : public Pokemon {
public:
    Nidoking(string name, double iv_attack, double iv_defense,
          double iv_stamina, double level)
    {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
        base_attack = 204;
        base_defense = 156;
        base_stamina = 191;
        Type1 = "Poison";
        Type2 = "Ground";
    }
};
