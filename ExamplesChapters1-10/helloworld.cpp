#include <iostream>


int main()
{
    int a = 1;
    int b = 10;
    ++a *= b;
    ///int c2 = b * a++;
    std::cout << a <<std::endl;
    //std::cout << c2 <<std::endl; 
}
