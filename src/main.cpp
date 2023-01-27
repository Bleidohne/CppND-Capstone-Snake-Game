#include <iostream>
#include <iomanip>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <string>
#include "highscore.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::string highscore_path = "Highscore.txt";
  int max_high_score = 5; 
  std::string player_name;
  int score, size;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  score = game.GetScore();                                     // Get the information out of the game for the Highscore.
  size = game.GetSize();

  std::cout << "What is your name? ";                          // Ask for the players name
  std::cin >> player_name;                                     // Wait for the user to type in his / her name.  
  if(player_name.length() > 12)                                 
    player_name.erase(12);                                     // Limit length to 15 (to handle the format of Highscore output easily).

  std::cout << "Your score " << player_name << " is : " << std::endl;   // Print the results of the game. 
  std::cout << "Score: " << score << "\n";
  std::cout << "Size: " << size << "\n";
  std::cout << std::endl << std::endl;                          // Leave a bit space between the Highscore. 
 
  // Create the Highscore List: 
  HighScore highscore(highscore_path,max_high_score);            // Create the HighScore Object.
  highscore.AddNewScoreToHighScore(player_name, score, size);             // Add the new Score and Player Name to the Highscore.
  highscore.PrintHighscoreToConsole();                                    // Print the current Highscore.  

  return 0;
}