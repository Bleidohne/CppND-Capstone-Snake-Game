# CPPND: Capstone Snake Game Upgrade

My project is to extend the given snake programm with some features. The updated features are: 
- User inputs name into consol after the game is finished
- The game creates a Highscore list and adds the user name, score and current date
- The Highscore list is stored in the directory of the game as txt-file
- If no Highscore list is available a list is created with to pre-defined entries
- After the list is updated it is printed to the console in a formated way 
- During the Game a random red obstacle which immediately ends the game is implemented.

The additional project structure and updates are: 
o Highscore.h / Highscore.cpp
	- Class PlayerScore: 	Objects which store the player data so they can be 
				used to create the Highscore list. And the relevant
				public methos and private members. 
				To sort the highscore list the operator < is overloaded.
	- Class Highscore:	Contains the Highscore-List with the vector of 
				PlayerScore objects. And the relevant public methods
				and private members. 
				The class Highscore cares about the highscore text file
				and creates and updates the file. 
o main.cpp
	- Starts the game as described in the root repository of the snake game
	- Afte the game is over it waits for the user name
	- The user score is printed
	- The Highscore-List is read or if not available generated by the costructor
	- The Highscore-List is updated and saved again. (AddNewScoreToHighScore)
	- The Highscore-List is printet formated to the console
	- Programm is over

o renderer.cpp / renderer.h
	- In the Render() method the bad food which ends the game immediately is rendered

o game.cpp / game.h
	- The additional Bad food is placed in PlaceFood()
	- Check if snake run into bad food in Update() method and exit game immediately. 

As descirbed in the udacity project the game runs in following phases: 
1. Main creates the Controller, the game and the renderer object
2. Main starts the game loop
3. The Game loop updates the conller (user input), the game with the snake and food, 
   and the renderer who does the graphical stuff. 
4. After Game over the main starts to handle the new Highscore-List. 

# Targeted criterias: 
During the project the task is to update the readme with the build instructions which are carry-over as no other dependencies were introduced. The Readme indicates that the Snake
project was chosen. The project is tested so that it compiles and runs with make and cmake.

Criteria: (5 Criterias must be met at least)
(1) 	The project demonstrates an understanding of C++ functions and control structures
	See file highscore.cpp / highscore.h: 
	- Project is organized in functions with clear names and comments

(2) 	The project reads data from a file and processes the data, or the program writes
	data to file
	- Project does both. Reads data from file into a vector of objects. Sorts the 
	  vector of objects and writes the data back to the text file. 
	highscore.cpp examples: 	
		o CreateHighScorefile() Line 90
		o ReadHighScoreFile() Line 114
		o AddNewScoreToHighScore(..) Line 149
		o PrintHighscoreToConsole() Line 190

(3) 	The project accepts user input and processes the input 
	- The user name is requested in the console
	- The name length is limited to easily handle the PrintHighscoreToConsole() with 		  easy formating
	- The user name is safed into a file
	main.cpp examples:
		o Line 31 - Line 34: Request User Name and limit length. 
		o Line 43: Hand over the name to Highscore. 
	highscore.cpp examples:
		o Line 159: Create a new element with user name, score, size, date
		o Line 160: Add the element to the vector

(4) 	The project uses Object Oriented Programming techniques
	- highscore.cpp / highscore.h is organized in classes (PlayerScore, Highscore)
	- Each class contains methods and variables in public or private area

(5) 	Classes use appropriate access specifies for class members
	- highscore.cpp / highscore.h
		o Line 10 / 30 in highscore.h defines the class with the members

(6) 	Classes absctract implementation details from their interfaces
	- highscore.cpp / highcscore.h
		o All member functiions have clear names which indicates what they are 
		  doing + comments

(7) 	Classes encapsulate behavior 
	- highscore.cpp / highscore.h
		o States / variables are accessed via get and set methods


	


This project uses the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
