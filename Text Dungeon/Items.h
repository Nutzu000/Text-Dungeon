#pragma once
#include <unordered_map>
unordered_map<string, int> inventory = {
	{"Goblin Dagger", 0},
	{"Ogre Belt",0},
	{"Lizardman Scales",0},
	{"Werewolf Fangs",0},
	{"Demon Blood",0},
	{"Skeleton Bones",0},
	{"Knight Equipment",0},
	{"Red Skull", 0},
	{"Holy Crystal Bow", 0},
	{"Jeanne", 0},
	{"EMP Grenade", 0},
	{"Ogre Slayer's Helmet", 0},
	{"Cool Shoes", 0},
	{"Bull's Eye", 0}
};
void getGoblinDagger(){
	inventory["Goblin Dagger"] = 1;
	playerAttackDamage += 5;
	typeText("You got a little dagger. How cute!\n");
	Sleep(1500);
}
void getOgreBelt() {
	inventory["Ogre Belt"] = 1;
	playerHp += 20;
	typeText("You take the Ogre's belt. You feel sturdier.\n");
	Sleep(1500);
}
void getLizardmanScales() {
	inventory["Lizardman Scales"] = 1;
	playerArmour += 10;
	typeText("You attach Lizardman's scales on your armor.\n");
	Sleep(1500);
}
void getWerewolfFangs() {
	inventory["Werewolf Fangs"] = 1;
	playerLifeSteal += 5;
	typeText("You take the Werewolf's fangs. Your bloodlust rises.\n");
	Sleep(1500);
}
void getDemonBlood() {
	inventory["Demon Blood"] = 1;
	playerAttackDamage += 20;
	typeText("You collect the Demon's blood. You feel stronger.\n");
	Sleep(1500);
}
void getSkeletonBones() {
	inventory["Skeleton Bones"] = 1;
	playerArmour += 5;
	typeText("You take some of the Skeleton's bones and attach them to your armor.\n");
	Sleep(1500);
}
void getKnightEquipment() {
	inventory["Knight Equipment"] = 1;
	playerArmour += 15;
	playerAttackDamage += 15;
	typeText("Leaving the Knight's equipment there would be such a waste. You take it for yourself.\n");
	Sleep(1500);
}
void getRedSkull() {
	inventory["Red Skull"] = 1;
	playerAttackDamage += 10;
	SetConsoleTextAttribute(h, 4);//rosu
	typeText("You acquired the Red Skull!\n");
	SetConsoleTextAttribute(h, 7);//normal
	Sleep(1500);
}
void getHolyCrystalBow() {
	inventory["Holy Crystal Bow"] = 1;
	SetConsoleTextAttribute(h, 14);//galben deschis
	typeText("You got the Holy Crystal Bow!\n");
	SetConsoleTextAttribute(h, 7);//normal
	Sleep(750);
	if (playerRace != "Angel") {
		typeText("However, it is outside your area of expertise...\n");
		Sleep(750);
		typeText("You can't use it.\n");
	}
	//maybe holy++
	Sleep(1500);
}
void getJeanne() {
	inventory["Jeanne"] = 1;
	typeText("You acquired 1 friend: ");
	SetConsoleTextAttribute(h, 14);//galben deschis
	typeText("Jeanne, the holy archer.\n");
	SetConsoleTextAttribute(h, 7);//normal
	partnerAttackDamage = 30;
	Sleep(1500);
}
void getEMPGrenade() {
	inventory["EMP Grenade"] = 1;
	SetConsoleTextAttribute(h, 11);//albastru deschis
	typeText("You obtained the EMP Grenade!\n");
	SetConsoleTextAttribute(h, 7);//normal
	Sleep(1500);
}
void getCommonItem() {
	if (playerItemsCounter < numberOfCommonItems) {
		playerItemsCounter++;
		int randomItemIndex = rand() % numberOfCommonItems;
		while( inventory[commonItems[randomItemIndex]] == 1){
			randomItemIndex = rand() % numberOfCommonItems;
		}
		inventory[commonItems[randomItemIndex]] = 1;
		SetConsoleTextAttribute(h, 8);//gri
		cout << "You got " << commonItems[randomItemIndex] << "!\n";
		SetConsoleTextAttribute(h, 7);//normal
	}
	else{
		cout << "You've got all the items!\n";
	}
}