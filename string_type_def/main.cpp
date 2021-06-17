#include <iostream>
#include <string>
static std::string u8str_from_ll(long long val)
{
    using char_type = std::string::value_type;
    
    char_type c[2];
    c[1] = char_type(val);
    c[0] = char_type(val >> 8);
    std::cout<<c[0]<<"---- "<<c[1]<<'\n';
    
    if (c[0] == 0)
    {
        std::cout<<"return 1Call with"<<val<<'\n';
        return std::string(1, c[1]); // size, character
    }
    std::cout<<"return 2Call with"<<val<<'\n';
    
    return std::string(c, 2); // char buffer, size
}
int main()
{
    std::string string1= u8str_from_ll(0);
    std::string string2= u8str_from_ll(258);

    string1="hola a todos";
    string2="hola a todos";
    
    std::cout<<string1<<'\n';
    std::cout<<string2<<'\n';

}
