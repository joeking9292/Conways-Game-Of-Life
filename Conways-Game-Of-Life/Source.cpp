//Joe Noonan
//p2.cpp
//2018/02/07
// Purpose: the purpose of this file is to run the game of life until the
// the player quits.
//input: the inputs are the responses to the user prompts which includes
// inputing files and letters to quit, load a file, and also the
// number of generations that want to be viewed.
//output: the output is the game display and the game prompts to the user
// for quitting, loading a file, and inputing number of generations.


#include <iostream>
#include <string>
#include "world.h"

using namespace std;

int main() {
	cout << "Welcome to the Game of Life!" << endl;

	World a;//initialize the object

	bool quit = false;
	char userInput;
	int numberOfGenerations;
	while (!quit) {//main part of playing the game
		a.displayGame();
		cout << "Available commands:" << endl;
		cout << "Next Generation(s): n#" << endl;
		cout << "Load World:         l fileName" << endl;
		cout << "Quit:               q" << endl;
		cout << "Command: " << endl;
		cin >> userInput;

		if (userInput == 'q') {//option for quiting
			cout << "Goodbye!" << endl;
			return 0;
		}
		else if (userInput == 'n') {//option for number of generations to play
			cin >> numberOfGenerations;
			a.animate(numberOfGenerations);
		}
		else if (userInput == 'l') {//option of loading a user file
			string fileName;
			cout << "Enter file here: ";
			cin >> fileName;
			a.loadUserWorld(fileName);
		}
	}
	return 0;
}