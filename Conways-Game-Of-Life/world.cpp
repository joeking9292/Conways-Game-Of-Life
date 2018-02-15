//Joe Noonan
//world.cpp
//2018/02/07
//Purpose: The purpose of this file is to hold all the functions of the world.h
// file.
//Input: the only input into this function is the file that the user enters and 
// the number of generations that the user wants to run.
//Output: The outputs of these functions are things like error messages and the
// game board.


#include "world.h"
#include <iostream>
#include <string>
#include <thread>
#include <fstream>

using namespace std;


World::World(){
	MAX_COLS = 40;
	MAX_ROWS = 100;
	twoD = nullptr;
	numCols = numRows = 0;
	loadDefaultWorld();
}

World::~World(){
	for (int row = 0; row < numRows; row++) {
		delete[] twoD[row];
	}
	delete[] twoD;
	twoD = nullptr;

	/*
	for (int i = 0; i < numRows; i++) {
		delete[] newBoard[i];
	}
	delete[] newBoard;
	newBoard = nullptr;*/
}

void World::loadDefaultWorld(){
	string defaultFileName = "/home/fac/lundeenk/submit/18wq1430/files/gosper.w";
	ifstream worldFile;
	worldFile.open(defaultFileName);

	if (worldFile.fail()) {
		cout << "File did not open." << endl;
		exit(1);
	}

	numRows = numCols = 0;
	string line;
	while (numRows < MAX_ROWS && getline(worldFile, line)) {
		numRows++;
		int length = static_cast<int>(line.length());
		if (length > numCols) {
			if (length > MAX_COLS)
				numCols = MAX_COLS;
			else
				numCols = length;
		}
	}
	worldFile.close();//close default file
	worldFile.open(defaultFileName);//opens default file

	twoD = new char*[numRows];
	for (int r = 0; r < numRows; r++) {
		twoD[r] = new char[numCols];//initialize the board
	}
	
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			worldFile.get(twoD[i][j]);//fills the board
		}
	}
	worldFile.close();
}

void World::loadUserWorld(string fileName){
	ifstream userFile;
	userFile.open(fileName);//user inputed file is opened here

	if (userFile.fail()) {
		cout << "File did not open." << endl;//error message
		exit(1);
	}

	numRows = numCols = 0;
	string line;
	while (numRows < MAX_ROWS && getline(userFile, line)) {
		numRows++;
		int length = static_cast<int>(line.length());
		if (length > numCols) {
			if (length > MAX_COLS)
				numCols = MAX_COLS;
			else
				numCols = length;
		}
	}
	userFile.close();//close file
	userFile.open(fileName);//open file again

	twoD = new char*[numRows];//initializing the board
	for (int r = 0; r < numRows; r++) {
		twoD[r] = new char[numCols];
	}

	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			userFile.get(twoD[i][j]);//filling the board
		}
	}
	userFile.close();//close file
}

void World::numGenerations(){
	newBoard = new char*[numRows];
	for (int c = 0; c < numRows; c++) {
		newBoard[c] = new char[numCols];
	}//allocating space for the copy array
	
	for (int r = 0; r < numRows; r++){//these for loops are reassigning
									  //the board properly.
		for (int c = 0; c < numCols; c++) {
			int lifeCount = numOfNeighbors(r, c);//function call checks the neighbors.

			newBoard[r][c] = DEATH;
			if (newBoard[r][c] == LIFE && lifeCount < 2){
				newBoard[r][c] = DEATH;
			}
			else if (newBoard[r][c] == LIFE && (lifeCount == 2 || lifeCount == 3)){
				newBoard[r][c] = LIFE;
			}
			else if (newBoard[r][c] == LIFE && lifeCount>3){
				newBoard[r][c] = DEATH;
			}
			else if (newBoard[r][c] == DEATH && lifeCount == 3){
				newBoard[r][c] = LIFE;
			}
		}
	}
	twoD = newBoard;//resets the board to how it should be with new neighbors.
}

void World::animate(int generations){
	for (int n = 0; n < generations; n++) {
		displayGame();
		numGenerations();
		sleepMilliseconds(DELAY);//delays the game by 500 milliseconds
		clearConsole();//clears the console
	}
}

void World::sleepMilliseconds(int n){
	this_thread::sleep_for(std::chrono::milliseconds(n));
}

void World::clearConsole(){
	cout << "\x1B[2J\x1B[H";
}

void World::displayGame() {
	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			cout << twoD[r][c] << ' ';//prints out the board.
		}
		cout << endl;
	}
}

int World::numOfNeighbors(int row, int column) {
	int neighbors = 8;//start with 8 neighbors and checks the space around.
	if ((row - 1) >= 0) {
		if (twoD[row - 1][column] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((row - 1) >= 0 && (column - 1) >= 0) {
		if (twoD[row - 1][column - 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((row - 1) >= 0 && (column + 1) < numCols) {
		if (twoD[row - 1][column + 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((column - 1) >= 0) {
		if (twoD[row][column - 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((column + 1) < numCols) {
		if (twoD[row][column + 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((row + 1) < numRows) {
		if (twoD[row + 1][column] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((row + 1) < numRows && (column - 1) >= 0) {
		if (twoD[row + 1][column - 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}

	if ((row + 1) < numRows && (column + 1) < numCols) {
		if (twoD[row + 1][column + 1] == DEATH) {
			neighbors--;
		}
	}
	else {
		neighbors--;
	}
	return neighbors;//returns the integer value of neighbors.
}