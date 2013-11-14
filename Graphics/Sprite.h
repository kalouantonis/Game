#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <string>

#include <Math/vector2.h>
#include <Graphics/Color.h>

class Sprite
{
    private:
        int m_height, m_width;
        Vector2 m_position;
        double m_rotation;
        
		Color m_color;

        SDL_Renderer *m_pRendTarget;
        SDL_Texture *m_pTexture;

        // Store it in here so that we don't have to create a new
        // one every draw loop
		SDL_Rect m_dstRect;


    public:
        Sprite(SDL_Renderer*);
        ~Sprite() {}
        
        /**
         * Note: Sprite will not unload texture after loading
         */
        // TODO: Get rid of these, add them in to drawablegameobject
        void loadImage(const std::string& id, const std::string& filename);
        void loadImage(const std::string& id);

        /**
         * Can use instead of using load method
         */
        void setTexture(SDL_Texture* tex);

        // Draw the sprite with the target window
        void draw();
        // No need for dispose
        //void dispose();

        // Set height or width
        void setHeight(int h) { m_height = h;}
        void setWidth(int w) { m_width = w; }
        
        int getHeight() { return m_height; }
        int getWidth() { return m_width; }

        const Vector2& getPosition() { return m_position; }
        float getX() { return m_position.x; }
        float getY() { return m_position.y; }

        void setX(float x) { m_position.x = x; }
        void setY(float y) { m_position.y = y; }
        void setPosition(const Vector2& pos) { m_position = pos; }
        void setPosition(float x, float y) { m_position.x = x; m_position.y =y; }

        /**
         * Move by offset
         */
        // TODO: Move these to drawablegameobject
        void move(float x, float y);
        void move(const Vector2& offset);

        // Rotation
        void setRotation(double rot) { m_rotation = rot; }
        /**
         * Rotate the sprite by using its previous rotation
         */
        void rotate(double rot);
        double getRotation() { return m_rotation; }

        void setColor(const Color& col) { m_color = col; }
        void setColor(Uint8 r, Uint8 g, Uint8 b)
        {
        	m_color.r = r;
        	m_color.g = g;
        	m_color.b = b;

        	if(m_pTexture)
				SDL_SetTextureColorMod(m_pTexture, r, g, b);
        }
        void setAlpha(Uint8 a)
        {
        	m_color.a = a;

        	if(m_pTexture)
        		SDL_SetTextureAlphaMod(m_pTexture, a);
        }

        Color getColor() { return m_color; }
        Uint8 getAlpha() { return m_color.a; }

private:
        void initTextureData();
};

#endif
