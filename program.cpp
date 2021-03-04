#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

string character_name;
string action;
int temp_training;
int number_of_enemies;
int enemy_strength;

struct character_type{
    string name;
    int health; 
    int strength;
    int inteligence;
    int points;
};

character_type character_creation(){
    character_type player;
    player.health = 10;
    player.strength = 5;
    player.points = 0;

    cout << "Whats your name, brave adventurer ?" << endl;
    cin >> player.name;
    cout << "Hail " << player.name << ". Welcome to the arena" << endl << endl;
    
    return player;
}

int fight(character_type player){
    srand(time(NULL));
    
    cout << "How many foes you want to challenge ? (1-4)" << endl;
    cin >> number_of_enemies;
    cout << "Let the fight begin!" << endl;
    enemy_strength = (rand() % 8) + number_of_enemies;
    cout << "Enemy strength:" << enemy_strength << " Player strength:" << player.strength << endl;

    if (enemy_strength < player.strength){
        cout << "You won!" << endl;
        player.points += 10;
        cout << player.points << endl;
    }
    else if (enemy_strength > player.strength){
        cout << "You lost" << endl;
    }
    else {
        cout << "Draw" << endl;
    }

    return player.points;
}

int train(character_type player){
    cout << "Training cost 10 points and will raise your strength by 1, how many hours will you train ?" << endl;
    cin >> temp_training;
    if (temp_training * 10 <= player.points){
        player.strength += 1;
        cout << player.strength << endl;
        return player.strength;
    }
    else {
        cout << "You dont have enough money" << endl;
    }  
}

void help(){
    cout << "help - ask for directions" << endl << "fight - you will face powerful enemies" << endl; 
    cout << "train - you can train your strength" << endl << "quit - you will rot in the dungeon" << endl;
}

void status(character_type player){
    cout << player.name << ": " << player.strength << ": " << player.points << endl;
    }

int main(){
    character_type player;
    player = character_creation();
    help(); 

    while (1){
        cout << endl << "Choose your action:";
        cin >> action;
        if (action == "fight"){
            player.points = fight(player);
        }
        if (action == "quit"){
            break;
        }
        if (action == "help"){
            help();
        }
        if (action == "status"){
            status(player);
        }
        if (action == "train"){
            player.strength = train(player);
            player.points -= (player.strength - 5) * 10;
        }
    }
}