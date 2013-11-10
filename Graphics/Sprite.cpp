#include "Sprite.h"

#include <stdexcept>

Sprite::Sprite(SDL_Renderer* renderer)
	: m_height(0), m_width(0)
	, m_position()
	, m_bVisible(false)
	, m_pRendTarget(renderer)
	, m_pTexture(nullptr)
{
	if(!renderer)
		throw std::runtime_error("Sprite::Sprite -- Invalid renderer");
}

Sprite::~Sprite()
{
	Dispose();
}

void Sprite::LoadImage(const std::string& filename)
{
    // Load texture from image
    m_pTexture = IMG_LoadTexture(m_pRendTarget, filename.c_str());
    
    if(!m_pTexture)
    {
        std::cout << IMG_GetError() << "\n";
        throw std::runtime_error("Failed to load image: " + filename + "\n\t" + IMG_GetError());
    }

    m_bVisible = true;
}

void Sprite::Draw()
{
	if(m_bVisible)
		SDL_RenderCopy(m_pRendTarget, m_pTexture, NULL, NULL);
}

void Sprite::Dispose()
{
	if(m_pTexture)
		SDL_DestroyTexture(m_pTexture);

	m_bVisible = false;
}
