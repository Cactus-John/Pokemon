#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

class Pokemon {
protected:
	string name, Type1, Type2, moveTypeFA, moveTypeCA;
	double level, base_attack, base_defense, base_stamina, iv_attack, iv_defense, iv_stamina, maxHP;

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

	double getLevel() {
		return (double)level;
	}

	void powerUp() {
		CPM = arrayCPM[(int)(this->level * 2) - 2];
		if (level == 1 && level < 40)
			level = level + 0.5;
		else
			level = level + 1;

	}

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

	string getName() {
		return name;
	}

	string getType1() {
		return Type1;
	}

	string getType2() {
		return Type2;
	}

};

class Charizard : public Pokemon {
public:
	Charizard(string name, double iv_attack, double iv_defense,
		double iv_stamina, double level)
	{
		this->name = name;
		this->iv_attack = iv_attack;
		this->iv_defense = iv_defense;
		this->iv_stamina = iv_stamina;
		this->level = level;
		base_attack = 223;
		base_defense = 173;
		base_stamina = 186;
		Type1 = "Fire";
		Type2 = "Flying";
	}
};

class Mewtwo : public Pokemon {
public:
	Mewtwo(string name, double iv_attack, double iv_defense,
		double iv_stamina, double level)
	{
		this->name = name;
		this->iv_attack = iv_attack;
		this->iv_defense = iv_defense;
		this->iv_stamina = iv_stamina;
		this->level = level;
		base_attack = 300;
		base_defense = 182;
		base_stamina = 214;
		Type1 = "Psychic";
	}
};

class Rayquaza : public Pokemon {
public:
	Rayquaza(string name, double iv_attack, double iv_defense,
		double iv_stamina, double level)
	{
		this->name = name;
		this->iv_attack = iv_attack;
		this->iv_defense = iv_defense;
		this->iv_stamina = iv_stamina;
		this->level = level;
		base_attack = 284;
		base_defense = 170;
		base_stamina = 213;
		Type1 = "Dragon";
		Type2 = "Flying";
	}
};

class Move {
protected:
	string moveTypeFA, moveTypeCA;
	int damageFA_Rayquaza, damageFA_Mewtwo, energy, damageCA_Rayquaza, damageCA_Mewtwo, turns, energyFA_Mewtwo, energyCA_Mewtwo, energyFA_Rayquaza, energyCA_Rayquaza, energy_gain, energy_cost;
public:
	Move() {
		moveTypeFA = "0";
		moveTypeCA = "0";
		damageFA_Rayquaza = 0;
		damageFA_Mewtwo = 0;
		damageCA_Rayquaza = 0;
		damageCA_Mewtwo = 0;
		turns = 0;
		energyFA_Rayquaza = 0;
		energyFA_Mewtwo = 0;
		energyCA_Rayquaza = 0;
		energyCA_Mewtwo = 0;
		energy_gain = 0;
		energy_cost = 0;
	}

	Move(string moveTypeFA, string moveTypeCA, int damageFA_Rayquaza, int damageFA_Mewtwo, int damageCA_Rayquaza, int damageCA_Mewtwo, int energyFA_Mewtwo, int energyFA_Rayquaza,
		int energyCA_Rayquaza, int energyCA_Mewtwo)
	{
		this->moveTypeFA = moveTypeFA;
		this->moveTypeCA = moveTypeCA;
		this->damageFA_Rayquaza = damageFA_Rayquaza;
		this->damageFA_Mewtwo = damageFA_Mewtwo;
		this->damageCA_Rayquaza = damageCA_Rayquaza;
		this->damageCA_Mewtwo = damageCA_Mewtwo;
		this->energyFA_Mewtwo = energyFA_Mewtwo;
		this->energyFA_Rayquaza = energyFA_Rayquaza;
		this->energyCA_Mewtwo = energyCA_Mewtwo;
		this->energyCA_Rayquaza = energyCA_Rayquaza;
	}
};

