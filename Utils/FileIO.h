#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <iostream>
#include <string>
#include <SDL2/SDL_rwops.h>

class FileIO
{
    private:
        std::string BUFFER;
        std::string fname;

        const unsigned int BLIMIT = 1024;
        SDL_RWops *__file;
        
        bool isopened;

    public:
        // constructor which takes buffer as arugment
        FileIO();

        // open a file and specify the mode
        void openfile(const std::string&, const char*);

        // allocate the function and open it;
        void init();

        // write the buffer's content to file when
        // it's full
        void flush();

        void write(const std::string&);
        std::string read();

        // clear the file
        void clearfile();

        // close the file and free resources
        void close();
        
        // check if there's a file opened or
        // return it's name
        bool isOpened() { return isopened; } 
        std::string checkfname() { return fname; }

};

#endif
