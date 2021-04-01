#pragma once
#include <cmath>
//pentru colorat
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int numberLength(int a) {
    int ctr = 1;
    if (a < 0) {
        a *= -1;
        ctr++;
    }
    while (a > 9) {
        a /= 10;
        ctr++;
    }
    return ctr;
}
void typeText(string t) {
    for (int i = 0; i < t.length(); i++) {
        Sleep(textSpeed);
        cout << t[i];
    }
}
void choiceInput(int& choice) {
    int ok;
    do {
        ok = 0;
        cin >> choice;
        if (cin.fail()) {
            ok = 1;
            cin.clear();
            cin.ignore();
        }
        cin.ignore();
    } while (ok);
}
void combat(); 
void HUD();
void createPlayer();
void fightHUD();
void createEnemy(int monsterIndex);
void fight(int monsterIndex);
void slaughter();
void adventure();
void startMenu();
void gameOver();
void itemReward();
#include "rooms.h"
//definitions
void startMenu() {
    cout << "Welcome, to Text Dungeon!\n"
        << "Are you ready to explore the depths of this forsaken land?\n"
        << "1. Yes, I am!\n"
        << "2. I just want to kill some monsters.\n"
        << "3. I want to know who created this dungeon first.\n"
        << "4. I don't think I am ready yet...\n";
    int choice;
    choiceInput(choice);
    switch (choice) {
    case 1:
        system("cls");
        createPlayer();
        adventure();
        break;
    case 2:
        system("cls");
        createPlayer();
        system("cls");
        cout << "Let the slaughter begin!\n";
        Sleep(750);
        system("cls");
        slaughter();
        break;
    case 3:
        cout << "Text Dungeon!\n";
        Sleep(1000);
        cout << "Brought to you by: ";
        Sleep(1000);
        cout << "Antal-Cionta Ioan Sorin!\n";
        Sleep(1000);
        system("cls");
        startMenu();
        break;
    case 4:
        cout << "You better be ready next time...\n";
        Sleep(1000);
        exit(0);
        break;
    case 0:
        exit(0);
        break;
    default:
        cout << "Sorry, I don't get it.\n";
        Sleep(750);
        system("cls");
        startMenu();
        break;
    }
}
void createPlayer() {
    cout << "Select your name: ";
    getline(cin, playerName);
    while (playerName.length() > 20) {
        cout << "Your name is too long! Try again a shorter one:\n";
        getline(cin, playerName);
    }
    playerHp = 100;
    playerArmour = 0;
    playerAttackDamage = 20;
    playerLifeSteal = 0;
    cout << "Select one of the following races:\n"
        << "1. Human\n"
        << "2. Elf\n"
        << "3. Dwarf\n"
        << "4. Demon\n"
        << "5. Angel\n"
        << "6. Another race\n";
    int choice;
    choiceInput(choice);

    switch (choice)
    {
    case 1:
        playerRace = "Human";
        playerMaxHp = 100;
        playerAttackDamage += 10;
        playerArmour += 10;
        break;
    case 2:
        playerRace = "Elf";
        playerMaxHp = 90;
        playerAttackDamage += 15;
        playerHp -= 10;
        break;
    case 3:
        playerRace = "Dwarf";
        playerMaxHp = 130;
        playerHp += 30;
        playerArmour += 30;
        break;
    case 4:
        playerRace = "Demon";
        playerMaxHp = 100;
        playerHp -= 50;
        playerAttackDamage += 30;
        playerLifeSteal = 5;
        break;
    case 5:
        playerRace = "Angel";
        playerMaxHp = 100;
        playerAttackDamage += 15;
        break;
    default:
        playerMaxHp = 100;
        cout << "Select your race: "; cin >> playerRace;
        for (int i = 0; i < playerRace.length(); i++) {
            playerRace[i] = tolower(playerRace[i]);
        }
        playerRace[0] = toupper(playerRace[0]);
        break;
    }
    for (int i = 1; i <= 3; i++) {
        system("cls");
        cout << "Creating your character";
        if (i == 1) cout << ".\n";
        if (i == 2) cout << "..\n";
        if (i == 3) cout << "...\n";
        Sleep(750);
    }
    system("cls");
}
void HUD() {
    cout << "Name: " << playerName << "\n"
        << "Race: " << playerRace << "\n";
    cout << "Health: ";
    SetConsoleTextAttribute(h, 2);
    cout << playerHp << "\n";
    SetConsoleTextAttribute(h, 7);
    cout << "Attack: ";
    SetConsoleTextAttribute(h, 4);
    cout << playerAttackDamage << "\n";
    SetConsoleTextAttribute(h, 7);
    cout << "Armour: ";
    SetConsoleTextAttribute(h, 8);
    cout << playerArmour << "\n";
    SetConsoleTextAttribute(h, 7);
}
void fight(int monsterIndex) {
    createEnemy(monsterIndex);
    Sleep(1000);
    combat();
}
void createEnemy(int monsterIndex) {
    switch (monsterIndex) {
    case 0:
        enemyName = "Goblin";
        enemyMaxHp = 25;
        enemyHp = 25;
        enemyArmour = 0;
        enemyAttackDamage = 3;
        enemyPointsReward = 5;
        enemyLifeSteal = 0;
        break;
    case 1:
        enemyName = "Ogre";
        enemyMaxHp = 50;
        enemyHp = 50;
        enemyArmour = 10;
        enemyAttackDamage = 20;
        enemyPointsReward = 10;
        enemyLifeSteal = 0;
        break;
    case 2:
        enemyName = "Lizardman";
        enemyMaxHp = 30;
        enemyHp = 30;
        enemyArmour = 50;
        enemyAttackDamage = 50;
        enemyPointsReward = 30;
        enemyLifeSteal = 0;
        break;
    case 3:
        enemyName = "Werewolf";
        enemyMaxHp = 30;
        enemyHp = 30;
        enemyArmour = 10;
        enemyAttackDamage = 15;
        enemyPointsReward = 15;
        enemyLifeSteal = 5;
        break;
    case 4:
        enemyName = "Demon";
        enemyMaxHp = 40;
        enemyHp = 25;
        enemyArmour = 0;
        enemyAttackDamage = 30;
        enemyPointsReward = 15;
        enemyLifeSteal = 10;
        break;
    case 5:
        enemyName = "Skeleton";
        enemyMaxHp = 5;
        enemyHp = 5;
        enemyArmour = 0;
        enemyAttackDamage = 10;
        enemyPointsReward = 5;
        enemyLifeSteal = 0;
        break;
    case 6:
        enemyName = "Jeanne";
        enemyMaxHp = 100;
        enemyHp = 100;
        enemyArmour = 30;
        enemyAttackDamage = 30;
        enemyPointsReward = 100;
        playerLifeSteal = 15;
        break;
    case 7:
        enemyName = "Knight";
        enemyMaxHp = 75;
        enemyHp = 75;
        enemyArmour = 50;
        enemyAttackDamage = 50;
        enemyPointsReward = 75;
        playerLifeSteal = 0;
        enemyAttackSpeed = 2;
        break;
    case 8:
        enemyName = "Bandit";
        enemyMaxHp = 100;
        enemyHp = 100;
        enemyArmour = 10;
        enemyAttackDamage = 30;
        enemyPointsReward = 150;
        playerLifeSteal = 0;
        break;
    case 9:
        enemyName = "King's Guard";
        enemyMaxHp = 75;
        enemyHp = 75;
        enemyArmour = 30;
        enemyAttackDamage = 50;
        enemyPointsReward = 50;
        playerLifeSteal = 0;
        break;
    case 10:
        enemyName = "The King"; 
        enemyMaxHp = 2000;
        enemyHp = 2000;
        enemyAttackDamage = 20;
        break;
    default:
        cout << "\nThere is no such monster\n";
        break;
    }
}
void combat() {
    fightHUD();
    if (startOfCombat < 0){
        arrowsVolleyCounter = 0;
    }
    cout << "1. Strike\n"
        << "2. Uppercut\n"
        << "3. Block\n"
        << "4. Run\n";
    if (playerRace == "Angel" && inventory["Holy Crystal Bow"]) {
        cout << "5. Arrows Volley\n";
    }
    int choice, run = 0;
    choiceInput(choice);
    switch (choice) {
    case 1:
        /*you*/ {
            if (playerAttackDamage > enemyArmour) {
                 cout << "You strike the monster ";
                 playerDamage = playerAttackDamage - enemyArmour;
                 if (inventory["Ogre Slayer's Helmet"] && enemyName.substr(0, 4) == "Ogre") {
                     playerDamage *= 2;
                 }
                 enemyHp -= playerDamage;
                 cout << "for " << playerDamage << " damage!\n";
                 if (playerHp + playerLifeSteal >= playerMaxHp) {
                       playerHp = playerMaxHp;
                 }
                 else {
                       playerHp += playerLifeSteal;
                 }
            }
            else {
                cout << "Oh no! The " << enemyName << "'s armour is too though! Try an Uppercut!\n";
            }
        }
        break;
    case 2:
        cout << playerName << " prepares an uppercut.\n";
        Sleep(500);
        if (rand() % 2) {
            cout << "Nice! It landed! ";
            if (inventory["Bull's Eye"] == 1) {
                playerDamage = playerAttackDamage * 5 / 2;
            }
            else {
                playerDamage = playerAttackDamage * 3 / 2;
            }
            if (inventory["Ogre Slayer's Helmet"] && enemyName.substr(0, 4) == "Ogre") {
                playerDamage *= 2;
            }
            enemyHp -= playerDamage;
            cout << "It dealt " << playerDamage << " damage!\n";
            if (playerHp + playerLifeSteal >= playerMaxHp) {
                playerHp = playerMaxHp;
            }
            else {
                playerHp += playerLifeSteal;
            }
        }
        else {
            cout << "Unfortunately he dodged...\n";
        }
        Sleep(500);
        break;
    case 3:
        cout << playerName << " takes a defensive stance.\n";
        Sleep(500);
        if (rand() % 4 != 0) {
            cout << "You managed to block the attack!\n";
            Sleep(500);
            cout << "Your wounds are starting to heal.\n";
            if (playerHp < playerMaxHp) {
                playerHp += 10;
                if (playerHp > playerMaxHp) {
                    playerHp = playerMaxHp;
                }
            }
            Sleep(500);
        }
        else {
            cout << "The enemy's ferocious attack breaks through your defense.\n";
            if (enemyAttackDamage > playerArmour) {
                playerHp -= enemyAttackDamage/2-playerArmour;
            }
        }
        break;
    case 4:
        if (rand() % 4) {
            cout << "You run until the monster eventually stops following you...\n";
            if (canRun) {
                run = 1;
            }
            else {
                cout << "You can't run now!\n";
                combat();
            }
            
        }
        else {
            cout << "Looks like he caught up to you!\n";
        }
        break;
    case 5:
        if (playerRace == "Angel" && inventory["Holy Crystal Bow"]) {
            if (arrowsVolleyCounter<=3) {
                if (playerAttackDamage > enemyArmour) {
                    cout << "You send a volley of arrows ";
                    playerDamage = playerAttackDamage - enemyArmour;
                    if (inventory["Ogre Slayer's Helmet"] && enemyName.substr(0, 4) == "Ogre") {
                        playerDamage *= 2;
                    }
                    enemyHp -= playerDamage;
                    cout << "for " << playerDamage << " damage!\n";
                    if (playerHp + playerLifeSteal >= playerMaxHp) {
                        playerHp = playerMaxHp;
                    }
                    else {
                        playerHp += playerLifeSteal;
                    }
                }
                else{
                    cout << "Oh no! The " << enemyName << "'s armour is too though! Try an Uppercut!\n";
                }
                arrowsVolleyCounter++;
            }
            else {
                cout << "You are out of light arrows... give them time to generate!\n";
                choice = 1;
            }
        }
        else {
            choice = 6;
        }
                break;
    default:
        cout << "You did nothing... ";
        Sleep(textSpeed);
        cout << "Yet you get hit.\n";
        break;
    }
    if(inventory["Jeanne"]){
        if (partnerAttackDamage > enemyArmour) {
             cout << "Jeanne strikes too ";
             if (inventory["Cool Shoes"] == 1) {
                 partnerDamage *= 2;
             }
             partnerDamage = partnerAttackDamage - enemyArmour;
             enemyHp -= partnerDamage;
             cout << "inflicting " << partnerDamage << " damage!\n";
        }
        else {
             cout << "Jeanne's arrows are too weak for the " << enemyName << "'s armour\n";
        }
         if (rand() % 5 == 0) {
             cout << "Jeanne also heals you!\n";
             if (playerHp < playerMaxHp) {
                playerHp += 10;
                if (playerHp > playerMaxHp) {
                playerHp = playerMaxHp;
                }
             }
         }
    Sleep(750);
    }
    /*enemy attack*/ {
        if (choice != 3 && choice!=5) {
            if (enemyAttacksCounter % enemyAttackSpeed == enemyAttackSpeed - 1) {
                if (enemyAttackDamage > playerArmour) {
                    cout << "The monster strikes back ";
                    enemyDamage = enemyAttackDamage - playerArmour;
                    playerHp -= enemyDamage;
                    Sleep(500);
                    cout << "for " << enemyDamage << " damage!\n";
                    if (enemyLifeSteal) {
                        if (enemyHp + enemyLifeSteal >= enemyMaxHp) {
                            enemyHp = enemyMaxHp;
                        }
                        else {
                            enemyHp += enemyLifeSteal;
                        }
                        cout << "The enemy heals after each attack!\n";
                    }
                }
                else {
                    cout << "The " << enemyName << "'s attacks can't get through your armor!\n";
                }
            }
             if(!(enemyAttacksCounter % enemyAttackSpeed == enemyAttackSpeed - 1)) {
                cout << "The " << enemyName << " prepares a blow.\n";
             }
             enemyAttacksCounter++;
        }
    }
    system("pause");
    startOfCombat = 0;
    if (playerHp > 0 && enemyHp > 0 && run == 0) {
        combat();
    }
    else if (enemyHp < 1) {
              cout << "The enemy is defeated!\n";
              score += enemyPointsReward;
              itemReward();
              startOfCombat = -1;
    }
    else if (playerHp < 1) {
              gameOver();
    }

}
void itemReward() {
    if (enemyName == "Goblin"&& inventory["Goblin Dagger"]==0) {
        getGoblinDagger();
    }
    else if(enemyName.substr(0, 4) == "Ogre" && inventory["Ogre Belt"]==0){
        getOgreBelt();
    }else if(enemyName=="Lizardman" && inventory["Lizardman Scales"]==0){
        getLizardmanScales();
    }
    else if (enemyName=="Werewolf" && inventory["Werewolf Fangs"] == 0) {
        getWerewolfFangs();
    }
    else if (enemyName == "Demon" && inventory["Demon Blood"] == 0) {
        getDemonBlood();
    }
    else if (enemyName == "Skeleton" && inventory["Skeleton Bones"] == 0) {
        getSkeletonBones();
    }
    else if (enemyName == "Knight" && inventory["Knight Equipment"] == 0) {
        getKnightEquipment();
    }
    Sleep(750);
}
void fightHUD() {
    system("cls");
    /*the name*/ {

        cout << "Name: " << playerName;
        for (int i = 0; i < 20 - playerName.length(); i++) {
            cout << ' ';
        }
        cout << '|' << enemyName << "\n";
    }
    /*maybe ill do it later*/ {
        /*cout << "Race: " << playerRace;
        for (int i = 0; i < 20 - playerRace.length(); i++) {
            cout << ' ';
        }
        cout << '|' << enemyRace << "\n"; */
    }
    /*the health*/ {

        cout << "Health: ";
        SetConsoleTextAttribute(h, 2);
        cout << playerHp;
        SetConsoleTextAttribute(h, 7);
        for (int i = 0; i < 18 - numberLength(playerHp); i++) {
            cout << ' ';
        }
        cout << '|';
        SetConsoleTextAttribute(h, 2);
        cout << enemyHp << "\n";
        SetConsoleTextAttribute(h, 7);
    }
    /*the attack*/ {

        cout << "Attack: ";
        SetConsoleTextAttribute(h, 4);
        cout << playerAttackDamage;
        SetConsoleTextAttribute(h, 7);
        for (int i = 0; i < 18 - numberLength(playerAttackDamage); i++) {
            cout << ' ';
        }
        cout << '|';
        SetConsoleTextAttribute(h, 4);
        cout << enemyAttackDamage << "\n";
        SetConsoleTextAttribute(h, 7);
    }
    /*the armour*/ {
        cout << "Armour: ";
        SetConsoleTextAttribute(h, 8);
        cout << playerArmour;
        SetConsoleTextAttribute(h, 7);
        for (int i = 0; i < 18 - numberLength(playerArmour); i++) {
            cout << ' ';
        }
        cout << '|';
        SetConsoleTextAttribute(h, 8);
        cout << enemyArmour << "\n";
        SetConsoleTextAttribute(h, 7);
    }

}
void slaughter() {
    HUD();
    cout << "1.Move\n";
    int choice;
    choiceInput(choice);
    if (choice == 1) {
        if (rand() % 3 == 0) {
            cout << "Nothing interesting here...\n";
        }
        else {
            int x = rand() % 6;
            cout << "A " << enemys[x] << " appear. A fight is inevitable!\n";
            fight(x);
        }
    }
    else if (choice == 0) {
        exit(0);
    }
    else {
        cout << "You can't do anything else yet :D\n";
    }
    Sleep(1500);
    system("cls");
    if (playerHp < 1) {
        gameOver();
    }
    slaughter();
}
void adventure() {
    system("cls");
    cout << "You enter the dungeon...\n";
    Sleep(750);
    typeText("You finally enter the first room.\n");
    Sleep(750);
    room1();
}
void gameOver() {
    if (playerHp > 0) {
        system("pause");
        system("cls");
        cout << "Congratulations! You beat the game!\n"
            << "Your score: " << score<<endl;
    }
    else {
        cout << "\nGAME OVER!\nYour score: " << score << "\n";
        if (score > 500) {
            cout << "Not bad!";
        }
        else {
            cout << "Better luck next time!";
        }
    }
    cout << endl;
    system("pause");
    exit(0);
}