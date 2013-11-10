#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <string>

#include <Math/vector2.h>

class Sprite
{
    private:
        int m_height, m_width;
        Vector2 m_position;
        double m_rotation;

        bool m_bVisible;
        
        SDL_Renderer *m_pRendTarget;
        SDL_Texture *m_pTexture;

        // Store it in here so that we don't have to create a new
        // one every draw loop
		SDL_Rect m_dstRect;

    public:
        // Constructor with filename and size ( height, width);
        Sprite(SDL_Renderer*);
        ~Sprite();
        
        void loadImage(const std::string& filename);
        // Draw the sprite with the target window
        void draw();
        void dispose();

        bool isVisible() { return m_bVisible; }
        void setVisible(bool visible) { m_bVisible = visible; }
        
        // Set height or width
        void setHeight(int h) { m_height = h;}
        void setWidth(int w) { m_width = w; }
        
        int getHeight() { return m_height; }
        int setWidth() { return m_width; }

        const Vector2& getPosition() { return m_position; }
        float getX() { return m_position.x; }
        float getY() { return m_position.y; }

        void setX(float x) { m_position.x = x; }
        void setY(float y) { m_position.y = y; }
        void setPosition(const Vector2& pos) { m_position = pos; }

        // Rotation
        void setRotation(double rot) { m_rotation = rot; }
        /**
         * Rotate the sprite by using its previous rotation
         */
        void rotate(double rot);
        double getRotation() { return m_rotation; }
};

#endif
