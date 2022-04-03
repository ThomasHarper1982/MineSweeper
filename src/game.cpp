#include "game.h"
#include <iostream>
#include "SDL2/SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t kScreenWidth, std::size_t kScreenHeight,  double proportion_) {
   gameState = std::make_unique< GameState>(static_cast<int>(grid_width), static_cast<int>(grid_height), static_cast<int>(kScreenWidth), static_cast<int>(kScreenHeight), proportion_);
   mapX = static_cast<int>(grid_width);
   mapY = static_cast<int>(grid_height);    
   proportion = proportion_;
  // gameState.get()->init();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  GameState* gameState_ = gameState.get();
  //renderer->initTimerThread();
  //renderer.initTimerThread(gameState_, renderer);
  while (running) {

    if (gameState_->isNewGame()){
       gameState = std::make_unique< GameState>(mapX, mapY, static_cast<int>(gameState_->getWindowX()), static_cast<int>(gameState_->getWindowY()), proportion);
       gameState_ =gameState.get();
    }
    frame_start = SDL_GetTicks();
    //if (renderer->getGameState()==nullptr){
        //renderer.initTimerThread(gameState_, renderer);
       // std::thread t1(renderer.RenderTimeThread);

   // }
  //  
    renderer.Render(gameState_);
    controller.HandleInput(running, gameState_);
    frame_start = SDL_GetTicks();
    renderer.Render(gameState_);
    gameState->playerAction();
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
     renderer.UpdateWindowTitle();
    // After every second, update the window title.
    if (frame_end - title_timestamp >= 10000) {
      renderer.UpdateWindowTitle();
 //     renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

