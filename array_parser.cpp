#include <iostream>

void increase(int *const array, const int NUM_ELEMENTS);
void display(const int *array, const int NUM_ELEMENTS);

int main()
{
    const int NUM_SCORES = 3;
    int hiScores[NUM_SCORES] = {5000, 3500, 2700};
    std::cout << *hiScores << std::endl;
    std::cout << *(hiScores + 1) << std::endl;
    std::cout << *(hiScores + 2) << std::endl;
    increase(hiScores, NUM_SCORES);
    display(hiScores, NUM_SCORES);
}

void increase(int *const array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        array[i] += 500;
    }
}
void display(const int *array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}
