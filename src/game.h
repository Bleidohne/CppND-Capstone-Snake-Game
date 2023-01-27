#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;                                 // Standard food used to increase snake by 1
  SDL_Point bad_food;                             // Food to quit game immediately 
  // SDL_Point speed_food;                           // Food to speed up snake
  // SDL_Point slow_food;                            // Food to slow down snake
  // SDL_Point inc_food;                             // Food to increase snake by 2
  // SDL_Point dec_food;                             // Food to decrease snake by 2

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif