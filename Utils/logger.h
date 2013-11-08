#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdarg.h>

typedef void(*LOGFUNCP)(const char* fmt, va_list args);

enum LOG_LEVEL
{
	DEBUG, // Developer debug info
	INFO,  // Some info the user might want to see
	ERROR  // Critical errors
};

extern LOGFUNCP custFunc;

// logger file descriptors
extern FILE* errordesc;
extern FILE* dbgdesc;
extern FILE* infodesc;

void log(LOG_LEVEL level, const char* format, ...);

void attachFunc(LOGFUNCP newcallback);

// Default log functions
void dbgLog(const char* format, va_list args);
void infoLog(const char* format, va_list args);
void errorLog(const char* format, va_list args);

#endif