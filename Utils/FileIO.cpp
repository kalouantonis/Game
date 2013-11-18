#include "FileIO.h"

FileIO::FileIO()
{
    init();
    isopened = false;
}

void FileIO::init()
{
   __file = SDL_AllocRW();
}

void FileIO::openfile(const std::string &name, const char *mode)
{
    if(isopened == true)
    {
        close();
    }

    fname = name;
    __file = SDL_RWFromFile(name.c_str(), mode);
}

void FileIO::flush()
{
    if(__file != NULL)
    {
        SDL_RWwrite(__file, BUFFER.c_str(), 1, BUFFER.size());
        BUFFER.clear();
    }
}

void FileIO::write(const std::string &content)
{
    if(BUFFER.size() < BLIMIT)
    {
        BUFFER += content;
    }
    else
    {
        flush();
        write(content);
    }
}

std::string FileIO::read()
{
    char *ptr = NULL;
    std::string content = "";

    if(isopened == true)
    {
        SDL_RWread(__file, ptr, 1024 * 8, 1);
        content = ptr;
    }
    else
    {
        std::cerr << "file is not opened!\n";
    }
    
    return content;
}

void FileIO::clearfile()
{
    if(__file != NULL)
    {
       SDL_RWclose(__file);
       init();
    }
}

void FileIO::close()
{
    fname = "";
    SDL_RWclose(__file);
    isopened = false;       
    __file = NULL; }
