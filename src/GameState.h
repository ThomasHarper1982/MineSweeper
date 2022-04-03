#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <iostream>
#include "Array2D.h"
#include <chrono> 
using namespace std::chrono; 


class Tile{
    public:
        enum TileType{MINE, OKAY};
        enum State{PRESSED, REVEALED, UNREVEALED};

      //  ~Tile();
        Tile(){};
        Tile(TileType t, int i_, int j_):type(t),i(i_),j(j_){state = State::UNREVEALED; tripped =false; flag=false;};
     //   Tile(const Tile &source); // 2 : copy constructor
 	//	    Tile &operator=(const Tile &source); // 3 : copy assignment operator
   	  //  Tile(Tile &&source); // 4 : move constructor
     //   Tile &operator=(Tile &&source); 
        TileType getType(){return type;};
        State getState(){return state;};
        void setState(Tile::State state_){state =state_;};
        int getMineCount(){return mine_count;};
        void setMineCount(int mine_count_){mine_count = mine_count_;};
        void setTripped(){tripped = true;};
        bool getTripped(){return tripped;};
        void setFlag(bool flag_){flag = flag_;};
        bool getFlag(){return flag;};

        int getI(){return i;};
        int getJ(){return j;};
    private:
        TileType type;
        bool flag;
        bool tripped;
        State state;
        int mine_count;
        int i;
        int j;

};


class GameState{
    public:
        enum MouseButtonState{LEFTUP, LEFTDOWN, RIGHTDOWN, RIGHTUP, NONE};
        enum StatusButtonState{PRESSED, NONE1};
        ~GameState();
        GameState(const GameState &source); // 2 : copy constructor
        GameState& operator=(const GameState &source); // 3 : copy assignment operator
        GameState(GameState &&source); // 4 : move constructor
        GameState& operator=(GameState &&source); // 5 : move assignment operator
        GameState(int mapX_, int mapY_, int windowX_, int windowY_, double mine_proportion_);
        int getMapX(){return mapX;};
        int getMapY(){return mapY;};
        int getX(){return x;};
        int getY(){return y;};
        int getWindowX(){return windowX;};
        int getWindowY(){return windowY;};
        void setWindowSize(int x, int y){windowX = x; windowY=y;};
        MouseButtonState getMouseButtonState(){return mbs;};
        void refresh(){refresh_ = true;};
        void checkMouseState(int x_, int y_, MouseButtonState mbs_){x =x_;y = y_; mbs=mbs_;};
        void playerAction();
        Tile* determineTile(int x, int y);  
        void checkAdjacentNeighbours();
        void setTileState(Tile* t, Tile::State tile_state);
        void exposeSafeNeighbours(int i, int j);
        void setGameOver(){gameOver = true;};
        void GameOverRoutine();
        bool isGameOver(){return gameOver;};
        bool hasWon(){return win;};
        Array2D<Tile*>* getMap(){return map;};
        void setNewGame(){newGame =true;};
        bool isNewGame(){return newGame;};
        bool checkStatusButton();
        bool isTilePressed(){return pressedTile!=nullptr;};
        time_t time_since_epoch();
        time_t getStartTime(){return start_time;};
        time_t getGameOverTime(){return game_over_time;};
        StatusButtonState getStatusButtonState(){return sbs;};
        int getRemainingTiles(){return numSafeTiles - numSafeTilesExposed;};
    private:
        int x;
        int y;
        MouseButtonState mbs;
        StatusButtonState sbs;
        int windowX;
        int windowY;

        int mapX;
        int mapY;
        bool refresh_;
        Array2D<Tile*>* map;    
        Tile* pressedTile;    
        bool gameOver;
        bool win; //if gameOver
        bool newGame;
        int numSafeTiles;
        int numSafeTilesExposed;
        int numMines;
        time_t start_time;
        time_t game_over_time;

};

#endif