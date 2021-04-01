#pragma once
#include "Items.h"
void room1();
void choiceRoom1();
void room2();
void choiceJeanne();
void choiceRoom2();
void bossHallRoom();
void choiceRoom3();
void bossRoom();
void guardsBattle();
void marketRoom();
void ogreChoice();
void theKingFight();
void theKingFightHUD();
int firstChant = 1;
//definitions
void room1() {
    typeText("Out of nowhere, a Goblin jumps right in front of you!");
    Sleep(750);
    typeText(" Defeat him!\n");
    system("pause");
    fight(0);//goblin
    system("cls");
    typeText("Good job!");
    Sleep(750);
    typeText(" You killed him!\n");
    Sleep(750);
    typeText("You can finally take a better look at the room.\n");
    Sleep(750);
    typeText("Up ahead, is the door for the next room.\n");
    Sleep(750);
    typeText("The door from which you came is not there anymore.\n");
    Sleep(750);
    typeText("A skull on a pillar immediately catches your attention.");
    Sleep(750);
    typeText(" You can feel that it's dangling with power!\n");
    system("pause");
    choiceRoom1();

}
void choiceRoom1() {
    system("cls");
    typeText("What will you do?\n");
    cout<<"1. Go to the next room.\n";
    cout<<"2. Take the skull.\n";
    int choice;
    choiceInput(choice);
    switch (choice) {
    case 1:
        room2();
        break;

    case 2:        
        if (inventory["Red Skull"]) {
            typeText("You already took it!\n");
        }
        else {
            getRedSkull();
        }
        Sleep(750);
        choiceRoom1();
        break;
    default :
        typeText("Hey! You can't do that!");
        break;
    }
    system("pause");
}
void room2() {
    system("cls");
    typeText("You enter the next room");
    for (int i = 0; i < 3; i++) {
        cout << '.';
        Sleep(750);
    }
    typeText("\nYou see a big room, with a lot of stuff, most of which is trash.\n");
    Sleep(750);
    typeText("As you cautiously look around, you hear a loud yawn.\n");
    Sleep(750);
    typeText("You instantly look in that direction and observe another adventurer.\n");
    Sleep(750); 
    typeText("Near her, lies a white bow, made of crystal. ");
    Sleep(750);
    typeText("Looks like she almost fell asleep.\nWhat will you do?\n");
    choiceJeanne();
    system("cls");
    typeText("You look around, and think wether it is worth to search for items in this pile of trash.\n");
    Sleep(750);
    typeText("If you stay too much, monsters may appear, so be careful!\n");
    Sleep(750);
    typeText("Up ahead there are 2 entries.\n");
    Sleep(750);
    typeText("The first is a nice looking door, big fit for a giant.\n");
    Sleep(750);
    typeText("The second is a crawling space. You barely fit.\n");
    Sleep(750);
    choiceRoom2();
}
void choiceJeanne() {
    cout << "1. Silently assassinate the adventurer, and then steal the bow.\n"
        << "2. Ask her to join you.\n";
    int JeanneChoice;
    choiceInput(JeanneChoice);
    switch (JeanneChoice) {
    case 1:
        typeText("You easily put her to sleep.\n");
        getHolyCrystalBow();
        break;
    case 2:
        if (rand()%10==0){
            typeText("Jeanne: STAY AWAY!\n");
            Sleep(750);
            typeText(playerName+": Wait! I don't want to fight. I want you to join me.\n");
            Sleep(750);
            typeText("Jeanne: In your dreams!\n");
            Sleep(750);
            typeText("And so, the fight begins!\n");
            canRun = 0;
            Sleep(1500);
            fight(6);//Jeanne
            canRun = 1;
            getHolyCrystalBow();
        }
        else{
            typeText("Jeanne: STAY AWAY!\n");
            Sleep(750);
            typeText(playerName + ": Wait! I don't want to fight. I want you to join me.\n");
            Sleep(750);
            typeText("Jeanne: Sure! Adventuring alone is booooring... Also I need man power to defeat The King.\n");
            Sleep(750);
            typeText(playerName+": That's great! Wait, who is The King?\n");
            Sleep(750);
            typeText("Jeanne won't respond...\n");
            Sleep(750);
            getJeanne();
            system("pause");
        }
        break;
    default:
        typeText("Hey! You can't do that!");
        break;
    }
}
void choiceRoom2() {
    typeText("What will you do?\n");
    cout << "1. Enter the enormous door.\n"
        <<"2. Enter the crawling space.\n"
        << "3. Search for items.\n";
    int choiceMadeInRoom2, chanceSearchItems;
    choiceInput(choiceMadeInRoom2);
    switch (choiceMadeInRoom2) {
    case 1:
        bossHallRoom();
        break;
    case 2:
        marketRoom();
        break;
    case 3:
        chanceSearchItems = rand() % 5;
        if (chanceSearchItems == 0) {
            getCommonItem();
        }
        else if (chanceSearchItems < 3) {
            int x = rand() % 6;
            cout << "A " << enemys[x] << " appear. A fight is inevitable!\n";
            fight(x);
        }
        else {
            cout << "You found nothing yet, keep searching and you'll find something!\n";
        }
        choiceRoom2();
        break;
    default:
        typeText("Hey! You can't do that!");
        choiceRoom2();
        break;
    }
    system("cls");
}
void marketRoom() {
    system("cls");
    typeText("You keep crawling");
    for (int i = 0; i < 3; i++) {
        cout << '.';
        Sleep(750);
    }
    typeText(" until you can finally see the end.\n");
    Sleep(750);
    typeText("As you get closer, it gets steeper, causing you to fall.\n");
    Sleep(750);
    typeText("But what is this?\n");
    Sleep(750);
    typeText("You just landed in the middle of a public market! ");
    Sleep(750);
    typeText("It's gigantic!\n");
    Sleep(750);
    typeText("You wander aimlessly, gazing at the many mysterious stands.\n");
    Sleep(750);
    typeText("Merchant: Beat the Ogre Commander and get rewarded!\n");
    Sleep(750);
    typeText("His offer is tempting, but that Ogre sure is strong.\nWhat will you do?\n");
    Sleep(750);
    ogreChoice();
    system("cls");
    typeText("You keep on going.\n");
    Sleep(750);
    typeText("You arrive at the center of the market. From here you can take a good look over the whole market.\n");
    Sleep(750);
    typeText("There is a part with many houses, and a huge forest. In the middle of the forest there sits a castle.\n");
    Sleep(750);
    typeText("This place is like a small utopia!\n");
    Sleep(750);
    typeText("No, this is no utopia. The people look sad.\n");
    Sleep(750);

    if (inventory["Red Skull"]) {
        typeText("Bandit: Haha! Surprise attack! Nice skull you got there!\n");
        Sleep(750);
        typeText("        I bet The King will fetch a high price for this item infused with dark magic.");
        system("pause");
        system("cls");
        canRun = 0;
        createEnemy(8);//bandit
        fightHUD();
        cout << "Bandit's surprise attack inflicts 30 damage, and reduces you armor by 10.\n";
        playerArmour -= 10;
        if (playerArmour < 0) playerArmour = 0;
        playerHp -= 30;
        if (playerHp <= 0) gameOver();
        combat();
        canRun = 1;
        system("cls");
        typeText("Bandit: Forgive me! I didn't know you were this strong!\n");
        Sleep(750);
        typeText("And he runs away.\n");
        Sleep(750);
    }

    typeText("There is only one thing left to do... Head to the castle!\n");
    Sleep(750);
    system("pause");
    system("cls");
    
    typeText("The only way to the castle is trough the forest,");
    Sleep(750);
    typeText(" which is filled with monsters!\n");
    Sleep(750);
    system("pause");
    for (int i = 0; i < 10; i++){
        system("cls");
        typeText("And you keep walking...\n");
        Sleep(750);
        fight(rand() % 6);
    }
    system("cls");
    typeText("You finally arrived at the castle!\n");
    Sleep(750);
    bossHallRoom();
}
void ogreChoice() {
    cout << "1. Accept the offer.\n"
        << "2. Keep wandering.\n";
    int choiceForOgre;
    choiceInput(choiceForOgre);
    switch (choiceForOgre) {
    case 1:
        createEnemy(1);//ogre
        enemyName = "Ogre Commander";
        enemyMaxHp *= 10;
        enemyHp *= 10;
        enemyAttackDamage *= 3;
        canRun = 0;
        system("cls");
        combat();
        canRun = 1;
        system("cls");
        typeText("Merchant: Hey, you sure know how to fight. You may even be able to beat The King!\n");
        Sleep(750);
        typeText(playerName+ ": The... King? Who is that?\n");
        Sleep(750);
        typeText("Merchant: You don't know who The King is? Whatever, I'll tell you. \n");
        Sleep(750);
        typeText("             He is the ruler of this dungeon, though his reign is troublesome. He does nothing and the taxes are high.\n");
        Sleep(750);
        typeText("             It is known that he practices dark magic. No wonder he is like that. He just seeks more and more power.\n");
        Sleep(750);
        typeText("             Someone needs to stop him before he gets too strong, can I entrust you with this task?\n");
        Sleep(750);
        typeText(playerName + ": Alright, I'll do it. I will deafeat The King.\n");
        Sleep(750);
        typeText("Merchant: Finally, his reign will come to an end! Here! Take this as a reward for beating the Ogre.\n");
        Sleep(750);
        typeText("             Use it on The King and he won't stand a chance! I wish you good luck!\n");
        Sleep(750);
        getEMPGrenade();
        system("pause");
        break;
    case 2:
        typeText("Merchant: You'll never get this deal again!\n");
        Sleep(750);
        break;
    default: 
        typeText("Hey, you can't do that!\n");
        Sleep(750);
        ogreChoice();
        break;
    }
}
void bossHallRoom() {
    system("cls");
    typeText("You hardly manage to open the door...\n");
    Sleep(750);
    typeText("Entering, you see a big hall.\n");
    Sleep(750);
    typeText("In the middle, lies a red carpet that leads straight to another gigantic door, similar to the one from before.\n");
    Sleep(750);
    typeText("The walls are decorated with many paintings of the same guy. All of them are labeled with \"The King\".\n");
    Sleep(750);
    typeText("On one side, and on the other side of the carpet, 3 pair of knights await without flinching.\n");
    Sleep(750);
    typeText("You take one step forward. The floor behind you crumbles, and your only choice is to go forward.\n");
    Sleep(750);
    typeText("You take another step. One of the knights approach you with red menacingly eyes.\n");
    Sleep(750);
    typeText("Looks like a fight is about to break out.\n");
    system("pause");
    fight(7);//knight
    system("cls");
    typeText("One is down, but the others won't let you go either. You'll have to fight all of them!\n");
    Sleep(750);
    typeText("The knight's movements are slow.\nWhile they strike once you strike twice!\nJust block their attacks and you'll be fine\n.");
    system("pause");
    for (int i = 0; i < 5; i++)
    {   
        system("cls");
        typeText("Another knight comes straight to you...\n");
        Sleep(750);
        fight(7);//knight
    }
    system("cls");
    typeText("The only thing left is to open the door.\n");
    Sleep(750);
    typeText("However, after all this fight a nap may help you recover.\n");
    Sleep(750);
    typeText("What will you do?\n");
    Sleep(750);
    choiceRoom3();
}
void choiceRoom3() {
    cout << "1. Enter the next room.\n"
        << "2. Sleep.\n";
    int choiceMadeInRoom3;
    choiceInput(choiceMadeInRoom3);
    switch (choiceMadeInRoom3) {
    case 1:
        bossRoom();
        break;
    case 2:
        if (playerHp == playerMaxHp) {
            typeText("You don't feel like sleeping.\n");
        }
        else {
            typeText("You feel refreshed.\n");
            playerHp = playerMaxHp;
        }
        choiceRoom3();
        break;
    default:
        break;
    }
}
void bossRoom() {
    system("cls");
    typeText(playerName+": The King! I've finally found you. The people are talking ill of you!\n");
    Sleep(750);
    typeText("The King: They do? Haha! I'll raise the taxes even more.\n");
    Sleep(750);
    typeText(playerName+ ": No! I won't let you!\n");
    Sleep(750);
    typeText("The King: GUARDS!\n");
    Sleep(750);
    typeText("Four malicious automated guards, driven by dark magic assault you!\n");
    Sleep(750);
    if (inventory["EMP Grenade"]) {
        typeText("Now is the time to use that EMP Grenade!\n");
        Sleep(750);
        cout << "1. Use EMP Grenade\n"
            << "2. I don't need it!\n";
        int empChoice;
        choiceInput(empChoice);
        switch (empChoice) {
        case 1:
            typeText("Haha! The EMP Grenade completely shut down the guards. The King is the only one left.\n");
            Sleep(750);
            score += 100;
            break;
        case 2:
            guardsBattle();
            break;
        default:
            typeText("You hesitated. They destroyed your bomb.\n");
            Sleep(750);
            guardsBattle();
            break;
        }
    }
    typeText("The King: You managed to beat my guards? Hahahaha! This is getting fun. You'll be worth my time!\n");
    Sleep(1500);
    createEnemy(10);
    theKingFight();
    cout << "The End!\n";
    system("pause");
}
void guardsBattle() {
    typeText("The fight begins!\n");
    for (int i = 1; i <= 4; i++) {
        createEnemy(9);
        if (i == 1) {
            enemyName += " Mk. I";
        }
        else {
            cout << "The next guard charges!\n";
            enemyName += "I";
        }
        if (i == 4) {
            enemyName += "King's Guard Mk IV";
        }
        enemyMaxHp += 10 * (i - 1);
        enemyHp += 10 * (i - 1);
        enemyAttackDamage += 10 * (i - 1);
        enemyPointsReward += 10 * (i - 1);
        combat();
        system("cls");
    }
}
void theKingFightHUD() {
    /*the name*/ {

        cout << "Name: " << playerName;
        for (int i = 0; i < 20 - playerName.length(); i++) {
            cout << ' ';
        }
        cout << '|' << enemyName << "\n";
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
}
void theKingFight() {
    system("cls");
    string kingsQuotes[] = {"Are you really trying to beat me? I like you!\n","Welcome... To die!\n", "And so, you must be silenced.\n", "I am your salvation through destruction.\n", "Do you know the definition of insanity...\n"};
    int numberOfQuotes = sizeof(kingsQuotes) / sizeof(kingsQuotes[0]);
    theKingFightHUD();
    typeText(kingsQuotes[rand()%numberOfQuotes]);
    string counterSpell, weakChant;
    int counterSpellColour;
    switch (rand() % 8) {
    case 0:
        SetConsoleTextAttribute(h, 4);
        cout << "Let my madness manifest! FIRE!\n";
        counterSpell = "WATER";
        weakChant = "water";
        counterSpellColour = 3;
        break;
    case 1:
        SetConsoleTextAttribute(h, 3);
        cout << "River of the fount of life flow ye out across the sky! WATER!\n";
        counterSpell = "NATURE";
        weakChant = "nature";
        counterSpellColour = 10;
        break;
    case 2:
        SetConsoleTextAttribute(h, 10);
        cout << "You reap what you sow! NATURE!\n";
        counterSpell = "FIRE";
        weakChant = "fire";
        counterSpellColour = 4;
        break;
    case 3:
        SetConsoleTextAttribute(h, 6);
        cout << "Thunder sprites, pay heed, and strike with your electric shock! LIGHTNING!\n";
        counterSpell = "EARTH   ";
        weakChant = "earth";
        counterSpellColour = 12;
        break;
    case 4:
        SetConsoleTextAttribute(h, 12);
        cout << "I stand there, hearing the sound of crumbling ground! EARTH!\n";
        counterSpell = "WIND";
        weakChant = "wind";
        counterSpellColour = 9;
        break;
    case 5:
        SetConsoleTextAttribute(h, 9);
        cout << "Hear the roar of the Wind God that reduces everything to a cloud of dust! WIND!\n";
        counterSpell = "LIGHTNING";
        weakChant = "lightning";
        counterSpellColour = 6;
        break;
    case 6:
        SetConsoleTextAttribute(h, 8);
        cout << "Oh pitiful shadow lost in the darkness, bring torment and pain to others! DARKNESS!\n";
        counterSpell = "LIGHT";
        weakChant = "light";
        counterSpellColour = 15;
        break;
    case 7:
        SetConsoleTextAttribute(h, 15);
        cout << "Illuminate the enemy! LIGHT!\n";
        counterSpell = "DARKNESS";
        weakChant = "darkness";
        counterSpellColour = 8;
        break;
    }
    SetConsoleTextAttribute(h, 7);
    int timer = clock(), succesfullChants=0, usedWeakChant=0, chantTime=10000;
    string chant;
    if (firstChant) {
        SetConsoleTextAttribute(h, 7);
        cout << "Chant the word that counters the element that The King invoked.\nIn this case you will need: ";
        SetConsoleTextAttribute(h, counterSpellColour);
        cout << counterSpell;
        SetConsoleTextAttribute(h, 7);
        cout << "\nChant the spell as much and as fast as you can!\n";
        firstChant = 0;
        chantTime -= 5000;
    }
    Sleep(2000);
    cout << "CHANT!\n";
    SetConsoleTextAttribute(h, counterSpellColour);
    SetConsoleTextAttribute(h, counterSpellColour);
    cin.get();
    while (clock() - timer < chantTime)
    {
        getline(cin,chant);
        if (chant == counterSpell) {
            succesfullChants++;
        }
        else if (chant==weakChant) {
            usedWeakChant = 1;
        }
    }
    SetConsoleTextAttribute(h, 7);//NORMAL
    if (succesfullChants==0) {
        cout << "You did not block his spell fast enough!\nYou take " << enemyAttackDamage << " damage!\n";
        playerHp -= enemyAttackDamage;
        chantTime -= 1000;
    }
    else 
    if (succesfullChants == 1) {
        cout << "You blocked his attack!\n";
        chantTime += 1000;
    }
    else {
        cout << "You chanted so fast that you blocked his attack and you strike him " << succesfullChants << " times!\n"
            <<"You deal "<<succesfullChants*playerAttackDamage<<" to The King!\n";
        enemyHp -= succesfullChants * playerAttackDamage;
        chantTime -= 1000;
    }
    if (usedWeakChant) {
        cout << "You used the good chant, but you have to scream it in order to be powerfull enough!\n";
    }
    Sleep(1500);
    system("pause");
    if (playerHp > 0 && enemyHp > 0) {
        theKingFight();
    }
    else if (enemyHp <= 0) {
        cout << "You defetead The King!\n";
        score += 1000;
        system("pause");
        gameOver();
    }
    else if (playerHp < 0) {
        gameOver();
    }
}
void glitchyText(string t) {
    for (int i = 0; i < t.length(); i++) {
        Sleep(textSpeed);
        if (rand() % 4) {
            SetConsoleTextAttribute(h, rand() % 15 + 1);
        }
        else {
            SetConsoleTextAttribute(h, rand() % 8190 + 1);
        }
        cout << t[i];
    }
    SetConsoleTextAttribute(h, 7);//normal
}