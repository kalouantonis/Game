#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL_image.h>
#include <SDL.h>

#include <string>
#include <iostream>


enum Collision
{
    COLLISION_NONE,
    COLLISION_RECT,
    COLLISION_DIST
};

typedef struct Position
{
    int x;
    int y;
};

class Sprite
{
    private:
        int height, width;
        Position pos;
        std::string filename;
        bool visible, alive;
        
        SDL_Renderer *rendTarget;
        SDL_Texture *texture;

    public:
        // Constructor with filename and size ( height, width);
        Sprite(std::string, int, int, SDL_Renderer*);
        //Sprite(const std::string, const int, const int);
        
        void LoadImage(std::string);
        // Draw the sprite with the target window
        void Draw();
        void Dispose();

        bool isAlive() { return alive; }
        bool isVisible() { return visible; }
        
        // Set height or width
        
        void setH(int h) { height = h;}
        void setW(int w) { width = w; }
        
        int getH() { return height; }
        int setW() { return width; }

        // Set positon
        // example: object.posX() = value
        int &posX() { return pos.x; }
        int &posY() { return pos.y; }
        
};

#endif