class FastMove : public Move {
public:
	double stabFA_Mewtwo, stabFA_Rayquaza, damage, effFA_Mewtwo, effFA_Rayquaza;
	int randomMewtwo, randomRayquaza, randomEnergyFA_Rayquaza;
	string randomFA_Mewtwo, randomFA_Rayquaza;
	FastMove() {
		static string MewtwoMoveTypeFA[2] = { "Psycho Cut", "Confusion" };
		static string RayquazaMoveTypeFA[2] = { "Dragon Tail", "Air Slash" };
		static int energyFA_Rayquaza[2] = { 9, 9 };
		static int energyFA_Mewtwo[2] = { 9, 12 };
		randomRayquaza = rand() % 2;
		randomFA_Rayquaza = RayquazaMoveTypeFA[randomRayquaza];
		randomMewtwo = rand() % 2;
		randomFA_Mewtwo = MewtwoMoveTypeFA[randomMewtwo];

		if (randomFA_Rayquaza == "Dragon Tail") {
			stabFA_Rayquaza = 1.2;
			effFA_Rayquaza = 1;
			energy_gain = 9;
			damageFA_Rayquaza = 15;
		}

		else if (randomFA_Rayquaza == "Air Slash") {
			stabFA_Rayquaza = 1.2;
			effFA_Rayquaza = 1;
			energy_gain = 10;
			damageFA_Rayquaza = 14;
		}

		if (randomFA_Mewtwo == "Psycho Cut") {
			stabFA_Mewtwo = 1.2;
			effFA_Mewtwo = 0.825;
			energy_gain = 8;
			damageFA_Mewtwo = 5;
		}
		else if (randomFA_Mewtwo == "Confusion") {
			stabFA_Mewtwo = 1.2;
			effFA_Mewtwo = 0.825;
			energy_gain = 15;
			damageFA_Mewtwo = 20;
		}
	}

	string getMoveTypeFA_Rayquaza() {
		return randomFA_Rayquaza;
	}

	string getMoveTypeFA_Mewtwo() {
		return randomFA_Mewtwo;
	}

	int getDamageFA_Rayquaza() {
		return damageFA_Rayquaza;
	}

	int getDamageFA_Mewtwo() {
		return damageFA_Mewtwo;
	}

	double getSTAB_FA_Mewtwo() {
		return stabFA_Mewtwo;
	}

	double getSTAB_FA_Rayquaza() {
		return stabFA_Rayquaza;
	}

	double getEFF_FA_Mewtwo() {
		return effFA_Mewtwo;
	}

	double getEFF_FA_Rayquaza() {
		return effFA_Rayquaza;
	}
};

class ChargedMove : public Move {
public:
	double stabCA_Mewtwo, stabCA_Rayquaza, damage, effCA_Mewtwo, effCA_Rayquaza;
	int randomRayquaza, randomMewtwo;
	string randomCA_Rayquaza, randomCA_Mewtwo;
	ChargedMove() {
		static string MewtwoMoveTypeCA[10] = { "Flamethrower", "Ice Beam", "Thunderbolt", "Psychic", "Focus Blast", "Shadow Ball", "Hyper Beam", "Psystrike", "Frustration", "Return" };
		static string RayquazaMoveTypeCA[4] = { "Aerial Ace", "Ancient Power", "Outrage", "Hurricane" };
		randomRayquaza = rand() % 4;
		randomCA_Rayquaza = RayquazaMoveTypeCA[randomRayquaza];
		randomMewtwo = rand() % 10;
		randomCA_Mewtwo = MewtwoMoveTypeCA[randomMewtwo];

		if (randomCA_Rayquaza == "Aerial Ace") {
			stabCA_Rayquaza = 1.2;
			effCA_Rayquaza = 1;
			energy_cost = 33;
			damageCA_Rayquaza = 55;
		}

		else if (randomCA_Rayquaza == "Outrage") {
			stabCA_Rayquaza = 1.2;
			effCA_Rayquaza = 1;
			energy_cost = 50;
			damageCA_Rayquaza = 110;
		}

		else if (randomCA_Rayquaza == "Hurricane") {
			stabCA_Rayquaza = 1.2;
			effCA_Rayquaza = 1;
			energy_cost = 100;
			damageCA_Rayquaza = 110;
		}

		else if (randomCA_Rayquaza == "Ancient Power") {
			stabCA_Rayquaza = 1;
			effCA_Rayquaza = 1;
			energy_cost = 33;
			damageCA_Rayquaza = 70;
		}

		if (randomCA_Mewtwo == "Psychic") {
			stabCA_Mewtwo = 1.2;
			effCA_Mewtwo = 1;
			energy_cost = 50;
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Psystrike") {
			stabCA_Mewtwo = 1.2;
			effCA_Mewtwo = 1;
			energy_cost = 50;
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Flamethrower") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 0.625;
			energy_cost = 50;
			damageCA_Mewtwo = 70;
		}

		else if (randomCA_Mewtwo == "Ice Beam") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 2.56;
			energy_cost = 50;
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Thunderbolt") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 1;
			energy_cost = 50;
			damageCA_Mewtwo = 80;
		}

