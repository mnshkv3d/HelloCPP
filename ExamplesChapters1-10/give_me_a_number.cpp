#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
int askNumber(int high, int low = 1);

int main()
{
    int number = askNumber(5);
    cout << "Thanks for entering: " << number << "\n\n";
    number = askNumber(10,5);
    cout << "Thanks for entering: " << number << "\n\n";
    return 0;
}

int askNumber (int high, int low)
{
    int num;
    do
    {
        cout << "Please enter a number" << " (" << low << " - " << high << "): ";
        cin >> num;
    } while (num > high || num < low);
    return num;
} 