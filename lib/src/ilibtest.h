#ifndef __ilibtest_h__
#define __ilibtest_h__
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <dlfcn.h>
#include <string>

class ilibtest
{
    public:
    ilibtest();
    ~ilibtest();
    
    bool   gainresult(uint32_t  _first,  uint32_t _seconde, uint32_t &_result);
    bool   rmresult(uint32_t _first,  uint32_t  _seconde, uint32_t &_result);
    
    bool   get_so_version(int& _major, int& _minor,  std::string& _ver);
    private:
    bool  loadso();
    void *_hso; 
};
extern  ilibtest gilibtest; 

#endif