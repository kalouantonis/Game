#include "Sprite.h"

#include <stdexcept>

#include <Resources/TextureManager.h>

Sprite::Sprite(SDL_Renderer* renderer)
	: m_height(0), m_width(0)
	, m_position()
	, m_rotation(0)
	, m_pRendTarget(renderer)
	, m_pTexture(nullptr)
	, m_dstRect()
{
	if(!renderer)
		throw std::runtime_error("Sprite::Sprite -- Invalid renderer");
}

Sprite::~Sprite()
{
	dispose();
}

void Sprite::loadImage(const std::string& filename)
{
    // Load texture from image
    m_pTexture = IMG_LoadTexture(m_pRendTarget, filename.c_str());
    
    if(!m_pTexture)
    {
        throw std::runtime_error("Failed to load image: " + filename + "\n\t" + IMG_GetError());
    }
}

void Sprite::rotate(double rot)
{
	m_rotation += rot;

	if(m_rotation > 360)
		m_rotation = 0;
	else if(m_rotation < 0)
		m_rotation = 360;
}

void Sprite::draw()
{
	m_dstRect.h = m_height;
	m_dstRect.w = m_width;
	m_dstRect.x = m_position.x;
	m_dstRect.y = m_position.y;

	SDL_RenderCopyEx(m_pRendTarget, m_pTexture, NULL, &m_dstRect, m_rotation, NULL, SDL_FLIP_NONE);
}

void Sprite::dispose()
{
	if(m_pTexture)
	{
		SDL_DestroyTexture(m_pTexture);

		// Set to null to keep things clean
		m_pTexture = nullptr;
	}
}

