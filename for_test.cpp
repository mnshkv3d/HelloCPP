#include <iostream>

int main ()
{
    const int ROWS = 10;
    const int COLUM = 10;

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUM; ++j)
        {
            std::cout << i << "," << j << " ";
        }
        std::cout << std::endl;
    }
}