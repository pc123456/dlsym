#include "libtest.h"

uint32_t  gainresult(uint32_t  _first,  uint32_t _seconde)
{
    return  _first + _seconde;
}

uint32_t  rmresult(uint32_t _first,  uint32_t  _seconde)
{
    return  _first - _seconde;
}


char  strversion[ PATH_MAX ]  = "this is dll";


__attribute__((constructor)) void befor_main()
{
    printf("befor main at momment");
}

__attribute__((destructor)) void  after_main()
{
    printf("after main at momment");
}

uint32_t multresult(uint32_t _first,  uint32_t _seconde)
{
    return  _first *  _seconde; 
}
