#include <iostream>
#include "parametrparser.h"

int main(int argc, char** argv)
{
    ParametrParser p(argc, argv);
    p.setShortOption("i", [](std::string str){ std::cout << str << std::endl; } );
    p.exec();
    std::cout << "The end!" << std::endl;
    return 0;
}

