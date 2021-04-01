#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
//statsurile caracterului
string playerName, playerRace;
int playerMaxHp = 0, playerHp = 0, playerArmour = 0, playerAttackDamage = 0, playerDamage = 0, playerLifeSteal = 0;
int canRun = 1, playerItemsCounter=0, startOfCombat=-1, arrowsVolleyCounter=0;
//statsurile partenerului
int partnerAttackDamage = 0, partnerDamage = 0;
int score=0;
//iteme comune
string commonItems[] = { "Ogre Slayer's Helmet", "Cool Shoes", "Bull's Eye"};
int numberOfCommonItems = sizeof(commonItems) / sizeof(commonItems[0]);
//statsurile monstrilor
string enemys[] = { "goblin", "ogre", "lizardman", "werewolf", "demon", "skeleton", "Jeanne", "knight", "bandit", "King's Guard", "The King"}; 
string enemyName;
int enemyMaxHp = 0, enemyHp = 0, enemyArmour = 0, enemyAttackDamage = 0, enemyDamage = 0, enemyLifeSteal = 0, enemyPointsReward = 0, enemyAttackSpeed = 1, enemyAttacksCounter=0;
//viteza jocului, mai putin e mai rapid
int textSpeed = 100;
//declararile
#include "Functions.h"

int main()
{
    //to make it truly random
    srand((int)time(0));
    startMenu();
    return 0;
}