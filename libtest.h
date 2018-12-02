#ifndef __lib_test_h__
#define __lib_test_h__

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>

#ifndef MAX_PATH
#define  MAX_PATH  260 
#endif

#ifndef API_EXPORT
#define API_EXPORT  __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C"
{
#endif

API_EXPORT uint32_t  gainresult(uint32_t  _first,  uint32_t _seconde);

API_EXPORT uint32_t  rmresult(uint32_t _first,  uint32_t  _seconde);

extern  char  strversion[ PATH_MAX ] API_EXPORT;

#ifdef __cplusplus
}
#endif

#endif