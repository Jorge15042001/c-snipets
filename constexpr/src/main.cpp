#include <vector>
#include <array>
#include <string>
#include <string_view>

constexpr std::vector<int> getVector ()
{
    std::vector<int> v {1,2,3,4,5,6};
    std::string a = "aaaaaa";
    std::string_view b = a;
    return v;
}
