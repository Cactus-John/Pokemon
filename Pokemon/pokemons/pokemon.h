#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <cmath>
using namespace std;

class Pokemon {
protected:
    string name, Type1, Type2, moveTypeFA, moveTypeCA;
    double level, base_attack, base_defense, base_stamina, iv_attack, iv_defense, iv_stamina, maxHP, currentHP;
public:
    double attack, defense, stamina, CP, CPM;
    double arrayCPM[101] = { 0.094, 0.1351374318, 0.16639787, 0.192650919,
                             0.21573247, 0.2365726613, 0.25572005, 0.2735303812,
                             0.29024988, 0.3060573775, 0.3210876, 0.3354450362,
                             0.34921268, 0.3624577511, 0.3752356, 0.387592416,
                             0.39956728, 0.4111935514, 0.4225, 0.4329264091,
                             0.44310755, 0.4530599591, 0.4627984, 0.472336093,
                             0.48168495, 0.4908558003, 0.49985844, 0.508701765,
                             0.51739395, 0.5259425113, 0.5343543,	0.5426357375,
                             0.5507927, 0.5588305862, 0.5667545, 0.5745691333,
                             0.5822789, 0.5898879072, 0.5974, 0.6048236651, 0.6121573,
                             0.6194041216, 0.6265671, 0.6336491432, 0.64065295,
                             0.6475809666, 0.65443563, 0.6612192524, 0.667934,
                             0.6745818959, 0.6811649, 0.6876849038, 0.69414365,
                             0.70054287, 0.7068842, 0.7131691091, 0.7193991,
                             0.7255756136, 0.7317, 0.7347410093, 0.7377695,
                             0.7407855938, 0.74378943, 0.7467812109, 0.74976104,
                             0.7527290867, 0.7556855, 0.7586303683, 0.76156384,
                             0.7644860647, 0.76739717, 0.7702972656, 0.7731865,
                             0.7760649616, 0.77893275, 0.7817900548, 0.784637,
                             0.7874736075, 0.7903, 0.792803968, 0.79530001,
                             0.797800015, 0.8003, 0.802799995, 0.8053, 0.8078,
                             0.81029999, 0.812799985, 0.81529999, 0.81779999,
                             0.82029999, 0.82279999, 0.82529999, 0.82779999,
                             0.83029999, 0.83279999, 0.83529999, 0.83779999,
                             0.84029999, 0.84279999, 0.84529999 };
    Pokemon() {
        name = "0";
        iv_attack = 0;
        iv_defense = 0;
        iv_stamina = 0;
        level = 0;
    }

    Pokemon(string name, double iv_attack, double iv_defense, double iv_stamina, double level) {
        this->name = name;
        this->iv_attack = iv_attack;
        this->iv_defense = iv_defense;
        this->iv_stamina = iv_stamina;
        this->level = level;
    }

    void setName(string name) {
        this->name = name;
    }

    void powerUp() {
        CPM = arrayCPM[(int)(this->level * 2) - 2];
        if (level == 1 && level < 40)
            level = level + 0.5;
        else
            level = level + 1;
    }

    double getLevel() const { return (double)level; }

    double getAttack() {
        attack = (base_attack + iv_attack) * CPM;
        return attack;
    }

    double getDefense() {
        defense = (base_defense + iv_defense) * CPM;
        return defense;
    }

    double getStamina() {
        stamina = (base_stamina + iv_stamina) * CPM;
        return stamina;
    }

    double getCP() {
        CP = max(floor(attack * sqrt(defense * stamina) / 10), 10.);
        return CP;
    }

    double getMaxHP() {
        maxHP = floor(stamina);
        return maxHP;
    }

    double getCurrentHP()  {
        currentHP = maxHP - currentHP;
        return currentHP;
    }

    string getName() const {
        return name;
    }

    string getType1() const {
        return Type1;
    }

    string getType2() const {
        return Type2;
    }
};
#endif // POKEMON_H
