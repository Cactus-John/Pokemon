
#include <string>

#ifndef POKEMON_MOVES_H
#define POKEMON_MOVES_H

#endif //POKEMON_MOVES_H
using namespace std;

class Move {
protected:
    string moveTypeFA, moveTypeCA;
    int damageFA_Rayquaza, damageFA_Mewtwo, damageCA_Rayquaza, damageCA_Mewtwo;
public:
    Move() {
        moveTypeFA = "0";
        moveTypeCA = "0";
        damageFA_Rayquaza = 0;
        damageFA_Mewtwo = 0;
        damageCA_Rayquaza = 0;
        damageCA_Mewtwo = 0;
    }

    Move(int damageFA_Rayquaza, int damageFA_Mewtwo, int damageCA_Rayquaza, int damageCA_Mewtwo)
    {
        this->damageFA_Rayquaza = damageFA_Rayquaza;
        this->damageFA_Mewtwo = damageFA_Mewtwo;
        this->damageCA_Rayquaza = damageCA_Rayquaza;
        this->damageCA_Mewtwo = damageCA_Mewtwo;
    }
};