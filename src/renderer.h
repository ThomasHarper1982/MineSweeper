#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "GameState.h"
#include "Array2D.h"
#include <math.h> 
#include <thread>

class Colour {
  public:
    Colour(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_):r(r_),g(g_),b(b_),a(a_){};
    Uint8 R(){return r;};
    Uint8 G(){return g;};
    Uint8 B(){return b;};
    Uint8 A(){return a;};
  private:
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(GameState* gameState);
  //void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle();
  void RenderStatePanel(GameState* gameState);
  void RenderFieldPanel(GameState* gameState);  
  void RenderFieldGrid(int offset_x, int offset_y, int mapX, int mapY, int fieldX, int fieldY, int tileX, int tileY, int line_thickness);
  void FillQuad(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, Colour c);
  void RenderPanel(int x, int y, int width, int height, int border_thickness, int border_thicknessY, Colour c1, Colour c2, Colour c3);

  void RenderHorizontalSegment(int posX, int posY, int width, int height);
  void RenderVerticalSegment(int posX, int posY, int width, int height);  
 // void RenderTile(int x, int y, int width, int height, int border_thickness, Colour c1, Colour c2, Colour c3);
  void RenderTriangle(int x1, int x2, int x3, int y1, int y2, int y3);
  void drawUnrevealedTile(int tileX, int tileY, int posX, int posY, Colour tile_colour);
  void drawPressedTile(int tileX, int tileY, int posX, int posY);
  void drawMine(int posX, int posY, int width, int height);
  void drawElipse( int x0, int y0, int radiusX, int radiusY);
  void drawMineCount(int posX, int posY, int tileX, int tileY, int mineCount);
  void RenderFlag(int posx, int posy, int width, int height);
  void RenderTimer(GameState* gameState, int timer_x, int timer_y, int timer_width, int timer_height);
  void RenderScore(GameState* gameState, int timer_x, int timer_y, int timer_width, int timer_height);//getRemainingTiles()
  void RenderEmoji(GameState* gameState, int x, int y, int width, int height);
  void RenderDigit(int posX, int posY, int width, int height, std::string mask);
  void RenderDigitalDisplay(int posX, int posY, int width, int height, int digit);
  int nthDigit(int a, int n, int b);
  void drawArc(int x0, int y0, double start_angle, double end_angle, double radiusX, double radiusY, int thickness);
  void drawCircle(int x0, int y0, int radius);
  void fillHalfCircle(int x0, int y0, int radius);
  void fillCircle(int x0, int y0, int radius);
 // void setGameState(GameState* gameState_){gameState = gameState_;};
 // GameState* getGameState(){return gameState;};
  void RenderTimeThread();
  void initTimerThread(GameState* gameState, Renderer* renderer);
  SDL_Window* getSDLWindow(){return sdl_window;};

 private:
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;
  TTF_Font* font;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  //GameState* gameState;
  
};


#endif