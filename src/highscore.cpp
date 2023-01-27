#include "highscore.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <algorithm>


// Constructor
PlayerScore::PlayerScore(int score, int size, 
                         std::string date, std::string pname)          // Constructor PlayerScore
{
    _player_score = score; 
    _player_size = size; 
    _player_date = date; 
    _player_name = pname; 

}

// Standard Destructor
PlayerScore::~PlayerScore()
{}

int PlayerScore::GetPlayerScore()
{
    return _player_score;
}

int PlayerScore::GetPlayerSize()
{
    return _player_size;
}

std::string PlayerScore::GetDate()
{
    return _player_date;
}

std::string PlayerScore::GetName()
{
    return _player_name;
}

bool PlayerScore::operator<(const PlayerScore& p_temp) const    // Overload < operator for PlayerScore to sort the list 
{                                                               // https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
    return _player_score < p_temp._player_score;    
          
}



// Functions of HighScore:
//===============================================

HighScore::HighScore(std::string hs_path, int max_high_score)                   // Constructor for HighScore List.
{
    _max_size = max_high_score;                                                 // sets the maximun size of the High-Score. 
    _highscore_path = hs_path;                                                  // Set the path in the constructor.  
    if(!CheckHighScoreFile())                                                   // Try to open the Highscore file. 
        CreateHighScoreFile();                                                  // Create the Highscore file. 
    
    ReadHighScoreFile();                                                        // Read the file into the vector.  

}

HighScore::~HighScore()                                                         // Destructor
{
    
}

bool HighScore::CheckHighScoreFile()
{
    _highscore_file.open(_highscore_path);                                      // Try to open the Highscore

    if(_highscore_file.is_open()) 
    {
            // std::cout <<"Highscore File is available." << std::endl;
            _highscore_file.close();                                            // Close the file. 
            return (1);
    }     
    else
    {
           // std::cout <<"Highscore File could not be openend - is not available." << std::endl;
            return (0);
    }
}

bool HighScore::CreateHighScoreFile()                                               // Creates a new pre-filled Highscore
{

        _highscore_file.open(_highscore_path, std::ios_base::app);                  // Try to create the file
            if(_highscore_file.is_open())
            {
                //_highscore_file << "Highscore is:" << std::endl;
                //_highscore_file << "Position " <<"Name "<<"Score "<<"Size "<<"Date "<<std::endl;
                _highscore_file << "1 " << "Simon " <<"1 " << "2 " << "01.01.2023 "<<std::endl;
                _highscore_file << "2 " << "Martin " <<"2 "<< "3 " << "02.01.2023 "<<std::endl; 
                //_highscore_file << "END;" << std::endl;
                _highscore_file.close();                                // Close the file.               
               //  std::cout <<"File created" <<std::endl;
                return (1);
            }
                
            else
            {
               //  std::cout <<"Failed to create file"<<std::endl;
                return (0);
            }
}


bool HighScore::ReadHighScoreFile()             // Get the Highscore out of the file int he vector.
{
    _highscore_file.open(_highscore_path);      // Open the Highscore File
    
    if(_highscore_file.is_open())
    {
        std::string pscore, psize, ppos, pdate, pname; // Buffer variables. 

        while(_highscore_file >> ppos)              // Read out the file
        {
            
            _highscore_file >> pname;               // Information is seperated by "space"
            _highscore_file >> pscore;              // each loop reads one line in the highescore file 
            _highscore_file >> psize;               // until end of file is reached. 
            _highscore_file >> pdate;
           
            _score_list.emplace_back(PlayerScore(std::stoi(pscore),std::stoi(psize),pdate,pname)); // stoi converts string to integer.
            
        }
        _highscore_file.close();

        // std::cout << "Highscore File imported" << std::endl;
            
        return(1);
    }
    else
    {
        // std::cout <<"Failed to import file"<<std::endl;
        return (0);
    }

    return (0);
}


bool HighScore::AddNewScoreToHighScore(std::string player_name, int score, int size)            // Try to add the new Highscore into the Vector list. 
{
 
    std::cout << "Updating Highscore list" << std::endl; 
 
    char c_time[50];                                                                            // Buffer the Date and Time
    auto t_time = std::time(nullptr);                                                           // Taken from https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c 
    std::strftime(c_time, sizeof(c_time), "%d.%m.%Y", std::localtime(&t_time));                 // Format Date for the Highscore list
    //std::cout << c_time << std::endl;                                                         // Ouptut to check date and time.                 

    PlayerScore new_score(score,size,c_time,player_name);                                   // Create new item to be sorted into the Highscore-List
    _score_list.emplace_back(new_score);                                                        // Add new score to List 
    std::sort(_score_list.begin(),_score_list.end());                                           // Sort the list with overloaded operator <. 

    // Write the Highscore File, and limit to maximum number: 
    _highscore_file.open(_highscore_path, std::ios_base::trunc | std::ios_base::out);           // To update the sorted Highscore open it and clear it 
            if(_highscore_file.is_open())                                                       // Cleare because a new sorted list needs to be created. 
            {
                int j = 1;                                                                      // Position in High-Score. 
                for(int i = _score_list.size()-1; i >= 0; i--)                                  // Go through the vector. 
                {
                    if(j <= _max_size)                                                          // Limit the Highscore List.
                    {
                        _highscore_file << std::to_string(j) << " " << _score_list[i].GetName() << " " << std::to_string(_score_list[i].GetPlayerScore())
                                    << " " << std::to_string(_score_list[i].GetPlayerSize()) << " " << _score_list[i].GetDate() << std::endl;
                        // std::cout << "Writing to file, run " << i << std::endl;
                        j++;
                    }
                }
                _highscore_file.close();                                // Close the file.               
                //std::cout <<"Highscore Updated" <<std::endl;
                return (1);
            }
                
            else
            {
                //std::cout <<"Failed to Update Highscore"<<std::endl;
                return (0);
            }       
}

bool HighScore::PrintHighscoreToConsole()
{

    std::string pscore, psize, ppos, pdate, pname; // Buffer variables. 
    
    _highscore_file.open(_highscore_path);      // Open the Highscore File
    
    if(_highscore_file.is_open())
    {
        std::cout << "          ----The SNAKE Highscore ---- " <<std::endl;
        
        std::cout <<std::left << std::setw(8)  << "Pos"  
        <<std::left << std::setw(16) << "Name" 
        <<std::left << std::setw(8)  << "Score"
        <<std::left << std::setw(8)  << "Length"
        <<std::left << std::setw(10) << "Date" << std::endl; 

        while(_highscore_file >> ppos)              // Read out the file
        {
            
            _highscore_file >> pname;               // Information is seperated by "space"
            _highscore_file >> pscore;              // each loop reads one line in the highescore file 
            _highscore_file >> psize;               // until end of file is reached. 
            _highscore_file >> pdate;
           
            std::cout <<std::left << std::setw(8)  << ppos  
                      <<std::left << std::setw(16) << pname 
                      <<std::left << std::setw(8)  << pscore
                      <<std::left << std::setw(8)  << psize 
                      <<std::left << std::setw(10) << pdate << std::endl; 
        }
        _highscore_file.close();

        std::cout << "Highscore End - Have Fun ! " << std::endl;
            
        return(1);
    }
    else
    {
        // std::cout <<"Failed to import file"<<std::endl;
        return (0);
    }
}