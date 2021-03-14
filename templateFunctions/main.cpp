#include <iostream>
char * p=0;
template<class T> T g(T x=&p){return x;}
template int g <int>(int);

template<int a>
void print(){
    std::cout<<a<<'\n';
}
/*wont work
template<long n>
long fib()
{
    //return n;
    return fib<n-1>()-fib<n-2>();
}
*/

template<long n>
struct fib{
     static const long val= fib<n-1>::val+ fib<n-2>::val;
};
template<>
struct fib<1>
{
    static const long val=1;

};
template<>
struct fib<0>
{
    static const long val=0;

};

/*
template<int n=0>
long fib()
{
    return 0;
}
*/
int  main()
{
    std::cout<<fib<10>::val<<'\n';
    std::cout<<fib<11>::val<<'\n';
    std::cout<<fib<12>::val<<'\n';
    std::cout<<fib<13>::val<<'\n';
    std::cout<<fib<14>::val<<'\n';
    std::cout<<fib<15>::val<<'\n';
    std::cout<<fib<16>::val<<'\n';
    std::cout<<fib<17>::val<<'\n';
    std::cout<<fib<18>::val<<'\n';
    std::cout<<fib<19>::val<<'\n';

}
