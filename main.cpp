
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "mewtwo.h"
#include "rayquaza.h"
#include "fastmove.h"
#include "chargemove.h"
using namespace std;

int main() {
    srand(time(nullptr));

    cout << "---------------------------" << endl;
    Mewtwo boski1("Mewtwo", 5, 5, 5, 13.5);
    Rayquaza boski2("Rayquaza", 5, 5, 5, 13.5);
    Move boskiMove;
    FastMove boskiFast;
    ChargedMove boskiCharged;

    // Mewtwo stats
    boski1.powerUp();
    cout << "Ime pokemona: " << boski1.getName();
    cout << endl;
    cout << "Type pokemona: " << boski1.getType1();
    cout << endl;
    cout << "Attack: " << boski1.getAttack();
    cout << endl;
    cout << "Defense: " << boski1.getDefense();
    cout << endl;
    cout << "Stamina: " << boski1.getStamina();
    cout << endl;
    cout << "Max HP: " << boski1.getMaxHP();
    cout << endl;
    cout << "Combat Power: " << boski1.getCP();
    cout << endl;
    cout << "Quick Move (Fast Attack): " << boskiFast.getMoveTypeFA_Mewtwo();
    cout << endl;
    cout << boskiFast.getMoveTypeFA_Mewtwo() << " base damage: " << boskiFast.getDamageFA_Mewtwo();
    cout << endl;
    cout << "Main Move (Charge Attack): " << boskiCharged.getMewtwoMoveTypeCA();
    cout << endl;
    cout << boskiCharged.getMewtwoMoveTypeCA() << " base damage: " << boskiCharged.getDamageCA_Mewtwo();
    cout << endl;
    cout << "------------------------------------" << endl;

    // Rayquaza stats
    boski2.powerUp();
    cout << "Ime pokemona: " << boski2.getName();
    cout << endl;
    cout << "Type1 pokemona: " << boski2.getType1();
    cout << endl;
    cout << "Type2 pokemona: " << boski2.getType2();
    cout << endl;
    cout << "Attack: " << boski2.getAttack();
    cout << endl;
    cout << "Defense: " << boski2.getDefense();
    cout << endl;
    cout << "Stamina: " << boski2.getStamina();
    cout << endl;
    cout << "Max HP: " << boski2.getMaxHP();
    cout << endl;
    cout << "Combat Power: " << boski2.getCP();
    cout << endl;
    cout << "Quick Move (Fast Attack): " << boskiFast.getMoveTypeFA_Rayquaza();
    cout << endl;
    cout << boskiFast.getMoveTypeFA_Rayquaza() << " base damage: " << boskiFast.getDamageFA_Rayquaza();
    cout << endl;
    cout << "Main Move (Charge Attack): " << boskiCharged.getRayquazaMoveTypeCA();
    cout << endl;
    cout << boskiCharged.getRayquazaMoveTypeCA() << " base damage: " << boskiCharged.getDamageCA_Rayquaza();
    cout << endl << "------------------------------------" << endl;

    double HP1_FA, HP1_CA, HP2_FA, HP2_CA;
    cout << "Mewtwo's Fast Attack: " << boskiFast.getMoveTypeFA_Mewtwo() << endl;
    cout << boskiFast.getMoveTypeFA_Mewtwo() << " damage: " << floor(0.65 * boskiFast.getDamageFA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiFast.getSTAB_FA_Mewtwo() * boskiFast.getEFF_FA_Mewtwo()) << endl;
    cout << "Mewtwo's Charge Attack: " << boskiCharged.getMewtwoMoveTypeCA() << endl;
    cout << boskiCharged.getMewtwoMoveTypeCA() << " damage: " << floor(0.65 * boskiCharged.getDamageCA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiCharged.getSTAB_CA_Mewtwo() * boskiCharged.getEFF_CA_Mewtwo()) << endl;
    cout << "Rayquaza's Fast Attack: " << boskiFast.getMoveTypeFA_Rayquaza() << endl;
    cout << boskiFast.getMoveTypeFA_Rayquaza() << " damage: " << floor(0.65 * boskiFast.getDamageFA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiFast.getSTAB_FA_Rayquaza() * boskiFast.getEFF_FA_Rayquaza()) << endl;
    cout << "Rayquaza's Charge Attack: " << boskiCharged.getRayquazaMoveTypeCA() << endl;
    cout << boskiCharged.getRayquazaMoveTypeCA() << " damage: " << floor(0.65 * boskiCharged.getDamageCA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiCharged.getSTAB_CA_Rayquaza() * boskiCharged.getEFF_CA_Rayquaza()) << endl;


//Rayquaza's attack on Mewtwo with fast attack
    HP1_FA = boski1.getMaxHP() - floor(0.65 * boskiFast.getDamageFA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiFast.getSTAB_FA_Rayquaza() * boskiFast.getEFF_FA_Rayquaza()) + 1;
//Mewtwo's attack on Rayquaza with fast attack
    HP2_FA = boski2.getMaxHP() - floor(0.65 * boskiFast.getDamageFA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiFast.getSTAB_FA_Mewtwo() * boskiFast.getEFF_FA_Mewtwo()) + 1;
// Rayquaza's attack on Mewtwo with charge attack
    HP1_CA = boski1.getMaxHP() - floor(0.65 * boskiCharged.getDamageCA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiCharged.getSTAB_CA_Rayquaza() * boskiCharged.getEFF_CA_Rayquaza()) + 1;
// Mewtwo's attack on Rayquaza with charge attack
    HP2_CA = boski2.getMaxHP() - floor(0.65 * boskiCharged.getDamageCA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiCharged.getSTAB_CA_Mewtwo() * boskiCharged.getEFF_CA_Mewtwo()) + 1;

    cout << endl;
    cout << "HP left on Mewtwo if fast attack was used: " << HP1_FA << endl;
    cout << "HP left on Rayquaza if fast attack was used: " << HP2_FA << endl;
    cout << "HP left on Mewtwo if charged move was used: " << HP1_CA << endl;
    cout << "HP left on Rayquaza if charged move was used: " << HP2_CA << endl;

    return 0;
}