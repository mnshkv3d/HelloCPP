#include <iostream>
#include <string>

int main()
{
    std::string phrase = "1234567890";
    std::string *pPhrase;
    pPhrase = &phrase;
    std::cout << pPhrase->size()<< std::endl; 
    return 0;

}