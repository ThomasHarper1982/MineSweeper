#include "renderer.h"
#include <iostream>
#include <string>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("MineSweeper", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_RESIZABLE |SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
 // sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  
    //Initialize SDL_ttf
  if( TTF_Init() == -1 )
  {
      printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
  }
  font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoBold.ttf", 18);

}

Renderer::~Renderer() {
  
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}


void Renderer::Render(GameState* gameState) {
 // std::cout<< "rendering" << std::endl;
  gameState->setWindowSize(SDL_GetWindowSurface(sdl_window)->w, SDL_GetWindowSurface(sdl_window)->h );
  RenderStatePanel(gameState);
  RenderFieldPanel(gameState);
  SDL_RenderPresent(sdl_renderer);
} 


void Renderer::RenderFieldGrid(int offset_x, int offset_y, int mapX, int mapY, int fieldWidth, int fieldHeight, int tileX, int tileY, int line_thickness){
  for (int i = 1; i <= mapX; i++){
        for (int j = 0; j < line_thickness; j++){
          int thickness_offset = (int)line_thickness/2.0;
            int x0 =  offset_x;
            int y0 = offset_y+j-thickness_offset + tileY*i;
            int x1 = fieldWidth+offset_x;
            int y1 = offset_y+j-thickness_offset + tileY*i;

            SDL_RenderDrawLine(sdl_renderer, x0,y0,x1,y1);
            
        }
  }
  for (int i = 1; i <= mapY; i++){
        for (int j = 0; j < line_thickness; j++){
          int thickness_offset = (int)line_thickness/2.0;
            int x0 = offset_x+j-thickness_offset+ tileX*i;
            int y0 = offset_y ;
            int x1 = offset_x+j-thickness_offset+ tileX*i;
            int y1 = fieldHeight+offset_y;
            SDL_RenderDrawLine(sdl_renderer, x0,y0,x1,y1);
      }
  }
}


void Renderer::drawCircle(int x0, int y0, int radius)
{
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        SDL_RenderDrawPoint(sdl_renderer,x0 + x, y0 + y);
        SDL_RenderDrawPoint(sdl_renderer,x0 + y, y0 + x);
        SDL_RenderDrawPoint(sdl_renderer,x0 - y, y0 + x);
        SDL_RenderDrawPoint(sdl_renderer,x0 - x, y0 + y);
        SDL_RenderDrawPoint(sdl_renderer,x0 - x, y0 - y);
        SDL_RenderDrawPoint(sdl_renderer,x0 - y, y0 - x);
        SDL_RenderDrawPoint(sdl_renderer,x0 + y, y0 - x);
        SDL_RenderDrawPoint(sdl_renderer,x0 + x, y0 - y);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}


