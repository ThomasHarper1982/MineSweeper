#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL2/SDL.h"
#include "controller.h"
#include "renderer.h"

#include "GameState.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, std::size_t kScreenWidth, std::size_t kScreenHeight, double proportion);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void Test();
  int getMapX(){return mapX;};
  int getMapY(){return mapY;};
  double getProportion(){return proportion;};
 private:
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::unique_ptr<GameState> gameState;
 // int score{0};

  int mapX;
  int mapY;
  double proportion;
//  void PlaceFood();
  void Update();
};

#endif