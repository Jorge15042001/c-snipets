#include <iostream>
#include <cstddef>
#include <string>
#include <utility>
#include <bitset>
#include <bits/stdc++.h>
#include <vector>


class simple_allocator;
template <simple_allocator & sa >class Variable;
typedef unsigned char  byte;
template<typename T>
void get_byte_representation(const T b)
{
    std::bitset<sizeof(T)*8> x(b);
    std::cout<<x<<' ';
}



enum class Type
{
    Integer,
    Decimal,
    String
};
class variable_t 
{
    Type m_type;
    size_t m_offset;
public:
    variable_t(const Type t, const size_t offset ):
        m_type(t),
        m_offset(offset)
    {
    }

};
class memory_handler
{
    size_t m_size =2480;
    byte * m_memory;
    size_t m_offset=0;
    std::vector<variable_t> m_variables;
    void realocate()
    {
        m_memory=(byte*)std::realloc(m_memory,m_size*2);
        m_size*=2;
        m_variables.reserve(128);
    }
    
public:
    memory_handler():
        m_memory(static_cast<byte *>(std::malloc(m_size)))
    {
    }
    ~memory_handler()
    {
        std::free(m_memory);
    }
    template <typename T> 
    T get_copy(size_t offset ){
       T* reader =(T*) (m_memory+offset); 
       return *reader;
    }
    template<typename T>
    variable_t store(T value,const Type t)
    {
        if (m_offset+sizeof(T)>=m_size) 
        {
            std::cout<<"\nREALOCATED\n";
            realocate();
        }
         T *T_writer= (T*)(m_memory+m_offset);
         *T_writer=value;
         m_variables.emplace_back(t,m_offset);
         m_offset+=sizeof(T);
    }



};
template <simple_allocator & sa >
class Variable
{
    size_t m_offset;
    Type m_type;
    simple_allocator& m_allocator=sa;
    Variable(const size_t offset, const Type type ):
        m_offset(offset),
        m_type(type)
    {
    }
    


    

};
template <typename Lambda>
class  variable_def
{
    const byte * pos_memory;
    const Type t;
    //const auto get_value_ref=[&](){return }
    Lambda get_value;
public:
    variable_def(const byte * pos_memory, const Type t,  Lambda &&get_value):
        pos_memory(pos_memory),
        t(t),
        get_value(std::forward<Lambda>(get_value))
    {
    }


};
template<typename Lambda>
variable_def<Lambda> make_memory_accesor( const byte * b, const Type t,Lambda &&l)
{
    return {b,t, std::forward<Lambda>(l)};
    
}
template<size_t mem_size>
void print_buffer(const byte* mem)
{
    const byte * buff_end=mem+mem_size;
    const byte * it=mem;
    for (;it<buff_end;it+=4)
    {
        get_byte_representation(*it);
        get_byte_representation(*(it+1));
        get_byte_representation(*(it+2));
        get_byte_representation(*(it+3));
        std::cout<<'\n';
    }


}

template <size_t n_bytes>
class Allocator
{


};
int main()
{
    
    const int mem_size=100;
    void * memory = static_cast<byte*>(std::malloc(mem_size));
    memset(memory,0,mem_size);
    byte * writer= memory;
    int a =256;
    std::cout<<"a:";
    get_byte_representation(a);
    std::cout<<"\n\n";
    //writer+=sizeof(int);
    int *int_writer= (int *)writer;
    *int_writer=a;
    auto value =make_memory_accesor(writer,Type::Integer,[&]{
            int * value_ptr=(int *)writer;
            return *value_ptr;
            });
    print_buffer<40>(memory);
    free(memory);
}
