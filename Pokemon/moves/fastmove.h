#ifndef FASTMOVE_H
#define FASTMOVE_H

#include "moves.h"
#include <string>

void stabFA(const string& randomFA_Rayquaza, double& stabFA_Rayquaza, double& effFA_Rayquaza, int& damageFA_Rayquaza,
            const string& randomFA_Mewtwo, double& stabFA_Mewtwo, double& effFA_Mewtwo, int& damageFA_Mewtwo);

class FastMove : public Move {
public:
    double stabFA_Mewtwo, stabFA_Rayquaza, effFA_Mewtwo, effFA_Rayquaza;
    int randomMewtwo, randomRayquaza;
    string randomFA_Mewtwo, randomFA_Rayquaza;
    FastMove() {
        static string MewtwoMoveTypeFA[2] = { "Psycho Cut", "Confusion" };
        static string RayquazaMoveTypeFA[2] = { "Dragon Tail", "Air Slash" };
        randomRayquaza = rand() % 2;
        randomFA_Rayquaza = RayquazaMoveTypeFA[randomRayquaza];
        randomMewtwo = rand() % 2;
        randomFA_Mewtwo = MewtwoMoveTypeFA[randomMewtwo];

        stabFA(randomFA_Rayquaza, stabFA_Rayquaza, effFA_Rayquaza, damageFA_Rayquaza, randomFA_Mewtwo, stabFA_Mewtwo, effFA_Mewtwo, damageFA_Mewtwo);
    }

    [[nodiscard]] string getMoveTypeFA_Rayquaza() const { return randomFA_Rayquaza; }

    [[nodiscard]] string getMoveTypeFA_Mewtwo() const {return randomFA_Mewtwo; }

    [[nodiscard]] int getDamageFA_Rayquaza() const { return damageFA_Rayquaza; }

    [[nodiscard]] int getDamageFA_Mewtwo() const { return damageFA_Mewtwo; }

    [[nodiscard]] double getSTAB_FA_Mewtwo() const { return stabFA_Mewtwo; }

    [[nodiscard]] double getSTAB_FA_Rayquaza() const { return stabFA_Rayquaza; }

    [[nodiscard]] double getEFF_FA_Mewtwo() const { return effFA_Mewtwo; }

    [[nodiscard]] double getEFF_FA_Rayquaza() const { return effFA_Rayquaza; }
};
#endif // FASTMOVE_H
