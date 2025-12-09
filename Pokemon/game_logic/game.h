//
// Created by Ivan on 07/12/2025.
//
#ifndef GAME_H
#define GAME_H

#include "../pokemons/pokemon.h"

inline bool lastPokemonStanding(Pokemon& p) {
    if (p.getCurrentHP() < 0)
        return true;
    return false;
}

inline void gameLogic(Pokemon& p1, Pokemon& p2, const double& HP1_FA, const double& HP2_FA, const double& HP1_CA, const double& HP2_CA) {
    int rounds;
    cout << "How many rounds you wanna play: ";
    cin >> rounds;
    bool isPokemon1Turn;

    if (p1.getCP() > p2.getCP()) {
        cout << p2.getName() << " has the first turn" << endl;
        isPokemon1Turn = false;
    }
    else {
        cout << p1.getName() << " has the first turn" << endl;
        isPokemon1Turn = true;
    }

    for (int i = 0; i < rounds; i++) {
        cout << "Round " << i + 1 << " of round " << rounds << endl;
        if (isPokemon1Turn) {
            cout << p1.getName() << "'s turn" << endl;
            p1.takeDamageFA1(HP2_FA);
            cout << "Remaining HP: " << p2.getCurrentHP() << endl;
            isPokemon1Turn = false;
        }
        cout << p2.getName() << "'s turn" << endl;
        p2.takeDamageFA2(HP1_FA);
        cout << "Remaining HP: " << p1.getCurrentHP() << endl;
        isPokemon1Turn = true;
    }

    if (p1.getCurrentHP() < 0 && p2.getCurrentHP() > 0) {
        cout << p1.getName() << " has won!" << endl;
    }
    else
        cout << p2.getName() << " has won!" << endl;
}

#endif // GAME_H
