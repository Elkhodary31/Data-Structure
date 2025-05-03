// Day 1: Basic Data Types, Conditions, and Input/Output in C++
#include <iostream>  // Include the standard input-output library
using namespace std; // Use the standard namespace to avoid writing std::

int main()
{
    // 1. Basic Data Types (Size in Bytes and Bits)
    int a = 10;         // Integer (4 bytes, 32 bits)
    float b = 5.5;      // Floating-point (4 bytes, 32 bits)
    double c = 3.14159; // Double (8 bytes, 64 bits)
    char d = 'A';       // Character (1 byte, 8 bits)
    bool e = true;      // Boolean (1 byte, 8 bits)

    // Display the values
    cout << "Integer (4 bytes, 32 bits): " << a << endl;
    cout << "Float (4 bytes, 32 bits): " << b << endl;
    cout << "Double (8 bytes, 64 bits): " << c << endl;
    cout << "Character (1 byte, 8 bits): " << d << endl;
    cout << "Boolean (1 byte, 8 bits): " << e << endl;

    // 2. Reference vs Value Type Example
    int x = 42; // Value type (stored directly in memory)
    int &y = x; // Reference type (alias for x, does not create new memory)
    cout << "Original x: " << x << ", Reference y: " << y << endl;
    y = 100; // Changing y also changes x
    cout << "After modifying y, x: " << x << ", y: " << y << endl;

    // 3. Input and Output
    int num;
    cout << "Enter an integer: ";
    cin >> num; // Taking input from the user
    cout << "You entered: " << num << endl;

    // 4. Conditions (if-else statements)
    if (num > 0)
    {
        cout << "The number is positive." << endl;
    }
    else if (num < 0)
    {
        cout << "The number is negative." << endl;
    }
    else
    {
        cout << "The number is zero." << endl;
    }

    // 5. Even or Odd Check
    if (num % 2 == 0)
    {
        cout << num << " is an even number." << endl;
    }
    else
    {
        cout << num << " is an odd number." << endl;
    }

    // 6. Nested Conditions
    if (num >= 1 && num <= 100)
    {
        cout << "The number is within the range of 1 to 100." << endl;
    }
    else
    {
        cout << "The number is out of range." << endl;
    }

    // 7. Switch Case Example
    cout << "Enter a grade (A, B, C, D, F): ";
    char grade;
    cin >> grade;

    switch (grade)
    {
    case 'A':
        cout << "Excellent!" << endl;
        break;
    case 'B':
        cout << "Good Job!" << endl;
        break;
    case 'C':
        cout << "You can do better!" << endl;
        break;
    case 'D':
        cout << "Try harder next time!" << endl;
        break;
    case 'F':
        cout << "You failed." << endl;
        break;
    default:
        cout << "Invalid grade." << endl;
    }

    return 0; // End of program
}
