//
//  Tile.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#ifndef Tile_hpp
#define Tile_hpp

#include "LTexture.hpp"
//The tile
class Tile
{
    public:
    //Tile constants
        static const int TILE_WIDTH = 80;
        static const int TILE_HEIGHT = 80;

        //The dimensions of the level
        static const int LEVEL_WIDTH = 1280;
        static const int LEVEL_HEIGHT = 960;

        //Initializes position and type
        Tile( int x, int y, int tileType);

        //Shows the tile
        void render( SDL_Rect& camera, SDL_Rect gTileClips[] , LTexture& gTileTexture);

        //Get the tile type
        int getType();
    
        bool checkCollision( SDL_Rect a, SDL_Rect b );
    
        //Get the collision box
        SDL_Rect getBox();

    private:
//        LTexture gTileTexture;
        //The attributes of the tile
        SDL_Rect mBox;

        //The tile type
        int mType;


};

#endif /* Tile_hpp */