void Renderer::fillHalfCircle(int x0, int y0, int radius)
{
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        SDL_RenderDrawLine(sdl_renderer,x0 + x, y0 + y,x0, y0 + y);
        SDL_RenderDrawLine(sdl_renderer,x0 + y, y0 + x,x0, y0 + x);
        SDL_RenderDrawLine(sdl_renderer,x0 - y, y0 + x,x0, y0 + x);
        SDL_RenderDrawLine(sdl_renderer,x0 - x, y0 + y,x0, y0 + y);
      //  SDL_RenderDrawLine(sdl_renderer,x0 - x, y0 - y,x0, y0 - y);
      //  SDL_RenderDrawLine(sdl_renderer,x0 - y, y0 - x,x0, y0 - x);
      //  SDL_RenderDrawLine(sdl_renderer,x0 + y, y0 - x,x0, y0 - x);
      //  SDL_RenderDrawLine(sdl_renderer,x0 + x, y0 - y,x0, y0 - y);


        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

void Renderer::fillCircle(int x0, int y0, int radius){
    int x = radius-1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        SDL_RenderDrawLine(sdl_renderer,x0 + x, y0 + y,x0, y0 + y);
        SDL_RenderDrawLine(sdl_renderer,x0 + y, y0 + x,x0, y0 + x);
        SDL_RenderDrawLine(sdl_renderer,x0 - y, y0 + x,x0, y0 + x);
        SDL_RenderDrawLine(sdl_renderer,x0 - x, y0 + y,x0, y0 + y);
        SDL_RenderDrawLine(sdl_renderer,x0 - x, y0 - y,x0, y0 - y);
        SDL_RenderDrawLine(sdl_renderer,x0 - y, y0 - x,x0, y0 - x);
        SDL_RenderDrawLine(sdl_renderer,x0 + y, y0 - x,x0, y0 - x);
        SDL_RenderDrawLine(sdl_renderer,x0 + x, y0 - y,x0, y0 - y);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        
        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

//angles provided in radians

void Renderer::drawArc(int x0, int y0, double start_angle, double end_angle, double radiusX, double radiusY, int thickness)
{

    float pi  = 3.14159265358979323846264338327950288419716939937510;
   // float pih = end_angle; //half of pi


    const int prec =500; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
    float theta = start_angle;     // angle that will be increased each loop

    //starting point
    int x  = (float)radiusX * cos(theta);//start point
    int y  = (float)radiusY * sin(theta);//start point
    int x1 = x;
    int y1 = y;

    for (int i =0; i < thickness; i++){
      //repeat until theta >= 90;
      float step = end_angle/(float)prec; // amount to add to theta each time (degrees)
      for(theta=start_angle;  theta <= end_angle+2*pi/100;  theta+=step)//step through only a 90 arc (1 quadrant)
      {
          //get new point location
          x1 = (float)radiusX * cosf(theta);// + 0.5; //new point (+.5 is a quick rounding method)
          y1 = (float)radiusY * sinf(theta)+i;// + 0.5; //new point (+.5 is a quick rounding method)
          SDL_RenderDrawPoint(sdl_renderer,x0+x1, y0+y1);
      }
    }


}

void Renderer::RenderEmoji(GameState* gameState, int x, int y, int width, int height){


    Colour yellow = Colour(0xFF, 0xFF,0x00,0xFF);
    SDL_SetRenderDrawColor(sdl_renderer, yellow.R(), yellow.G(), yellow.B(), yellow.A());  
    fillCircle(x+0.5*width, y+0.5*height, width*0.35);
  //  drawElipse(x+0.5*width, y+10*height, width*5, height*5);
    Colour black = Colour(0x00, 0x00,0x00,0xFF);
    SDL_SetRenderDrawColor(sdl_renderer, black.R(), black.G(), black.B(), black.A());  
    //four states
    if (gameState->isGameOver()){
      if (gameState->hasWon()){
        //cool face
        fillHalfCircle(x+0.40*width, y+0.35*height, width*0.12);
        fillHalfCircle(x+0.60*width, y+0.35*height, width*0.12);
        drawArc(x+0.5*width, y+0.4*height, 3.14/4.0, 3.14*3.0/4.0, width*0.25, height*0.25, 3);

      }else{
        //sad face
        drawElipse(x+0.40*width, y+0.4*height, width*0.05, height*0.05);
        drawElipse(x+0.60*width, y+0.4*height, width*0.05, height*0.05);
        drawArc(x+0.5*width, y+0.8*height, 3.14*5/4, 3.14*7/4, width*0.25, height*0.25, 3);
      }

    }else{

      if (gameState->isTilePressed()){
        drawElipse(x+0.40*width, y+0.4*height, width*0.05, height*0.05);
        drawElipse(x+0.60*width, y+0.4*height, width*0.05, height*0.05);

        SDL_Rect mouth;
        mouth.x = x+0.35*width;
        mouth.y = y+0.6*height;
        mouth.w = width*0.3;
        mouth.h = 0.1*height;
        SDL_RenderFillRect(sdl_renderer, &mouth);
        //nervous face
      }else{
        //happy face - eyes
        drawElipse(x+0.40*width, y+0.4*height, width*0.05, height*0.05);
        drawElipse(x+0.60*width, y+0.4*height, width*0.05, height*0.05);
        drawArc(x+0.5*width, y+0.4*height, 3.14/4.0, 3.14*3.0/4.0, width*0.25, height*0.25, 3);

      }

    }


}

void Renderer::RenderScore(GameState* gameState, int score_x, int score_y, int score_width, int score_height){
   Colour c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour c1 = Colour(0x72, 0x72,0x72,0xFF);

   Colour c3 = Colour(0x00, 0x00,0x00,0xFF);

   int tiles = gameState->getRemainingTiles();
  

   RenderPanel(score_x, score_y, score_width, score_height, 0.025*score_width, 0.025*score_height, c1, c2, c3);
   //first digit
   RenderDigitalDisplay(score_x+0.025*score_width, score_y+0.025*score_height, 0.95*score_width/4.0, 0.95*score_height, nthDigit(tiles, 4, 10));
   RenderDigitalDisplay(score_x+0.2625*score_width, score_y+0.025*score_height, 0.95*score_width/4.0, 0.95*score_height, nthDigit(tiles, 3, 10));
   RenderDigitalDisplay(score_x+0.5*score_width, score_y+0.025*score_height, 0.95*score_width/4.0, 0.95*score_height, nthDigit(tiles, 2, 10));
   RenderDigitalDisplay(score_x+0.7375*score_width, score_y+0.025*score_height, 0.95*score_width/4.0, 0.95*score_height, nthDigit(tiles, 1, 10));
}

void Renderer::RenderTimer(GameState* gameState, int timer_x, int timer_y, int timer_width, int timer_height){

  //render panel with c3 black 

  //
   Colour c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour c1 = Colour(0x72, 0x72,0x72,0xFF);

   Colour c3 = Colour(0x00, 0x00,0x00,0xFF);
   
   time_t t0 = gameState->getStartTime();
   time_t t1 = gameState->time_since_epoch();
   int seconds = std::min((int)(t1-t0),9999);
   if (gameState->isGameOver()){
     seconds = std::min((int)(gameState->getGameOverTime()-t0),9999);
   }

   RenderPanel(timer_x, timer_y, timer_width, timer_height, 0.025*timer_width, 0.025*timer_height, c1, c2, c3);
   //first digit
   RenderDigitalDisplay(timer_x+0.025*timer_width, timer_y+0.025*timer_height, 0.95*timer_width/4.0, 0.95*timer_height, nthDigit(seconds, 4, 10));
   RenderDigitalDisplay(timer_x+0.2625*timer_width, timer_y+0.025*timer_height, 0.95*timer_width/4.0, 0.95*timer_height, nthDigit(seconds, 3, 10));
   RenderDigitalDisplay(timer_x+0.5*timer_width, timer_y+0.025*timer_height, 0.95*timer_width/4.0, 0.95*timer_height, nthDigit(seconds, 2, 10));
   RenderDigitalDisplay(timer_x+0.7375*timer_width, timer_y+0.025*timer_height, 0.95*timer_width/4.0, 0.95*timer_height, nthDigit(seconds, 1, 10));
}

int Renderer::nthDigit(int a, int n, int b)
{
 
    // Skip N-1 Digits in Base B
    for (int i = 1; i < n; i++)
        a = a / b;
 
    // Nth Digit from right in Base B
    return a % b;
}

void Renderer::RenderDigitalDisplay(int posX, int posY, int width, int height, int digit){

  switch(digit){
    case(0):{
      RenderDigit(posX, posY, width, height, "1110111");
      break;
    }
    case(1):{
      RenderDigit(posX, posY, width, height, "0010010");
      break;
    }
    case(2):{
      RenderDigit(posX, posY, width, height, "1101011");
      break;
    }
    case(3):{
      RenderDigit(posX, posY, width, height, "1011011");
      break;
    }
    case(4):{
      RenderDigit(posX, posY, width, height, "0011110");
      break;
    }
    case(5):{
      RenderDigit(posX, posY, width, height, "1011101");
      break;
    }
    case(6):{
      RenderDigit(posX, posY, width, height, "1111101");
      break;
    }
    case(7):{
      RenderDigit(posX, posY, width, height, "0010011");
      break;
    }
    case(8):{
      RenderDigit(posX, posY, width, height, "1111111");
      break;
    }
    case(9):{
      RenderDigit(posX, posY, width, height, "1011111");
      break;
    }
  }
}



void Renderer::RenderDigit(int posX, int posY, int width, int height, std::string mask){
    Colour red = Colour(0xFF, 0x00,0x00,0xFF);
    Colour darkRed = Colour(0x7C, 0x00,0x00,0xFF);
    SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());  

    if (mask.at(0)=='1'){ //bot
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
     // 
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderHorizontalSegment(posX+0.15*width, posY+0.90*height, 0.7*width, 0.10*height);
    if (mask.at(1)=='1'){ //bot left
          SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
    }else{
          SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
     RenderVerticalSegment(posX+0.05*width, posY+0.55*height, 0.15*width, 0.40*height);
    if (mask.at(2)=='1'){//bot right
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderVerticalSegment(posX+ 0.75*width, posY+0.55*height, 0.15*width, 0.40*height);
    if (mask.at(3)=='1'){//mid
//RenderHorizontalSegment(posX, posY, width, height);
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderHorizontalSegment(posX+0.1*width, posY+0.475*height, 0.75*width, 0.10*height);
    if (mask.at(4)=='1'){//top left
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());  
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderVerticalSegment(posX+0.05*width, posY+0.10*height, 0.15*width, 0.40*height);
    if (mask.at(5)=='1'){//top right
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderVerticalSegment(posX+ 0.75*width, posY+0.10*height, 0.15*width, 0.40*height);
    if (mask.at(6)=='1'){ //top
//RenderHorizontalSegment(posX, posY, width, height);
      SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());
    }else{
      SDL_SetRenderDrawColor(sdl_renderer, darkRed.R(), darkRed.G(), darkRed.B(), darkRed.A());
    }
    RenderHorizontalSegment(posX+0.1*width, posY , 0.75*width, 0.10*height);
}

void Renderer::RenderHorizontalSegment(int posx, int posy, int width, int height){
  //1 rect
  //4 triangle
    SDL_Rect base;


    int x0 =round(posx+0.15*width);
    int y0 = round(posy+0.5*height);
    int y1 = round(posy+0.05*height);
    int y2 =round(posy+0.95*height);
    int x1 =round(posx+0.85*width);
    base.x = x0;
    base.y = y1;
    base.w = round(width*0.70);
    base.h = round(0.9*height);
    SDL_RenderFillRect(sdl_renderer, &base);
    RenderTriangle(x0, x0, posx, y0, y1, y0);
    RenderTriangle(x0, x0, posx, y0, y2, y0);
    RenderTriangle(x1, x1, posx + width, y0, y1, y0);
    RenderTriangle(x1, x1, posx + width, y0, y2, y0);
}

void Renderer::RenderVerticalSegment(int posx, int posy, int width, int height){
  //1 rect
  //6 triangle
    SDL_Rect base;

    int x0 = round(posx+0.5*width);
    int y0 = round(posy+0.15*height);
    int x1 = round(posx+0.05*width);
    int x2 =round(posx+0.95*width);
    int y1 =round(posy+0.85*height);

    base.w = round(0.9*width);
    base.h = round(0.7*height);
    base.x = x1;
    base.y = y0;


    SDL_RenderFillRect(sdl_renderer, &base);
    RenderTriangle(x0, x1, x0, y0, y0, posy);
    RenderTriangle(x0, x2, x0, y0, y0, posy);
    RenderTriangle(x0, x1, x0, y1, y1, posy + height);
    RenderTriangle(x0, x2, x0,y1, y1, posy + height);
}

void Renderer::RenderFieldPanel(GameState* gameState){
  int field_width = SDL_GetWindowSurface(sdl_window)->w * 0.95;
  int field_height = SDL_GetWindowSurface(sdl_window)->h  * 0.825;
  int field_x = SDL_GetWindowSurface(sdl_window)->w  * 0.025;
  int field_y = SDL_GetWindowSurface(sdl_window)->h  * 0.15;
  int border_thicknessX = SDL_GetWindowSurface(sdl_window)->w  * 0.01;
  int border_thicknessY = SDL_GetWindowSurface(sdl_window)->h  * 0.01;
  int offset_x = field_x+ border_thicknessX;
  int offset_y = field_y + border_thicknessY;
  int tileX = (field_width-2*border_thicknessX)/(gameState->getMapX());
  int tileY = (field_height-2*border_thicknessY)/(gameState->getMapY());
  field_width = tileX*gameState->getMapX() + 2*border_thicknessX;
  field_height = tileY*gameState->getMapY() + 2*border_thicknessY;

  Array2D<Tile*>* map = gameState->getMap();
   Colour field_c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour field_c1 = Colour(0x72, 0x72,0x72,0xFF);

   Colour field_c3 = Colour(0xB8, 0xB8,0xB8,0xFF);

  //field
  RenderPanel(field_x, field_y, field_width, field_height, border_thicknessX,border_thicknessY, field_c1, field_c2, field_c3);
  //TODO DrawFieldGrid

   SDL_SetRenderDrawColor(sdl_renderer, field_c1.R(), field_c1.G(), field_c1.B(), field_c1.A());
   RenderFieldGrid(offset_x,  offset_y,  gameState->getMapX(),  gameState->getMapY(),  tileX*gameState->getMapX() ,  tileY*gameState->getMapY(),  tileX,  tileY,  4);

  
  for (int i = 0; i < gameState->getMapX(); i++){
    for(int j = 0; j < gameState->getMapY(); j++){
      Tile* t = map->operator()(i,j);
      int posX =  tileX*i+offset_x;
      int posY =  tileY*j+offset_y;
      if (t->getState() == Tile::State::UNREVEALED){
        Colour c3 = Colour(0xB6, 0xB6,0xB6,0xFF);

        //draw flag
        if (t->getFlag()){
          drawUnrevealedTile(tileX, tileY, posX, posY, c3);
          RenderFlag(posX+tileX*0.1, posY+tileY*0.1,  tileX-2*tileX*0.1, tileY-2*tileY*0.1);
        }else{
          drawUnrevealedTile(tileX, tileY, posX, posY, c3);
        }

      }else if (t->getState() == Tile::State::PRESSED){
        // std::cout << "draw pressed tile\n";
         drawPressedTile(tileX, tileY, posX, posY);
      }else if (t->getState() == Tile::State::REVEALED){
        //render no tile
       // std::cout << "draw no tile\n";
       if (t->getType() == Tile::TileType::MINE){
         if (t->getTripped()){
           //draw red tile
            Colour c = Colour(0xFF, 0x00,0x00,0xFF);
            
            SDL_SetRenderDrawColor(sdl_renderer, c.R(), c.G(), c.B(), c.A());
            // top edge
            SDL_Rect red_square;
            red_square.w = (int)tileX;
            red_square.h = (int)tileY;
            red_square.x = (int)posX;
            red_square.y = (int)posY;
            SDL_RenderFillRect(sdl_renderer, &red_square);
         }
         drawMine(posX, posY, tileX, tileY);
       }
       if (t->getMineCount() >0){
         drawMineCount(posX, posY, tileX, tileY, t->getMineCount());
       }
      }
    }
  }

}

void Renderer::drawMineCount(int posX, int posY, int tileX, int tileY, int mineCount){

  if (!font)
     std::cout << "Couldn't find/init Sans ttf font." << TTF_GetError()<< std::endl;

  SDL_Color colour;
  switch(mineCount){
    case(1):{
      colour = {53, 59, 189};
      break;
    }

    case(2):{
      colour = {57, 119, 63};
      break;
    }

    case(3):{
      colour = {209, 92, 78};
      break;
    }

    case(4):{
      colour = {255, 255, 0};
      break;
    }

    case(5):{
      colour = {255, 0, 255};
      break;    }

    case(6):{
      colour = {0, 255, 255};
      break;
    }

    case(7):{
      colour = {255, 255, 255};
      break;
    }
  }

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  std::string s = std::to_string(mineCount);
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, s.c_str(), colour); 

  // now you can convert it into a texture
  SDL_Texture* Message = SDL_CreateTextureFromSurface(sdl_renderer, surfaceMessage);
  //Colour field_c3 = Colour(0xB8, 0xB8,0xB8,0xFF);
 // SDL_SetRenderDrawColor(sdl_renderer, field_c3.R(), field_c3.G(), field_c3.B(), field_c3.A());
  SDL_Rect Message_rect; //create a rectq
  Message_rect.x = posX + tileX*0.3;  //controls the rect's x coordinate 
  Message_rect.y = posY+ tileY*0.1; // controls the rect's y coordinte
  Message_rect.w = tileX*0.6; // controls the width of the rect
  Message_rect.h = tileY*0.8; // controls the height of the rect

  //SDL_RenderFillRect(sdl_renderer, &Message_rect);
  // (0,0) is on the top left of the window/screen,
  // think a rect as the text's box,
  // that way it would be very simple to understand

  // Now since it's a texture, you have to put RenderCopy
  // in your game loop area, the area where the whole code executes

  // you put the renderer's name first, the Message,
  // the crop size (you can ignore this if you don't want
  // to dabble with cropping), and the rect which is the size
  // and coordinate of your texture
  int success =SDL_RenderCopy(sdl_renderer, Message, NULL, &Message_rect);

  // Don't forget to free your surface and texture
  SDL_FreeSurface(surfaceMessage);
  SDL_DestroyTexture(Message);
}

void Renderer::drawMine(int posX, int posY, int width, int height){
  Colour c1 = Colour(0x00, 0x00,0x00,0xFF);
  SDL_SetRenderDrawColor(sdl_renderer, c1.R(), c1.G(), c1.B(), c1.A());
  drawElipse(posX+0.5*width, posY+0.5*height, width*0.25, height*0.25);
  Colour c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

  //draw line
  //SDL_RenderDrawLine(sdl_renderer, posX+0.5*width, posY+0.23*height, posX+0.5*width, posY+0.78*height);
  drawElipse(posX+0.5*width, posY+0.23*height, width*0.05, height*0.05);
  drawElipse(posX+0.5*width, posY+0.77*height, width*0.05, height*0.05);
  drawElipse(posX+0.23*width, posY+0.5*height, width*0.05, height*0.05);
  drawElipse(posX+0.77*width, posY+0.5*height, width*0.05, height*0.05);
  drawElipse(posX+0.30*width, posY+0.30*height, width*0.05, height*0.05);
  drawElipse(posX+0.71*width, posY+0.71*height, width*0.05, height*0.05);
  drawElipse(posX+0.30*width, posY+0.71*height, width*0.05, height*0.05);
  drawElipse(posX+0.71*width, posY+0.30*height, width*0.05, height*0.05);


  SDL_SetRenderDrawColor(sdl_renderer, c2.R(), c2.G(), c2.B(), c2.A());
  drawElipse(posX+0.45*width, posY+0.45*height, width*0.075, height*0.075);
 // drawElipse( int x0, int y0, int radiusX, int radiusY);
}

void Renderer::drawElipse( int x0, int y0, int radiusX, int radiusY)
{
    float pi  = 3.14159265358979323846264338327950288419716939937510;
    float pih = pi / 2.0; //half of pi

    //drew  28 lines with   4x4  circle with precision of 150 0ms
    //drew 132 lines with  25x14 circle with precision of 150 0ms
    //drew 152 lines with 100x50 circle with precision of 150 3ms
    const int prec = 27; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
    float theta = 0;     // angle that will be increased each loop

    //starting point
    int x  = (float)radiusX * cos(theta);//start point
    int y  = (float)radiusY * sin(theta);//start point
    int x1 = x;
    int y1 = y;

    //repeat until theta >= 90;
    float step = pih/(float)prec; // amount to add to theta each time (degrees)
    for(theta=step;  theta <= pih;  theta+=step)//step through only a 90 arc (1 quadrant)
    {
        //get new point location
        x1 = (float)radiusX * cosf(theta);// + 0.5; //new point (+.5 is a quick rounding method)
        y1 = (float)radiusY * sinf(theta);// + 0.5; //new point (+.5 is a quick rounding method)

        //draw line from previous point to new point, ONLY if point incremented
        if( (x != x1) || (y != y1) )//only draw if coordinate changed
        {
            SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 - y,    x0, y0 - y1 );//quadrant TR
            SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 - y,    x0 , y0 - y1 );//quadrant TL
            SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 + y,    x0, y0 + y1 );//quadrant BL
            SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 + y,    x0, y0 + y1 );//quadrant BR

            SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 - y,    x0+x, y0 );//quadrant TR
            SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 - y,    x0-x, y0 );//quadrant TL
            SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 + y,    x0-x, y0);//quadrant BL
            SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 + y,    x0+x, y0);//quadrant BR
        }
        //save previous points
        x = x1;//save new previous point
        y = y1;//save new previous point
    }
    //arc did not finish because of rounding, so finish the arc
    if(x!=0)
    {
        x=0;
        SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
        SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
        SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
        SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR

        SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 - y,    x0+x, y0 );//quadrant TR
        SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 - y,    x0-x, y0 );//quadrant TL
        SDL_RenderDrawLine(sdl_renderer, x0 - x, y0 + y,    x0-x, y0);//quadrant BL
        SDL_RenderDrawLine(sdl_renderer, x0 + x, y0 + y,    x0+x, y0);//quadrant BR
    }
}

