#include "parametrparser.h"


#include <iostream>

ParametrParser::ParametrParser(int argc, char **argv)
{
    _argc = argc;
    for(int i = 0; i < argc; ++i){
        _argv.push_back( argv[i] );
        std::cout << _argv.back() << std::endl;
    }
}

void ParametrParser::setOption(std::string shortKey, std::string longKey, ParametrParser::func callback)
{
    _longCallback[longKey]   = callback;
    _shortCallback[shortKey] = callback;
}

void ParametrParser::setShortOption(std::string key, ParametrParser::func callback)
{
    _shortCallback[key] = callback;
}

void ParametrParser::setLongOption(std::string key, ParametrParser::func callback)
{
    _longCallback[key] = callback;
}

bool ParametrParser::exec()
{
    std::string key("o");
    std::string ret("result");
    try{
        _shortCallback[key](ret);
    }catch( std::bad_function_call ){
        std::cout << "So fucking gay!" << std::endl;
        return false;
    }
    return true;
}
