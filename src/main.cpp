#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"


int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{40};
  constexpr std::size_t kGridHeight{40};
  double proportion = 0.15;

  Renderer renderer =  Renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, kScreenWidth, kScreenHeight,  proportion);
  
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "finish" << std::endl;
  return 0;
}