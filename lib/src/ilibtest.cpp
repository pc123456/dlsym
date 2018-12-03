#include "ilibtest.h"

#define  SO_PATH "../lib/libtest.so.1.0"
ilibtest::ilibtest(): _hso(NULL){}

ilibtest::~ilibtest()
{
    if(NULL != _hso){
        dlclose(_hso);
        _hso = NULL;
    }
}

bool  ilibtest::loadso()
{
    if(NULL != _hso){
        return true;
    }
    _hso = dlopen(SO_PATH, RTLD_LAZY);
    if(NULL == _hso)
    {
        char * err = dlerror();
        perror(err);
    }
    return NULL != _hso;
}

bool  ilibtest::gainresult(uint32_t  _first,  uint32_t _seconde, uint32_t &_result)
{
    if(false == loadso()){
        return false;
    }
    typedef uint32_t  (*fngainresult)(uint32_t  _first,  uint32_t _seconde);
    fngainresult pfngainresult = (fngainresult)dlsym(_hso,  "gainresult");
    if(NULL ==  pfngainresult){
        perror(dlerror());
        return false;
    }
    _result =  pfngainresult(_first, _seconde);
    return true;
}

bool ilibtest::rmresult(uint32_t _first,  uint32_t  _seconde, uint32_t &_result)
{
    
    if(false == loadso()){
        return false;
    }
    typedef uint32_t  (*fnrmresult)(uint32_t  _first,  uint32_t _seconde);
    fnrmresult pfngainresult = (fnrmresult)dlsym(_hso,  "rmresult");
    if(NULL ==  pfngainresult){
        perror(dlerror());
        return false;
    }
    _result =  pfngainresult(_first, _seconde);
    return true;
}

ilibtest gilibtest; 