void Renderer::drawPressedTile(int tileX, int tileY, int posX, int posY){

   int border_thicknessX = tileX  * 0.1;
   int border_thicknessY = tileY  * 0.1;

   Colour c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour c1 = Colour(0x72, 0x72,0x72,0xFF);

   Colour c3 = Colour(0xB6, 0xB6,0xB6,0xFF);

   RenderPanel(posX, posY, tileX, tileY, border_thicknessX, border_thicknessY, c1, c2, c3);
}

void Renderer::drawUnrevealedTile(int tileX, int tileY, int posX, int posY, Colour tile_colour){

   int border_thicknessX = tileX  * 0.1;
   int border_thicknessY = tileY  * 0.1;

   Colour c1 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour c2 = Colour(0x72, 0x72,0x72,0xFF);

   Colour c3 = Colour(0xB6, 0xB6,0xB6,0xFF);

   RenderPanel(posX, posY, tileX, tileY, border_thicknessX,border_thicknessY,  c1, c2, c3);
}

void Renderer::RenderStatePanel(GameState* gameState){

   int status_width = SDL_GetWindowSurface(sdl_window)->w  * 0.95;
   int status_height = SDL_GetWindowSurface(sdl_window)->h * 0.1;
   int border_thicknessX = SDL_GetWindowSurface(sdl_window)->w  * 0.01;
   int border_thicknessY = SDL_GetWindowSurface(sdl_window)->h  * 0.01;
   int tileX = (status_width-2*border_thicknessX)/(gameState->getMapX());
   int tileY = (status_height-2*border_thicknessY)/(gameState->getMapY());
   status_width = tileX*gameState->getMapX() + 2*border_thicknessX;
   status_height = tileY*gameState->getMapY() + 2*border_thicknessY;


   int status_x = SDL_GetWindowSurface(sdl_window)->w  * 0.025;
   int status_y = SDL_GetWindowSurface(sdl_window)->h  * 0.025;
   Colour c2 = Colour(0xFF, 0xFF,0xFF,0xFF);

   Colour c1 = Colour(0x72, 0x72,0x72,0xFF);

   Colour c3 = Colour(0xB6, 0xB6,0xB6,0xFF);
   

  RenderPanel(status_x, status_y, status_width, status_height, border_thicknessX, border_thicknessY, c1, c2, c3);
  RenderTimer(gameState, status_x + status_width*0.05, status_y + status_height*0.05+border_thicknessY, status_width*0.10, status_height*0.7);
  RenderScore(gameState, status_x + status_width*0.75, status_y + status_height*0.05+border_thicknessY, status_width*0.10, status_height*0.7);

   //render state button
  int state_button_height = 0.6*status_height;
  int state_button_width = state_button_height;
  int state_button_posX = status_x + status_width/2- 0.5*state_button_width;
  int state_button_posY = status_y + status_height/2 - 0.5*state_button_height;

   if (gameState->getStatusButtonState()== GameState::StatusButtonState::PRESSED){
      RenderPanel(state_button_posX, state_button_posY, state_button_width, state_button_height, state_button_width*0.1, state_button_height*0.1, c1, c2, c3);
   }else{
      RenderPanel(state_button_posX, state_button_posY, state_button_width, state_button_height, state_button_width*0.1, state_button_height*0.1, c2, c1, c3);
   }
   RenderEmoji(gameState, state_button_posX, state_button_posY, state_button_width, state_button_height);
   
}

