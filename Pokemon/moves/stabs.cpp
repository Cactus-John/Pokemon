//
// Created by Ivan on 07/12/2025.
//

#ifndef STAB_H
#define STAB_H

#include <string>
using namespace std;

inline void stabFA(const string& randomFA_Rayquaza, double& stabFA_Rayquaza, double& effFA_Rayquaza, int& damageFA_Rayquaza,
                   const string& randomFA_Mewtwo, double& stabFA_Mewtwo, double& effFA_Mewtwo, int& damageFA_Mewtwo) {

    if (randomFA_Rayquaza == "Dragon Tail") {
        stabFA_Rayquaza = 1.2;
        effFA_Rayquaza = 1;
        damageFA_Rayquaza = 15;
    }

    else if (randomFA_Rayquaza == "Air Slash") {
        stabFA_Rayquaza = 1.2;
        effFA_Rayquaza = 1;
        damageFA_Rayquaza = 14;
    }

    if (randomFA_Mewtwo == "Psycho Cut") {
        stabFA_Mewtwo = 1.2;
        effFA_Mewtwo = 0.825;
        damageFA_Mewtwo = 5;
    }
    else if (randomFA_Mewtwo == "Confusion") {
        stabFA_Mewtwo = 1.2;
        effFA_Mewtwo = 0.825;
        damageFA_Mewtwo = 20;
    }
}

inline void stabCA(const string& randomCA_Rayquaza, double& stabCA_Rayquaza, double& effCA_Rayquaza, int& damageCA_Rayquaza,
                   const string& randomCA_Mewtwo, double& stabCA_Mewtwo, double& effCA_Mewtwo, int& damageCA_Mewtwo) {

    if (randomCA_Rayquaza == "Aerial Ace") {
        stabCA_Rayquaza = 1.2;
        effCA_Rayquaza = 1;
        damageCA_Rayquaza = 55;
    }

    else if (randomCA_Rayquaza == "Outrage") {
        stabCA_Rayquaza = 1.2;
        effCA_Rayquaza = 1;
        damageCA_Rayquaza = 110;
    }

    else if (randomCA_Rayquaza == "Hurricane") {
        stabCA_Rayquaza = 1.2;
        effCA_Rayquaza = 1;
        damageCA_Rayquaza = 110;
    }

    else if (randomCA_Rayquaza == "Ancient Power") {
        stabCA_Rayquaza = 1;
        effCA_Rayquaza = 1;
        damageCA_Rayquaza = 70;
    }

    if (randomCA_Mewtwo == "Psychic") {
        stabCA_Mewtwo = 1.2;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 90;
    }

    else if (randomCA_Mewtwo == "Psystrike") {
        stabCA_Mewtwo = 1.2;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 90;
    }

    else if (randomCA_Mewtwo == "Flamethrower") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 0.625;
        damageCA_Mewtwo = 70;
    }

    else if (randomCA_Mewtwo == "Ice Beam") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 2.56;
        damageCA_Mewtwo = 90;
    }

    else if (randomCA_Mewtwo == "Thunderbolt") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 80;
    }

    else if (randomCA_Mewtwo == "Focus Blast") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 0.625;
        damageCA_Mewtwo = 140;
    }

    else if (randomCA_Mewtwo == "Shadow Ball") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 100;
    }

    else if (randomCA_Mewtwo == "Hyper Beam") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 150;
    }

    else if (randomCA_Mewtwo == "Frustration") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 10;
    }

    else if (randomCA_Mewtwo == "Return") {
        stabCA_Mewtwo = 1;
        effCA_Mewtwo = 1;
        damageCA_Mewtwo = 35;
    }
}

#endif // STAB_H
