//
// Created by Ivan on 07/12/2025.
//
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../pokemons/pokemon.h"

inline bool lastPokemonStanding(Pokemon& p) {
    if (p.getCurrentHP() < 0)
        return true;
    return false;
}

inline void gameLogic(vector<Pokemon>& vPokemon1, vector<Pokemon>& vPokemon2) {
    for (int i = 0; i < vPokemon1.size(); i++) {
        Pokemon p1 = vPokemon1[i];
        for (int j = 0; j < vPokemon2.size(); j++) {
            Pokemon p2 = vPokemon2[j];
            if (p1.getCurrentHP() > p2.getCurrentHP())
                vPokemon1.push_back(p1);
            else
                vPokemon2.push_back(p2);

        }
    }
}

#endif // GAME_H
