
#ifndef POKEMON_CHARGEMOVE_H
#define POKEMON_CHARGEMOVE_H

#endif //POKEMON_CHARGEMOVE_H

void stabCA(string& randomCA_Rayquaza, double& stabCA_Rayquaza, double& effCA_Rayquaza, int& damageCA_Rayquaza,
            string& randomCA_Mewtwo, double& stabCA_Mewtwo, double& effCA_Mewtwo, int& damageCA_Mewtwo);

class ChargedMove : public Move {
public:
    double stabCA_Mewtwo, stabCA_Rayquaza, effCA_Mewtwo, effCA_Rayquaza;
    int randomRayquaza, randomMewtwo;
    string randomCA_Rayquaza, randomCA_Mewtwo;
    ChargedMove() {
        static string MewtwoMoveTypeCA[10] = { "Flamethrower", "Ice Beam", "Thunderbolt", "Psychic", "Focus Blast", "Shadow Ball", "Hyper Beam", "Psystrike", "Frustration", "Return" };
        static string RayquazaMoveTypeCA[4] = { "Aerial Ace", "Ancient Power", "Outrage", "Hurricane" };
        randomRayquaza = rand() % 4;
        randomCA_Rayquaza = RayquazaMoveTypeCA[randomRayquaza];
        randomMewtwo = rand() % 10;
        randomCA_Mewtwo = MewtwoMoveTypeCA[randomMewtwo];

        stabCA(randomCA_Rayquaza, stabCA_Rayquaza, effCA_Rayquaza, damageCA_Rayquaza, randomCA_Mewtwo, stabCA_Mewtwo, effCA_Mewtwo, damageCA_Mewtwo);
    }

    [[nodiscard]] string getRayquazaMoveTypeCA() const { return randomCA_Rayquaza; }

    [[nodiscard]] string getMewtwoMoveTypeCA() const { return randomCA_Mewtwo; }

    [[nodiscard]] int getDamageCA_Rayquaza() const { return damageCA_Rayquaza; }

    [[nodiscard]] int getDamageCA_Mewtwo() const { return damageCA_Mewtwo; }

    [[nodiscard]] double getSTAB_CA_Mewtwo() const { return stabCA_Mewtwo; }

    [[nodiscard]] double getSTAB_CA_Rayquaza() const { return stabCA_Rayquaza; }

    [[nodiscard]] double getEFF_CA_Mewtwo() const { return effCA_Mewtwo; }

    [[nodiscard]] double getEFF_CA_Rayquaza() const { return effCA_Rayquaza; }
};
