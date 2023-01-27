#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>                               // Header-File for handling strings. 
#include <vector>                                 // Header-File for handling the High-Score Vector. 
#include <fstream>
#include <ctime>
#include <chrono>

class PlayerScore                                            // New class with the intems for the Highscore list. 
{
  public:
      int GetPlayerScore();                                  // Access the private variables. 
      int GetPlayerSize();                                   
      int GetPlayerPosition();
      void SetPlayerPosition(int pos);                       // Position needs to be changeable when list gets updated. 
      std::string GetName();
      std::string GetDate();
      bool operator<(const PlayerScore& p_temp) const;             // Overload < operator for PlayerScore to sort the list 
 
     
      PlayerScore(int score, int size, 
                  std::string date, std::string pname);      // Class constructor
      ~PlayerScore();                                        // Class destructor

  private: 
      int _player_score;                                     // Score of the player
      int _player_size;                                      // Size of the snake
      std::string _player_date;                              // Date when the score was achieved
      std::string _player_name;                              // Name of the player. 

      

};


class HighScore                                     // New class to handle the High-Score List
{
  public:
    bool CheckHighScoreFile();                                                                  // Tries to open-up the Highscore File. 
    bool CreateHighScoreFile();                                                                 // Method to create High-Score File
    bool ReadHighScoreFile();                                                                   // Method to create High-Score File
    bool AddNewScoreToHighScore(std::string player_name, int score, int size);                  // Adds the new score to Highscore-Vector if high enough.
    bool PrintHighscoreToConsole();                                                             // Print Highscore to Console 


    HighScore(std::string hs_path, int max_high_score);                    // Constructor
    ~HighScore();                                                          // Destructor

  private: 
    std::vector<PlayerScore> _score_list;           // Vector with the High-Score Elements. 
    std::string _highscore_path;                    // HighScore should be in the programm path. 
    std::fstream _highscore_file;                   // Handle for the Highscore file. 
    int _max_size;                                  // Maximum size of the High-Score. 



};


#endif
