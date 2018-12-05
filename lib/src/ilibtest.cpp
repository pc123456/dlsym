#include "ilibtest.h"

#define  SO_PATH "../lib/libtest.so.1.0"
#define  MIX_MAJOR_VERSION 1
#define  MIX_MINOR_VERSION 0 

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
    bool bret = false;

    do{
        if(NULL != _hso){
            return true;
        }
        _hso = dlopen(SO_PATH, RTLD_LAZY);
        if(NULL == _hso){
            perror(dlerror());
            break;
        }
        int major = 0;
        int minor = 0;
        std::string  strver;
        if(false == get_so_version(major,  minor,  strver)){
            perror("get_so_version fail..");
            break;
        }
        if(major < MIX_MAJOR_VERSION || (major == MIX_MAJOR_VERSION && minor < MIX_MINOR_VERSION)){
           perror("version of so is low...");
            break;
        }
        bret = true;

    }while(false);

    if(false == bret && NULL != _hso){
        dlclose(_hso);
        _hso = NULL;
    }
    return bret;
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

bool   ilibtest::get_so_version(int& _major, int& _minor,  std::string& _ver)
{
     if(false == loadso()){
        return false;
    }
    typedef void  (*fnget_so_version)(int& _major, int& _minor,  std::string& _ver);
    fnget_so_version pfnget_so_version = (fnget_so_version)dlsym(_hso,  "get_so_version");
    if(NULL ==  pfnget_so_version){
        perror(dlerror());
        return false;
    }
    pfnget_so_version(_major, _minor, _ver);
    return true;

}
ilibtest gilibtest; 
