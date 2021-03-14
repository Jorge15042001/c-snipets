#include <cstdlib>
#include <iostream>

void LOG(const char* message)
{
    std::cout<<message<<'\n';
}
void * operator  new(size_t size)
{
    std::cout<<"Allocating "<<size<<'\n';
    return malloc(size);
    
}
void operator delete  (void * mem, size_t size)
{
    free(mem);
    std::cout<<"free "<<size;
}
class ran
{
    public:
    const int id;
    ran* other;
    ran(const int id):
        id(id),
        other(nullptr)
    {
        std::cout<<"creating "<<id<<'\n';
    }
    ran(const int id, const int id_other):
        id(id)
    {
        other = new ran(id_other);
        std::cout<<"creating "<<id<<'\n';
    }
    
    ~ran()
    {
        std::cout<<"removing "<<id<<'\n';
    }


};

int main(){
    std::string h;
    LOG("understanding lifetime");
    {
    ran r1(1);
    ran* r2;
    r2= new ran(2);
    ran r3(3,4);
    r3.other=nullptr;
    r3.other=new ran(5);
    }
    std::cin.get();


}
