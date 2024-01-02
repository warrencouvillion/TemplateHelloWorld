#include <iostream>
#include <cstring>

class HelloWorldString
{
protected:
    static const char s_helloWorldString[];
};
const char HelloWorldString::s_helloWorldString[] = "Hello World!\n";

template<size_t N = 0>
class HelloWorld : public HelloWorldString
{
public:
    HelloWorld()
    {
        std::cout << s_helloWorldString[N];
        HelloWorld<N+1>();
    }
}; 

template<> class HelloWorld<std::size(HelloWorldString::s_helloWorldString)>
{
public:
    HelloWorld(){}
};