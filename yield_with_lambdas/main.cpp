#include <iostream>
struct range_2
{
    int m_start=0;
    int m_end;
    int m_jump=1;
    mutable int m_current_value;
    range_2(const int start, const int end, const int jump=1):
        m_start(start),
        m_end(end),
        m_jump(jump),
        m_current_value(start)
    {}
    class iterator{
    int  value;
    int jump;
    public: 
        iterator(int & ptr,int jump =1):
            value(ptr),jump(jump)
        {
        }
        iterator operator++()
        {
            value+=jump;
            return *this;
        }
        const int & operator * ()const {return value ; }
        bool operator !=(const iterator &other)const 
        {
            return value<other.value;
        }


    };
    iterator  begin() 
    {
        return iterator(m_current_value,m_jump);
    }
    iterator  end () 
    {
        return iterator(m_end);
    }

};
int main()
{
    /*
    auto range=[](const int start, const int end){
        static int it2=start;
        if(it2>=end)return it2;
        return ++it2;
    };
    int x=10;
    while(x-->0)std::cout<<  range(1,10)<<'\n';
    */
    for (int a:range_2(0,100,5))std::cout<<a<<'\n';

}