void Renderer::RenderFlag(int posx, int posy, int width, int height){
    Colour black = Colour(0x00, 0x00,0x00,0xFF);

    Colour red = Colour(0xFF, 0x00,0x00,0xFF);
    SDL_SetRenderDrawColor(sdl_renderer, black.R(), black.G(), black.B(), black.A());
    // top edge
    SDL_Rect base;
    base.w = width;
    base.h = 0.1*height;
    base.x = posx;
    base.y = posy+0.9*height;
    SDL_RenderFillRect(sdl_renderer, &base);

    SDL_Rect base2;
    base2.w = width*0.5;
    base2.h = 0.1*height;
    base2.x = posx+0.2*width;
    base2.y = posy+0.8*height;
    SDL_RenderFillRect(sdl_renderer, &base2);

    SDL_Rect pole;
    pole.w = width*0.1;
    pole.h = 0.3*height;
    pole.x = posx+0.45*width;
    pole.y = posy+0.5*height;
    SDL_RenderFillRect(sdl_renderer, &pole);

    SDL_SetRenderDrawColor(sdl_renderer, red.R(), red.G(), red.B(), red.A());

    RenderTriangle(posx, posx+0.55*width, posx+0.55*width, posy+0.25*height, posy+0.25*height, posy +0.5*height);
    RenderTriangle(posx, posx+0.55*width, posx+0.55*width, posy+0.25*height, posy+0.25*height, posy);
}

