#include "utils.h"

#include <iostream>

int main( int argc, char* argv[] )
try
{
    if( argc != 3 )
        throw std::runtime_error{
            "e164normalise: missing operand\n"
            "Try 'e164normalise --help' for more information." };

    std::cout <<  Utility::E164::normalise( argv[1], argv[2] ) << std::endl;
    return 0;
}
catch( const std::exception& e )
{
    std::cout << e.what() << std::endl;
}
