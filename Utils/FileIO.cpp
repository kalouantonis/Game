#include "FileIO.h"

FileIO::FileIO()
{
    __file = SDL_AllocRW();
    BUFFER = new std::string[100];
    std::cout << "Buffer initialized !\n";
}

void FileIO::openfile(std::string name, const char *mode)
{
    fname = name;
    __file = SDL_RWFromFile(name.c_str(), mode);
}

void FileIO::writetofile(std::string content)
{
    SDL_RWwrite(__file, content.c_str(), 1, content.length());
}

void FileIO::clearfile()
{
    __file = SDL_RWFromFile(fname.c_str(), "w");
    SDL_RWclose(__file);

    __file = SDL_RWFromFile(fname.c_str(), "a+");
}

void FileIO::printBuffer()
{
    for( int i = 0; i < 100; i++)
    {
        std::cout << i << "> " << BUFFER[i];
    }
}