//origin
//width
//height
//border thickness

void Renderer::RenderTriangle(int x1, int x2, int x3, int y1, int y2, int y3){

    bool two_x_low = false;
    bool two_y_low = false;
    if (x1==x2 && x2>x3 || x1==x3 && x3>x2 || x2==x3 && x3>x1){
      two_x_low =false;
    } else if(x1==x2 && x2<x3 || x1==x3 && x3<x2 || x2==x3 && x3<x1){
      two_x_low =true;
    }else{
      //std::cout<<"Not a right angle triangle";
      return;
    }
    
    if (y1==y2 && y2>y3 || y1==y3 && y3>y2 || y2==y3 && y3>y1){
        two_y_low =false;
    } else if(y1==y2 && y2<y3 || y1==y3 && y3<y2 || y2==y3 && y3<y1){
        two_y_low =true;
    }else{
     // std::cout<<"Not a right angle triangle";
      return;
    }

  int x1_;
  int y1_ ;
  int x2_ ;
  int y2_;
  int x3_ ;
  int y3_; 
    //triangle 1
      if (two_x_low && two_y_low){
         x1_ = std::min(x1,std::min(x2,x3));
         y1_ = std::min(y1,std::min(y2,y3));

         x2_ = x1_;
         y2_ = std::max(y1, std::max(y2,y3));

         x3_ = std::max(x1,std::max(x2,x3));
         y3_ = y1_;

        double m = (y3_ - y2_+0.0)/(x3_ - x2_+0.0);

        int xi = x1_;
        while (xi < x3_){
          int yi = y1_;
          double yj = y2_ + m*(xi-x1_);
          while (yi < yj){
            SDL_RenderDrawPoint(sdl_renderer, xi, yi);
            yi++;
          }
        xi++;
        }
      }

    //triangle 2 TODO -- test and check
      if (!two_x_low && two_y_low){
         x1_ = std::max(x1,std::max(x2,x3));
         y1_ = std::min(y1,std::min(y2,y3));  

         x2_ = x1_;
         y2_ = std::max(y1,std::max(y2,y3));

         x3_ = std::min(x1,std::min(x2,x3));
         y3_ = y1_;

        double m = (y3_ - y2_+0.0)/(x3_ - x2_+0.0);
        int xi = x1_;
        while (xi > x3_){
          int yi = y1_;
          double yj = y2_ + m*(xi-x1_);
          while (yi < yj){
            SDL_RenderDrawPoint(sdl_renderer, xi, yi);
            yi++;
          }
        xi--;
        }
      }
    //tirangle 3
      if (two_x_low && !two_y_low){
         x1_ = std::min(x1,std::min(x2,x3));
         y1_ = std::max(y1,std::max(y2,y3));  

         x2_ = x1_;
         y2_ = std::min(y1,std::min(y2,y3));

         x3_ = std::max(x1,std::max(x2,x3));
         y3_ = y1_;
        double m = (y3_ - y2_ +0.0)/(x3_ - x2_ +0.0);
        int xi = x1_;
        while (xi < x3_){
          int yi = y1_;
          double yj = y2_ + m*(xi-x1_);
          while (yi > yj){
            SDL_RenderDrawPoint(sdl_renderer, xi, yi);
            yi--;
          }
        xi++;
        }
      }
    //triangle 4 TODO -- test and check
      if (!two_x_low && !two_y_low){
        x1_ = std::max(x1,std::max(x2,x3));
        y1_ = std::max(y1,std::max(y2,y3)); 

        x2_ = x1_;
        y2_ = std::min(y1,std::min(y2,y3));

        x3_ = std::min(x1,std::min(x2,x3));
        y3_ = y1_;
        double m = (y3_ - y2_+0.0)/(x3_ - x2_+0.0);
        int xi = x1_;
        while (xi > x3_){
          int yi = y1_;
          double yj = y2_ + m*(xi-x1_);
          while (yi > yj){
            SDL_RenderDrawPoint(sdl_renderer, xi, yi);
            yi--;
          }
        xi--;
        }
      }
}



