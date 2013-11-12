#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <iostream>
#include <string>
#include <SDL_rwops.h>

class FileIO
{
    private:
        std::string *BUFFER;
        std::string fname;

        int count, limit;
        void flush();
        SDL_RWops *__file;

    public:
        FileIO();
        void openfile(std::string, const char*);
        void writetofile(std::string);
        void clearfile();


        void check();
        void printBuffer();

};

#endif
