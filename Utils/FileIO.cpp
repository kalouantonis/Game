#include "FileIO.h"

FileIO::FileIO(bool buffer = false)
{
    init();

    if(buffer == true)
    {
        BUFFER = new std::string;
    }
}

void FileIO::init()
{
   __file = SDL_AllocRW();
   std::cout << "allocating stuff\n";
}

void FileIO::openfile(const std::string &name, const char *mode)
{
    fname = name;
    __file = SDL_RWFromFile(name.c_str(), mode);
    std::cout << "opening file !\n";
}

void FileIO::flush()
{
    if(BUFFER != NULL && __file != NULL)
    {
        SDL_RWwrite(__file, BUFFER->c_str(), 1, BUFFER->size());
        BUFFER->clear();
        std :: cout << "flushing stuff\n";
    }
}

void FileIO::write(const std::string &content)
{
    if(BUFFER->size() < 1024)
    {
        *BUFFER += content;
//        std:: cout << "writing stuff\n";
    }
    else
    {
        flush();
        *BUFFER += content;
    }
}

void FileIO::clearfile()
{
    if(__file !=NULL)
    {
       SDL_RWclose(__file);
       init();
    }
}

void FileIO::close()
{
    if(BUFFER != NULL && __file != NULL)
    {
        delete BUFFER;
        SDL_RWclose(__file);
    } 
}
