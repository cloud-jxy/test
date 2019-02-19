#include "StdAfx.h"
#include "uTimeCounter.h"

void __cdecl odprintf(const char *format, ...)
{
    char buf[4096], *p = buf;
    va_list args;

    va_start(args, format);
    p += _vsnprintf(p, sizeof buf - 1, format, args);
    va_end(args);

    
    OutputDebugString(buf);
}

uTimeCounter::uTimeCounter()
{
    LARGE_INTEGER  large_interger;

    QueryPerformanceFrequency(&large_interger);  

    m_dff = large_interger.QuadPart;

    m_c1 = 0;

    m_c2 = 0;
}

uTimeCounter::~uTimeCounter()
{

}

void uTimeCounter::Enter()
{
    LARGE_INTEGER  large_interger;
    QueryPerformanceCounter(&large_interger);  
    m_c1 = large_interger.QuadPart; 
}

void uTimeCounter::Leave( char* file, int line )
{
    LARGE_INTEGER  large_interger;
    QueryPerformanceCounter(&large_interger);  
    m_c2 = large_interger.QuadPart;

    odprintf( "%s(%d):Using time: %0.3lf us\n", file, line, (m_c2 - m_c1)* 1000000 / m_dff );
}
