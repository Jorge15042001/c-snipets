#include <iostream>
struct range
{
    const int m_start=0;
    const int m_end;
    const int m_jump=1;
    range(const int start, const int end, const int jump=1):
        m_start(start),
        m_end(end),
        m_jump(jump)
    {}
    class iterator{
    int current_value ;
    const int jump;
    public: 
        iterator(const int value ,int jump =1):
            current_value(value),jump(jump)
        {
        }
        iterator operator++()
        {
            current_value +=jump;
            return *this;
        }
        const int & operator * ()const {return current_value ; }
        bool operator !=(const iterator &other)const 
        {
            return current_value<other.current_value;
        }


    };
    iterator  begin() 
    {
        return iterator(m_start,m_jump);
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
    for (const int &a:range(0,100,5))std::cout<<a<<'\n';

}
