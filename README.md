# Conways-Game-Of-Life
# Conways-Game-Of-Life

This assignment was written and assignment by Professor Kevin Lundeen at Seattle University.

Your assignment is to write a simple version of the game. From a given starting world, it will animate the generations. It will also allow worlds to be created on the console, saved from the current world, and loaded from previously saved worlds or other text files.

Your program must use a 2-D dynamically allocated array of chars to represent the world. A living cell is an asterisk and a dead cell is a blank. Your world should be the size of the input world (the examples are various sizes). The size (number of rows and number of columns) should be stored as data fields in your World class.

You will have a class World that has four required methods (and any number of other ones you see fit) enumerated below. It will also, since it uses dynamic memory, have to implement the big four: constructor, copy-constructor, destructor, and overloaded assignment-operator.

1. animate(numGenerations): This method displays the currently loaded world on the console. Then it moves the world to the next generation according to the rules of life (see reading above) and displays that next generation on the console. It repeats this for the number of generations specified by the user. Before each generation, clear the screen by using the clearConsole function (see below). After displaying each generation, wait 500 milliseconds or so using the sleepMilliseconds function (see below). Think about building the animate method by calling your some of your own private methods. Here are some ideas: display(), nextGeneration(), countNeighbors(row,col).

2. load: This method replaces the current world with the contents of a file. Each line in the file is interpreted as a row in the world. Every whitespace character corresponds to a dead cell in the world and every other character is interpreted as a living cell. Ignore any characters after the 100th character in a line and ignore any lines after the 40th line. Make your world size be adaptive to the file contents by making the width of your world equal to the longest line seen (max 100) and the length of your world equal to the number of lines in the file (max 40). Use dynamic 2-D arrays of char and you are not allowed to use the c_str() method of std::string to fetch the characters. It is typical and expected that you will have to read through the file twice--once to size it, and once to load it into a 2-D array.
