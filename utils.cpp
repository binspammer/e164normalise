#include "utils.h"
#include <iostream>
#include <map>
#include <regex>

namespace Utility
{

namespace E164
{

namespace
{

const std::map<std::string, std::string> country_code_list{ { "UK", "44" }, { "AU", "61" } };

std::regex spacers{ " |-" };
const std::regex prefixes_re( const std::string& country )
{
    auto const code{ country_code_list.at( country ) };
    auto const prefixes{ "^(00" + code + "|\\+" + code + "\\(0\\)|\\(\\+" + code + "\\)|\\+" + code + ")" };
    return std::regex{ prefixes };
}

} // namespace

std::string normalise( const std::string& phone_number, const std::string& country )
try
{
    if( !country_code_list.contains( country ) )
    {
        throw std::runtime_error{ "error: invalid country code" };
    }
    // Extention phone_number format
    if( phone_number.size() < 6 )
    {
        return phone_number;
    }

    // Already in normalised format
    if( auto number{ phone_number.substr( 1 ) };
        phone_number.at( 0 ) == '+' && all_of( begin( number ), end( number ), ::isdigit ) )
    {
        return phone_number;
    }

    // Drop spaces and dashes
    auto number{ std::regex_replace( phone_number, spacers, "" ) };

    auto pos{ 0u };
    // International format
    if( std::cmatch m; std::regex_search( number.c_str(), m, prefixes_re( country ) ) )
    {
        pos = m[0].length();
    }
    // Domestic format
    else if( std::cmatch m; std::regex_search( number.c_str(), m, std::regex{ "^0[1-9]" } ) )
    {
        pos = m[0].length() - 1;
    }
    // Number itself is in correct format
    if( auto clean_number{ number.substr( pos ) }; all_of( begin( clean_number ), end( clean_number ), ::isdigit ) )
    {
        return "+" + country_code_list.at( country ) + clean_number;
    }
    else
    {
        throw std::runtime_error{ "error: invalid phone number" };
    }
}
catch( const std::exception& e )
{
    std::cout << e.what() << std::endl;
    return {};
}

} // namespace E164
} // namespace Utility
