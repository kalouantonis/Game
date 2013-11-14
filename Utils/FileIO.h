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

        const int limit = 100;
        int count;
        SDL_RWops *__file;

    public:
        // constructor which takes buffer as arugment
        FileIO(bool buffer);

        // open a file and specify the mode
        void openfile(const std::string&, const char*);

        // allocate the function and open it;
        void init();

        void flush();

        void write(const std::string&);

        // clear the file
        void clearfile();

        // close the file and free resources
        void close();

};

#endif
