#include "strlib.h"

std::string  extract_file_name(std::string filepath)
{
   if(filepath.empty()){
        return  "";
    }
 
    size_t  pos = filepath.find_last_of("/", std::string::npos);
    if(pos == std::string::npos){
        return "";
    }
    
    std::string strret =  filepath.substr(pos, std::string::npos);

    return strret;
}

