#include "calculator.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    double db;
    if (calculator(argv[1],&db))
    {
        std::cout<<argv[1]<<" = "<<db<<std::endl;
    }else{
        std::cout<<"input data incorrect, please verify it"<<std::endl;
    }
    
    return 0;
}
