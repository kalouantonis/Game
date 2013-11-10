#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <string>
#include <iostream>

#include <Math/vector2.h>


enum Collision
{
    COLLISION_NONE,
    COLLISION_RECT,
    COLLISION_DIST
};

class Sprite
{
    private:
        int m_height, m_width;
        Vector2 m_position;

        bool m_bVisible, m_bAlive;
        
        SDL_Renderer *m_pRendTarget;
        SDL_Texture *m_pTexture;

    public:
        // Constructor with filename and size ( height, width);
        Sprite(SDL_Renderer*);
        ~Sprite();
        
        void LoadImage(const std::string& filename);
        // Draw the sprite with the target window
        void Draw();
        void Dispose();

        bool isAlive() { return m_bAlive; }
        bool isVisible() { return m_bVisible; }
        
        // Set height or width
        
        void setHeight(int h) { m_height = h;}
        void setWidth(int w) { m_width = w; }
        
        int getHeight() { return m_height; }
        int setWidth() { return m_width; }

        // Set positon
        // example: object.posX() = value
        const Vector2& getPosition() { return m_position; }
        float getX() { return m_position.x; }
        float getY() { return m_position.y; }

        void setX(float x) { m_position.x = x; }
        void setY(float y) { m_position.y = y; }
        void setPosition(const Vector2& pos) { m_position = pos; }
};

#endif
