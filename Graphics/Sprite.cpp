#include "Sprite.h"

Sprite::Sprite(std::string name, int h, int w, SDL_Renderer *rend) : height(h), width(w),
    filename(name), rendTarget(rend)
{
    texture = NULL;

    LoadImage(name);

    this->posX() = 0;
    this->posY() = 0;

}

void Sprite::LoadImage(std::string nm)
{
    // Load texture from image
    texture = IMG_LoadTexture(rendTarget, nm.c_str());
    
    if(!texture)
    {
        std::cout << IMG_GetError() << "\n";
    //    throw std::runtime_error("Failed to load image: ", + nm + IMG_GetError());
    }
}

void Sprite::Draw()
{
    SDL_RenderCopy(rendTarget, texture, NULL, NULL);
}

void Sprite::Dispose()
{
    SDL_DestroyTexture(texture);
}
