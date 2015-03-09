#ifndef PARAMETRPARSER_H
#define PARAMETRPARSER_H

#include <string>
#include <list>
#include <map>
#include <functional>

using std::string;
using std::map;
using std::list;
using std::function;

class ParametrParser
{
private:
    typedef function<void(string)> func;


    int _argc;
    list<string> _argv;
    map<string, func> _shortCallback;
    map<string, func> _longCallback;


public:
    ParametrParser(int argc, char** argv);
    void setOption(string shortKey, string longKey, func callback);
    void setShortOption(string key, func callback);
    void setLongOption(string key, func callback);
    bool exec();
};

#endif // PARAMETRPARSER_H
