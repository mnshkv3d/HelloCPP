#include <iostream>


int main()
{
int count = 0;
while (true)
{
    count +=1;
    if(count > 10)
    {
        break;
    }
    if(count == 5)
    {
        continue;
    }
    std::cout << count << std::endl;
}


}

