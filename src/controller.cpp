#include "controller.h"
#include <iostream>
#include "SDL2/SDL.h"


void Controller::HandleInput(bool &running , GameState* gameState)const {
  
  SDL_Event e;

  //std::cout << "handle input : start " << std::endl;

  bool waiting_for_input = true;
  while(waiting_for_input){
      if(SDL_PollEvent(&e)){
          if(e.type == SDL_QUIT){
              waiting_for_input = false;
          }else if (e.type == SDL_WINDOWEVENT){
            if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
              break;
            }
          }else if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym) {
                case SDLK_w:{
                    waiting_for_input = false;
                  break;
                }
                  case SDLK_q:{
                      exit(0);
                      break;
                }

                  }
            }else if(e.type == SDL_MOUSEBUTTONDOWN){

              int x, y;
              if(e.button.button == SDL_BUTTON_LEFT){
            //    std::cout << "Left click down\n";
                SDL_GetMouseState(&x, &y);
                gameState->checkMouseState(x,y,GameState::MouseButtonState::LEFTDOWN);
                //changes the emoji -> nervous
                //changes the tile to pressed
                break;
              }
           
            }else if(e.type == SDL_MOUSEBUTTONUP){

              int x, y;
              if(e.button.button == SDL_BUTTON_LEFT){
            //    std::cout << "Left click up\n";
                SDL_GetMouseState(&x, &y);
                gameState->checkMouseState(x,y,GameState::MouseButtonState::LEFTUP);
                //reveals the tile
                break;
              }else if (e.button.button == SDL_BUTTON_RIGHT){
            //    std::cout << "Left click up\n";
                SDL_GetMouseState(&x, &y);
                gameState->checkMouseState(x,y,GameState::MouseButtonState::RIGHTUP);
                //reveals the tile
                break;
              }
              
            }
              
            
            

        }

      }

  }



void mousePressDown(SDL_MouseButtonEvent& b){
  if(b.button == SDL_BUTTON_LEFT){
    //handle a left-click
  }
}
void mousePressUp(SDL_MouseButtonEvent& b){
  if(b.button == SDL_BUTTON_LEFT){
    //handle a left-click
  }
}