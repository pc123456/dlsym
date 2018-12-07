#include "libtest.h"
#include "strlib.h"

version_t gversion = {1, 0, "1.0"};

uint32_t  gainresult(uint32_t  _first,  uint32_t _seconde)
{
    return  _first + _seconde ;
}

uint32_t  rmresult(uint32_t _first,  uint32_t  _seconde)
{
    return  _first - _seconde;
}

char  strversion[ PATH_MAX ]  = "this is dll";

__attribute__((constructor)) void befor_main()
{
    printf("befor main at momment...\n");
}

__attribute__((destructor)) void  after_main()
{
    printf("after main at mommen...\n");
}

uint32_t multresult(uint32_t _first,  uint32_t _seconde)
{
    return  _first *  _seconde; 
}

void  get_so_version(int& _major, int& _minor,  std::string& _ver)
{
    _major = gversion.major;
    _minor = gversion.minor;
    _ver  =  gversion.strver;
}
