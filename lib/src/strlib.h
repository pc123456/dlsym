#ifndef __str_lib_h__
#define __str_lib_h__

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>


//#include <iostream>
//#include <string>

// std::string  extract_file_name(std::string filepath);


#ifndef API_EXPORT
#define API_EXPORT  __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C"
{
#endif

extern    int RTMP_ctrlC;

#ifdef __cplusplus
}
#endif

#endif