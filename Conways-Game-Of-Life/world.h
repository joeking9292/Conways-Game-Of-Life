//Joe Noonan
//world.h
//2018/02/07
//Purpose: the purpose is to declare the World class in this file.
//Input: there is no input form the user.
//Output: there is no output in this function.


#pragma once
#include <string>

class World{
private:
	static const int DELAY = 500;
	static const char DEATH = ' ';
	static const char LIFE = '*';
	char **newBoard;
	char **twoD;
	int numRows, numCols, MAX_ROWS, MAX_COLS;
public:
	World();// This is the constructor of the World class.

	~World();//This is the destructor of the World class.
	
	void loadDefaultWorld();//This loads the default world with the file that is 
	                        // that is hard coded into the function.
	
	void loadUserWorld(std::string fileName);//This function loads the file that
	                                         //was given to the computer by the user.
	
	void numGenerations();//This is the function that does the main process of
	                      //modifying the game board to make neighbors or kill things.
	
	void animate(int generations);//This function animates the game.
	
	void sleepMilliseconds(int n);//This creates the delay between generations of 
	                              //the game.
	
	void clearConsole();//This clears the console that is displayed.
	
	void displayGame();//This displays the game board that is presently filled.
	
	int numOfNeighbors(int row, int column);//This is the function that checks the
	                                       //number of neighbors around alive things.
};

