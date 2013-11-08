#include "logger.h"

LOGFUNCP custFunc = NULL;

// logger file locations
FILE* errordesc = stderr;
FILE* infodesc = stdout;
FILE* dbgdesc = stdout;


void log(LOG_LEVEL level, const char* format, ...) 
{
	// Create arg list
	va_list args;

	// store args
	va_start(args, format);

	LOGFUNCP tmpFunc = NULL;

	if(custFunc)
	{
		tmpFunc = custFunc;
	}
	else
	{
		switch(level)
		{
		case DEBUG:
			tmpFunc = dbgLog;
			break;
		case INFO:
			tmpFunc = infoLog;
			break;
		case ERROR:
			tmpFunc = errorLog;
			break;
		default:
			// Just to be safe, dont want NULL pointer dereferencing
			tmpFunc = infoLog;
			break;
		}
	}

	tmpFunc(format, args);

	va_end(args);
}

void attachFunc(LOGFUNCP func)
{
	custFunc = func;
}

void dbgLog(const char* fmt, va_list va)
{
#ifdef _DEBUG
	vfprintf(dbgdesc, fmt, va);
	// Flush changes immedietally for debugging
	fflush(dbgdesc);
#endif
}

void infoLog(const char* fmt, va_list va)
{
	vfprintf(infodesc, fmt, va);
}

void errorLog(const char* fmt, va_list va)
{
	vfprintf(errordesc, fmt, va);
	// Flush messages so they are not lost
	fflush(errordesc);
}