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
	double arrayCPM[101] = {0.094, 0.1351374318, 0.16639787, 0.192650919,
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
	int damageFA_Rayquaza, damageFA_Mewtwo, damageCA_Rayquaza, damageCA_Mewtwo, turns, energy_gain, energy_cost;
public:
	Move() {
		moveTypeFA = "0";
		moveTypeCA = "0";
		damageFA_Rayquaza = 0;
		damageFA_Mewtwo = 0;
		damageCA_Rayquaza = 0;
		damageCA_Mewtwo = 0;
		turns = 0;
		energy_gain = 0;
		energy_cost = 0;
	}
	Move(string moveTypeFA, string moveTypeCA, int damageFA_Rayquaza, int damageFA_Mewtwo, int damageCA_Rayquaza, int damageCA_Mewtwo) {
		this->moveTypeFA = moveTypeFA;
		this->moveTypeCA = moveTypeCA;
		this->damageFA_Rayquaza = damageFA_Rayquaza;
		this->damageFA_Mewtwo = damageFA_Mewtwo;
		this->damageCA_Rayquaza = damageCA_Rayquaza;
		this->damageCA_Mewtwo = damageCA_Mewtwo;
	}

	int getTurns() {
		return turns;
	}
};

class FastMove : public Move {
public:
	double stab;
	int randomMewtwo, randomRayquaza;
	string randomFA_Mewtwo, randomFA_Rayquaza;
	FastMove() {
		static string MewtwoMoveTypeFA[2] = { "Psycho Cut", "Confusion" };
		static string RayquazaMoveTypeFA[2] = { "Dragon Tail", "Air Slash" };
		randomRayquaza = rand() % 2;
		randomFA_Rayquaza = RayquazaMoveTypeFA[randomRayquaza];
		randomMewtwo = rand() % 2;
		randomFA_Mewtwo = MewtwoMoveTypeFA[randomMewtwo];

		if (randomFA_Rayquaza == "Dragon Tail") {
			stab = 0.2;
			damageFA_Rayquaza = 15;
		}

		else if (randomFA_Rayquaza == "Air Slash") {
			stab = 0.2;
			damageFA_Rayquaza = 14;
		}

		if (randomFA_Mewtwo == "Psycho Cut") {
			stab = 0.2;
			damageFA_Mewtwo = 5;
		}
		else if (randomFA_Mewtwo == "Confusion") {
			stab = 0.2;
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
};

class ChargedMove : public Move {
public:
	double stab;
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
			stab = 0.2;
			damageCA_Rayquaza = 55;
		}

		else if (randomCA_Rayquaza == "Outrage") {
			stab = 0.2;
			damageCA_Rayquaza = 110;
		}

		else if (randomCA_Rayquaza == "Hurricane") {
			stab = 0.2;
			damageCA_Rayquaza = 110;
		}

		else if (randomCA_Rayquaza == "Ancient Power") {
			damageCA_Rayquaza = 70;
		}

		if (randomCA_Mewtwo == "Psychic") {
			stab = 0.2;
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Psystrike") {
			stab = 0.2;
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Flamethrower") {
			damageCA_Mewtwo = 70;
		}

		else if (randomCA_Mewtwo == "Ice Beam") {
			damageCA_Mewtwo = 90;
		}

		else if (randomCA_Mewtwo == "Thunderbolt") {
			damageCA_Mewtwo = 80;
		}

		else if (randomCA_Mewtwo == "Focus Blast") {  
			damageCA_Mewtwo = 140;
		}

		else if (randomCA_Mewtwo == "Shadow Ball") {
			damageCA_Mewtwo = 100;
		}

		else if (randomCA_Mewtwo == "Hyper Beam") {
			damageCA_Mewtwo = 150;
		}

		else if (randomCA_Mewtwo == "Frustration") {
			damageCA_Mewtwo = 10;
		}

		else if (randomCA_Mewtwo == "Return") {
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
};

int main() {
	srand(time(nullptr));

	Charizard boski("Charizard", 5, 5, 5, 14.5);

	boski.powerUp();
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
	cout << "-----------------------" << endl;

	Mewtwo boski2("Mewtwo", 5, 5, 5, 14.5);
	Move boskiMove;
	FastMove boskiFast; 
	ChargedMove boskiCharged;

	boski2.powerUp();
	cout << "Ime pokemona: " << boski2.getName();
	cout << endl;
	cout << "Type pokemona: " << boski2.getType1();
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
	cout << "Quick Move (Fast Attack): " << boskiFast.getMoveTypeFA_Mewtwo();
	cout << endl;
	cout << boskiFast.getMoveTypeFA_Mewtwo() << " damage: " << boskiFast.getDamageFA_Mewtwo();
	cout << endl;
	cout << "Main Move (Charge Attack): " << boskiCharged.getMewtwoMoveTypeCA();
	cout << endl;
	cout << boskiCharged.getMewtwoMoveTypeCA() << " damage: " << boskiCharged.getDamageCA_Mewtwo();
	cout << endl;
	cout << "------------------------------------" << endl;

	Rayquaza boski3("Rayquaza", 5, 5, 5, 14.5);

	boski3.powerUp();
	cout << "Ime pokemona: " << boski3.getName();
	cout << endl;
	cout << "Type1 pokemona: " << boski3.getType1();
	cout << endl;
	cout << "Type2 pokemona: " << boski3.getType2();
	cout << endl;
	cout << "Attack: " << boski3.getAttack();
	cout << endl;
	cout << "Defense: " << boski3.getDefense();
	cout << endl;
	cout << "Stamina: " << boski3.getStamina();
	cout << endl;
	cout << "Max HP: " << boski3.getMaxHP();
	cout << endl;
	cout << "Combat Power: " << boski3.getCP();
	cout << endl;
	cout << "Quick Move (Fast Attack): " << boskiFast.getMoveTypeFA_Rayquaza();
	cout << endl;
	cout << boskiFast.getMoveTypeFA_Rayquaza() << " damage: " << boskiFast.getDamageFA_Rayquaza();
	cout << endl;
	cout << "Main Move (Charge Attack): " << boskiCharged.getRayquazaMoveTypeCA();
	cout << endl;
	cout << boskiCharged.getRayquazaMoveTypeCA() << " damage: " << boskiCharged.getDamageCA_Rayquaza();
	cout << endl;

	return 0;
}