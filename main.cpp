#include <iostream>
#include "parametrparser.h"

int main(int argc, char** argv)
{
    std::string inFile  = "Input.txt";
    std::string outFile = "Output.txt";
    char* pars[6] = {"-o", "Out.txt", "-x", "--input-file", "In.txt", "-h"};
    ParametrParser p(6, pars);
    p.setShortOption("o", [&](std::string str){ outFile = str; } );
    p.setOption("i", "input-file", [&](std::string str){ inFile = str; } );
    p.setShortOption("h", [](std::string){ std::cout << "[HELP]" << std::endl; } );
    try{
        p.exec();
    }catch(ParametrParser::UnknownOption e){
        std::cerr << "Unknown option: " << e.optionName << std::endl;
    }
    std::cout << "Input  file: " << inFile << std::endl;
    std::cout << "Output file: " << outFile << std::endl;
    return 0;
}

