// #include <iostream>
// #include <string>

// using std::cout;
// using std::cin;
// using std::string;
// int myNumber;
// int enterNumber(string promt);

// int main()
// {
//     enterNumber("Please enter the number: ");
//     cout << "\n\nYour number is: " << myNumber << std::endl;
// }

// int enterNumber(string promt)
// {
//     cout << promt;
//     cin >> myNumber;
//     //cout << "\n\nYour number is: " << myNumber << std::endl;
//     return myNumber;
// }

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int enterNumber(string prompt);

int main() {
    int myNumber = enterNumber("Please enter the number: ");
    cout << "\n\nYour number is: " << myNumber << std::endl;
}

int enterNumber(string prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}
