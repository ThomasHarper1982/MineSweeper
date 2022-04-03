#include "GameState.h"


GameState::GameState(const GameState &source){
    std::cout << "GameState Copy Constructor " <<  std::endl;
}

GameState& GameState::operator=(const GameState &source){
    std::cout << "Copy assignment "<< this << std::endl;
    if (this == &source)
      return *this;
    return *this;
}

GameState::GameState(GameState &&source){
    std::cout << "GameState Move Constructor"<< std::endl;
} // 4 : move constructor
GameState& GameState::operator=(GameState &&source){
    std::cout << "ChatBot Move Assignment Operator" << std::endl;
    if (this == &source)
      return *this;

    return *this;
}

GameState::~GameState(){
}

 GameState::GameState(int mapX_, int mapY_, int windowX_, int windowY_, double mine_proportion_):mapX(mapX_),mapY(mapY_),windowX(windowX_), windowY(windowY_){
    numMines = 0;
    numSafeTiles = 0;
    numSafeTilesExposed = 0;
    map = new Array2D<Tile*>(mapX_, mapY_);
    for (int i=0; i<mapX; i++){
        for (int j=0; j<mapY; j++){
           // Tile* tile  =  new Tile(Tile::TileType::OKAY);
            Tile *tile  =  (mine_proportion_> (rand() % 100)/100.0) ? new Tile(Tile::TileType::MINE,i,j): new Tile(Tile::TileType::OKAY,i,j);
          //  std::shared_ptr<Title> tile = std::make_shared<Title>(tile);
             if (tile->getType() == Tile::TileType::MINE){
                 numMines++;
             }else{
                 numSafeTiles++;
             }

             map->operator()(i,j) = tile; 
        }
    }
    newGame = false;
    sbs = StatusButtonState::NONE1;
    checkAdjacentNeighbours();
    start_time= time_since_epoch();
    gameOver = false;
    win = false;
    pressedTile = nullptr;
}

bool GameState::checkStatusButton(){
  int status_width = windowX * 0.95;
  int status_height = windowY * 0.1;
  int border_thicknessX = windowX  * 0.01;
  int border_thicknessY = windowY  * 0.01;
  int tileX = (status_width-2*border_thicknessX)/(mapX);
  int tileY = (status_height-2*border_thicknessY)/(mapY);

  status_width = tileX*mapX+ 2*border_thicknessX;
  status_height = tileY*mapY + 2*border_thicknessY;
  int status_x = windowX * 0.025;
  int status_y = windowY * 0.025;
  int state_button_height = 0.6*status_height;
  int state_button_width = state_button_height;
  int state_button_posX = status_x + status_width/2- 0.5*state_button_width;
  int state_button_posY = status_y + status_height/2 - 0.5*state_button_height;

  if (x > state_button_posX && y > state_button_posY && x < state_button_posX + state_button_width && y < state_button_posY + state_button_height){
    sbs = StatusButtonState::PRESSED;   
    return true; 
  }
  sbs = StatusButtonState::NONE1; 
  return false;
}
void GameState::playerAction(){
    //get mouse button up or down status
    //get mouse position

    if (getMouseButtonState()==GameState::MouseButtonState::LEFTDOWN){
        
        if (checkStatusButton()){
            return;
        }


        //mouse button Down
        //determine which tile is affected
        Tile * t  = determineTile(x,y);
        if (t==nullptr)
            return;

        //changed tile state to PRESSED
        if (t->getState()==Tile::State::UNREVEALED){
            setTileState(t, Tile::State::PRESSED);
            pressedTile = t;
        }
        mbs = MouseButtonState::NONE;

        //change emoji face to nervous
    }else if (getMouseButtonState()==GameState::MouseButtonState::LEFTUP){
        //mouse button UP
        //determine which tile is affected

        if (checkStatusButton()){
            //create new game
            newGame = true;
            sbs = StatusButtonState::NONE1;
            return;
        }

        Tile* t = determineTile(x,y);
        if (t==nullptr)
            return;
        //change tile state to REVEALED
        if (t==pressedTile && t->getState()!=Tile::State::REVEALED){
            setTileState(t, Tile::State::REVEALED);
            if (t->getType() == Tile::TileType::MINE){
                //game over routine
              //  t->setState(Tile::State::REVEALED);
                t->setTripped();
                setGameOver();
                GameOverRoutine(); //loss
            }else{
                numSafeTilesExposed++;
                exposeSafeNeighbours(t->getI(), t->getJ());
            }
            
        }else{
            if (pressedTile!=nullptr && (pressedTile->getState()==Tile::State::PRESSED || !pressedTile->getState()==Tile::State::REVEALED)){
                pressedTile->setState(Tile::State::UNREVEALED);
               
            }
                
        }
        pressedTile = nullptr;
        mbs = MouseButtonState::NONE;
        //if OKAY apply revealSafeNeighbours algorithm
        //if MINE apply GameOver algorithm and reveal all
    }else if (getMouseButtonState()==GameState::MouseButtonState::RIGHTUP){
        //toggle flag
        Tile* t = determineTile(x,y);
        if (t==nullptr)
            return;
        if (t->getState()==Tile::State::UNREVEALED){
            t->setFlag(!t->getFlag());
            
        }
        
         mbs = MouseButtonState::NONE;
    }
    if (numSafeTilesExposed==numSafeTiles){
        setGameOver();
        GameOverRoutine(); //win
        win =true;
    }
}