void Renderer::RenderPanel(int x, int y, int width, int height, int border_thicknessX, int border_thicknessY, Colour c1, Colour c2, Colour c3){
   
  //colour 1
  SDL_SetRenderDrawColor(sdl_renderer, c1.R(), c1.G(), c1.B(), c1.A());
  // top edge
   SDL_Rect top_edge;
   top_edge.w = (int)width -border_thicknessX;
   top_edge.h = (int)border_thicknessY;
   top_edge.x = (int)x;
   top_edge.y = (int)y;


  SDL_RenderFillRect(sdl_renderer, &top_edge);
  // triangle_tr
  RenderTriangle(x + width -border_thicknessX, x + width - border_thicknessX, x + width, y, y +border_thicknessY, y);
  // left edge
   SDL_Rect left_edge;
   left_edge.w = (int)border_thicknessX;
   left_edge.h = (int)height -2*border_thicknessY;
   left_edge.x = (int)x;
   left_edge.y = (int)y + border_thicknessY;
  SDL_RenderFillRect(sdl_renderer, &left_edge);
  // triangle_lb
  RenderTriangle(x, x, x+border_thicknessX, y + height-border_thicknessY, y + height, y+ height-border_thicknessY);
  //colour 2
  SDL_SetRenderDrawColor(sdl_renderer, c2.R(), c2.G(), c2.B(), c2.A());
  // right edge

  SDL_Rect right_edge;
   right_edge.w = (int)border_thicknessX;
   right_edge.h = (int)height -2*border_thicknessY;
   right_edge.x = (int)x+width-border_thicknessX;
   right_edge.y = (int)y + border_thicknessY;
   SDL_RenderFillRect(sdl_renderer, &right_edge);
  // triangle_rt 
  RenderTriangle(x + width-1, x + width - border_thicknessX-1, x + width-1, y+border_thicknessY, y+border_thicknessY, y);
  // bottom edge
   SDL_Rect bot_edge;
   bot_edge.w = (int)width - border_thicknessX;
   bot_edge.h = (int)border_thicknessY;
   bot_edge.x = (int)x+ border_thicknessX;;
   bot_edge.y = (int)y+height-border_thicknessY;

  SDL_RenderFillRect(sdl_renderer, &bot_edge);
  // triangle_bl
  RenderTriangle(x+ border_thicknessX, x + border_thicknessX, x, y+height-1, y + height-border_thicknessY-1, y + height-1);

  //colour 3
  SDL_SetRenderDrawColor(sdl_renderer, c3.R(), c3.G(), c3.B(), c3.A());
  //middle rect
  SDL_Rect middle_box;
   middle_box.w = (int)width -2*border_thicknessX;
   middle_box.h = (int)height - 2*border_thicknessY;
   middle_box.x = (int)x+border_thicknessX;
   middle_box.y = (int)y+border_thicknessY;
  SDL_RenderFillRect(sdl_renderer, &middle_box);

  }


void Renderer::FillQuad(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, Colour c){
    
}

void Renderer::UpdateWindowTitle() {

  
  SDL_SetWindowTitle(sdl_window, "MineSweeper");
}