		else if (randomCA_Mewtwo == "Focus Blast") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 0.625;
			energy_cost = 100;
			damageCA_Mewtwo = 140;
		}

		else if (randomCA_Mewtwo == "Shadow Ball") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 1;
			energy_cost = 50;
			damageCA_Mewtwo = 100;
		}

		else if (randomCA_Mewtwo == "Hyper Beam") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 1;
			energy_cost = 100;
			damageCA_Mewtwo = 150;
		}

		else if (randomCA_Mewtwo == "Frustration") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 1;
			energy_cost = 33;
			damageCA_Mewtwo = 10;
		}

		else if (randomCA_Mewtwo == "Return") {
			stabCA_Mewtwo = 1;
			effCA_Mewtwo = 1;
			energy_cost = 33;
			damageCA_Mewtwo = 35;
		}
	}

	string getRayquazaMoveTypeCA() {
		return randomCA_Rayquaza;
	}

	string getMewtwoMoveTypeCA() {
		return randomCA_Mewtwo;
	}

	int getDamageCA_Rayquaza() {
		return damageCA_Rayquaza;
	}

	int getDamageCA_Mewtwo() {
		return damageCA_Mewtwo;
	}

	double getSTAB_CA_Mewtwo() {
		return stabCA_Mewtwo;
	}
	double getSTAB_CA_Rayquaza() {
		return stabCA_Rayquaza;
	}

	double getEFF_CA_Mewtwo() {
		return effCA_Mewtwo;
	}
	double getEFF_CA_Rayquaza() {
		return effCA_Rayquaza;
	}
};

int main() {
	srand(time(nullptr));

	cout << "---------------------------" << endl;
	Mewtwo boski1("Mewtwo", 5, 5, 5, 13.5);
	Rayquaza boski2("Rayquaza", 5, 5, 5, 13.5);
	Move boskiMove;
	FastMove boskiFast;
	ChargedMove boskiCharged;

	//Charizard boski("Charizard", 5, 5, 5, 13.5);
	/*boski.powerUp();
	cout << "Ime pokemona: " << boski.getName();
	cout << endl;
	cout << "Type1 pokemona: " << boski.getType1();
	cout << endl;
	cout << "Type2 pokemona: " << boski.getType2();
	cout << endl;
	cout << "Attack: " << boski.getAttack();
	cout << endl;
	cout << "Defense: " << boski.getDefense();
	cout << endl;
	cout << "Stamina: " << boski.getStamina();
	cout << endl;
	cout << "Max HP: " << boski.getMaxHP();
	cout << endl;
	cout << "Combat Power: " << boski.getCP();
	cout << endl;
	cout << "-----------------------" << endl; */

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

	HP1_FA = boski1.getMaxHP() - floor(0.65 * boskiFast.getDamageFA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiFast.getSTAB_FA_Rayquaza() * boskiFast.getEFF_FA_Rayquaza()) + 1; //Rayquaza's attack on Mewtwo with fast attack
	HP2_FA = boski2.getMaxHP() - floor(0.65 * boskiFast.getDamageFA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiFast.getSTAB_FA_Mewtwo() * boskiFast.getEFF_FA_Mewtwo()) + 1; //Mewtwo's attack on Rayquaza with fast attack
	HP1_CA = boski1.getMaxHP() - floor(0.65 * boskiCharged.getDamageCA_Rayquaza() * boski2.getAttack() / boski1.getDefense() * boskiCharged.getSTAB_CA_Rayquaza() * boskiCharged.getEFF_CA_Rayquaza()) + 1; // Rayquaza's attack on Mewtwo with charge attack
	HP2_CA = boski2.getMaxHP() - floor(0.65 * boskiCharged.getDamageCA_Mewtwo() * boski1.getAttack() / boski2.getDefense() * boskiCharged.getSTAB_CA_Mewtwo() * boskiCharged.getEFF_CA_Mewtwo()) + 1; // Mewtwo's attack on Rayquaza with charge attack

	cout << endl;
	cout << "HP left on Mewtwo (fast attack): " << HP1_FA << endl;
	cout << "HP left on Rayquaza (fast attack): " << HP2_FA << endl;
	cout << "HP left on Mewtwo (charge attack): " << HP1_CA << endl;
	cout << "HP left on Rayquaza (charge attack): " << HP2_CA << endl;

	return 0;
}