void GameState::GameOverRoutine(){
    game_over_time = time_since_epoch();
    //reveal all tiles
        for (int i=0; i<mapX; i++){
            for (int j=0; j<mapY; j++){
           // Tile* tile  =  new Tile(Tile::TileType::OKAY);
        
          //  std::shared_ptr<Title> tile = std::make_shared<Title>(tile);         
             map->operator()(i,j)->setState(Tile::State::REVEALED); 
        }
    }

}


void GameState::setTileState(Tile* t,Tile::State tile_state){
    t->setState(tile_state);
}

Tile* GameState::determineTile(int x, int y){
  int field_width = windowX * 0.95;
  int field_height = windowY * 0.825;
  int field_x = windowX * 0.025;
  int field_y = windowY * 0.15;
  int border_thicknessX = windowX * 0.01;
  int border_thicknessY = windowY * 0.01;
  int tileX = (field_width-2*border_thicknessX)/mapX;
  int tileY = (field_height-2*border_thicknessY)/mapY;
  int offset_x = field_x + border_thicknessX;
  int offset_y = field_y + border_thicknessY;
  field_width = tileX*mapX + 2*border_thicknessX;
  field_height = tileY*mapY + 2*border_thicknessY;
  if (x < offset_x || y < offset_y || x > offset_x+field_width-2*border_thicknessX || y>offset_y+field_height-2*border_thicknessY){
      return nullptr;
  }

  int targetX = (int)((x - offset_x)/tileX);
  int targetY = (int)((y - offset_y)/tileY);
  if (0 <= targetX && targetX <mapX && 0 <= targetY && targetY <mapY){
    Tile* t = map->operator()(targetX,targetY);
    return t;
  }
    return nullptr;
}

void GameState::checkAdjacentNeighbours(){
    for (int i=0; i<mapX; i++){
        for (int j=0; j<mapY; j++){
            Tile* tile = map->operator()(i,j);
            int mine_count = 0;
            if (tile->getType()==Tile::TileType::OKAY){

                for (int k=-1; k<=1; k++){
                    for (int l=-1; l<=1; l++){
                        if ((i+k >= 0 && i+k < mapX) && (j+l >= 0 && j+l< mapY) && !(k==0 && l==0)){
                            Tile* neighbour = map->operator()(i+k,j+l);
                            mine_count += (neighbour->getType()==Tile::TileType::MINE)?1:0; 
                        }
                    }
                }

            }
            tile->setMineCount(mine_count);
        }
    }
}

//precondition: tile i,j is revealed and okay
//method to expose safe neighbours of tile i,j
void GameState::exposeSafeNeighbours(int i, int j){

    int x[8] ={-1,0,0,1,-1,1,1,-1};
    int y[8] ={0,1,-1,0,1,-1,1,-1};

    for (int k = 0; k < 8; k++){
        if ((i+x[k] >= 0 && i+x[k] < mapX) && (j+y[k] >= 0 && j+y[k] < mapY)){
            Tile* neighbour_left = map->operator()(i+x[k],j+y[k]);
            if (neighbour_left->getState() == Tile::State::UNREVEALED){
                if (neighbour_left->getType() == Tile::TileType::OKAY){
                    neighbour_left->setState(Tile::State::REVEALED);
                    numSafeTilesExposed++;
                    if (neighbour_left->getMineCount() == 0){
                        exposeSafeNeighbours(i+x[k], j+y[k]);
                    }
                }
            }
        }
    }
}

time_t GameState::time_since_epoch()
{
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t( now );
}