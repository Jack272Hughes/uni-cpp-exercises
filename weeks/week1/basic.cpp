#include <iostream>
#include <string>
#include <ctime>

#include "MyVars.h"

using namespace std;

template <class T>
T getUserInput(string message) {
    cout << message << endl;
    T input;
    cin >> input;
    return input;
}

namespace firstJob {
    int salary = 20000;
}

namespace secondJob {
    int salary = 15000;
}

int main() {
    cout << "-=== Exercise 1 ===-" << endl;
    string name = getUserInput<string>("What is your name?");
    int age = getUserInput<int>("What is your age?");
    cout << "Welcome " << name << " your age is " << age << endl;

    cout << "-=== Exercise 2 ===-" << endl;
    const int daysOld = (age * 365) + (int)(age / 4);
    cout << "Your age in days would be roughly " << daysOld << endl;

    cout << "-=== Exercise 3 ===-" << endl;
    const int* pAge = &age;
    cout << "The address of the variable 'age' is " << pAge << endl;

    age = 10;
    cout << "After changing the 'age' variable to " << age << " the pointer shows " << *pAge << endl;

    cout << "-=== Exercise 4 ===-" << endl;
    int& rAge = age;
    age = 19;
    cout << "After changing the 'age' variable to " << age << " the reference shows " << rAge << endl;

    cout << "-=== Exercise 5 ===-" << endl;
    cout << "Salary of first job is " << firstJob::salary << " and salary of second job is " << secondJob::salary << endl;

    cout << "-=== Exercise 6 ===-" << endl;
    cout << "MyVars header file contains variable 'surname' with value: " << surname << endl;

    cout << "-=== Exercise 7 ===-" << endl;
    const size_t surnameLength = surname.length();
    cout << "This surname contains " << surnameLength << " characters, starts with " << surname[0] << ", and ends with " << surname[surnameLength - 1] << endl;

    cout << "-=== Exercise 8 ===-" << endl;
    // 1. *i = 30
    // 2. The pointer's type is different to its target type 'char'

    cout << "-=== Exercise 9 ===-" << endl;
    time_t now = time(0);
    tm gmTime;
    gmtime_r(&now, &gmTime);

    char buffer[9];
    strftime(buffer, 9, "%X", &gmTime);

    cout << "It has been " << now << " seconds since 01/01/1970" << endl;
    cout << "The current time is " << buffer << endl;
}