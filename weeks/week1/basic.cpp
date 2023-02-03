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
    // Exercise 1
    string name = getUserInput<string>("What is your name?");
    int age = getUserInput<int>("What is your age?");
    cout << "Welcome " << name << " your age is " << age << endl;

    // Exercise 2
    const int daysOld = (age * 365) + (int)(age / 4);
    cout << "Your age in days would be roughly " << daysOld << endl;

    // Exercise 3
    const int* pAge = &age;
    cout << "The address of the variable 'age' is " << pAge << endl;

    age = 10;
    cout << "After changing the 'age' variable to " << age << " the pointer shows " << *pAge << endl;

    // Exercise 4
    int& rAge = age;
    age = 19;
    cout << "After changing the 'age' variable to " << age << " the reference shows " << rAge << endl;

    // Exercise 5
    cout << "Salary of first job is " << firstJob::salary << " and salary of second job is " << secondJob::salary << endl;

    // Exercise 6
    cout << "MyVars header file contains variable 'surname' with value: " << surname << endl;

    // Exercise 7
    const size_t surnameLength = surname.length();
    cout << "This surname contains " << surnameLength << " characters, starts with " << surname[0] << ", and ends with " << surname[surnameLength - 1] << endl;

    // Exercise 8
    // 1. *i = 30
    // 2. The pointer's type is different to its target type 'char'

    // Exercise 9
    time_t now = time(0);
    tm gmTime;
    gmtime_r(&now, &gmTime);

    char buffer[9];
    strftime(buffer, 9, "%X", &gmTime);

    cout << "It has been " << now << " seconds since 01/01/1970" << endl;
    cout << "The current time is " << buffer << endl;
}