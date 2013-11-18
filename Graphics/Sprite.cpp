#include "Sprite.h"

#include <stdexcept>

#include <Resources/TextureManager.h>

const std::string Sprite::ID = "sprite";

Sprite::Sprite(SDL_Renderer* renderer)
	: Component()
	, m_height(0), m_width(0)
	//, m_position()
	, m_rotation(0)
	, m_pRendTarget(renderer)
	, m_pTexture(nullptr)
	, m_dstRect()
{
	if(!renderer)
		throw std::runtime_error("Sprite::Sprite -- Invalid renderer");
}

void Sprite::loadImage(const std::string& id, const std::string& filename)
{
	// Load texture
	SharedTextureManager::Instance().load(id, filename);

	// Add texture to class
	loadImage(id);
}

void Sprite::loadImage(const std::string& id)
{
	// Error handling done in texture manager
	m_pTexture = SharedTextureManager::Instance().get(id);

	initTextureData();
}

void Sprite::setTexture(SDL_Texture* tex)
{
	m_pTexture = tex;

	initTextureData();
}

void Sprite::initTextureData()
{
	if(m_pTexture)
	{
		// Get texture width and height
		SDL_QueryTexture(m_pTexture, NULL, NULL, &m_width, &m_height);

		// Get color mod
		SDL_GetTextureColorMod(m_pTexture, &m_color.r, &m_color.g, &m_color.b);

		// Get alpha
		SDL_GetTextureAlphaMod(m_pTexture, &m_color.a);
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

void Sprite::draw(const Vector2& position)
{
	m_dstRect.h = m_height;
	m_dstRect.w = m_width;
	m_dstRect.x = position.x;
	m_dstRect.y = position.y;

	SDL_RenderCopyEx(m_pRendTarget, m_pTexture, NULL, &m_dstRect, m_rotation, NULL, SDL_FLIP_NONE);
}

void Sprite::draw(int x, int y)
{
	m_dstRect.h = m_height;
	m_dstRect.w = m_width;
	m_dstRect.x = x;
	m_dstRect.y = y;

	SDL_RenderCopyEx(m_pRendTarget, m_pTexture, NULL, &m_dstRect, m_rotation, NULL, SDL_FLIP_NONE);
}

//void Sprite::move(const Vector2& offset)
//{
//	m_position += offset;
//}

/*void Sprite::move(float x, float y)
{
	m_position.x += x;
	m_position.y += y;
}*/
