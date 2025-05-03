#include <bits/stdc++.h>
using namespace std;

template <class T>
class Array
{
private:
    T *A;       // Dynamic array
    int size;   // Total size
    int length; // Current number of elements

public:
    // Default constructor
    Array()
    {
        size = 10;
        A = new T[size];
        length = 0;
    }

    // Parameterized constructor
    Array(int size)
    {
        this->size = size;
        length = 0;
        A = new T[size];
    }

    // Destructor to free allocated memory
    ~Array()
    {
        delete[] A;
    }

    // Method to display array elements
    void display();

    // Method to insert an element at a given index
    void insert(int index, T element);

    // Method to delete an element from a given index and return the deleted element
    T remove(int index); // Changed from Delete to remove

    // Method to get element at a given index
    T at(int index);

    // Method to add an element at the end of the array
    void push_back(T element);

    // Method to remove the last element in the array
    void pop_back();

    // Method to calculate the sum of all elements
    T sum();

    // Method to return the number of elements in the array
    int get_length() const;

    // Method to fill the array with a specified element
    void fill(T element);

    // Method to set an element at a given index and return the old element
    T set(int index, T element);

    // Method to return the maximum element in the array
    T max();

    // Method to reverse the array
    void reverse();

    // Overloaded [] operator for accessing and modifying elements
    T &operator[](int index);
    bool isSorted();
};

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

template <class T>
void Array<T>::insert(int index, T element)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = element;
        length++;
    }
    else
    {
        cout << "Invalid index\n";
    }
}

template <class T>
T Array<T>::remove(int index)
{
    T deletedElement = T(); // Default value
    if (index >= 0 && index < length)
    {
        deletedElement = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    else
    {
        cout << "Invalid index\n";
    }

    return deletedElement;
}

template <class T>
T Array<T>::at(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    else
    {
        cout << "Index out of bounds\n";
        return T(); // Return a default value of type T
    }
}

template <class T>
void Array<T>::push_back(T element)
{
    if (length < size)
    {
        A[length] = element;
        length++;
    }
    else
    {
        cout << "Array is full\n";
    }
}

template <class T>
void Array<T>::pop_back()
{
    if (length > 0)
    {
        length--;
    }
    else
    {
        cout << "Array is empty\n";
    }
}

template <class T>
T Array<T>::sum()
{
    if (std::is_arithmetic<T>::value)
    {
        T sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }
    else
    {
        cout << "Sum operation is not supported for non-numeric types.\n";
        return T(); // Return a default value of type T
    }
}

template <class T>
int Array<T>::get_length() const
{
    return length; // Return the current length of the array
}

template <class T>
void Array<T>::fill(T element)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = element; // Fill the array with the specified element
    }
    length = size; // Update length to match size after filling
}

template <class T>
T Array<T>::set(int index, T element)
{
    if (index >= 0 && index < length)
    {
        T oldElement = A[index];
        A[index] = element;
        return oldElement; // Return the replaced element
    }
    else
    {
        cout << "Invalid index\n";
        return T(); // Return default value
    }
}

template <class T>
T Array<T>::max()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return T(); // Return default value of T
    }

    T max = A[0]; // Initialize to the first element
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

template <class T>
void Array<T>::reverse()
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        T temp = A[start]; // Swap the elements
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}

template <class T>
T &Array<T>::operator[](int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    else
    {
        throw out_of_range("Index out of bounds");
    }
}
template <class T>
bool Array<T>::isSorted()
{
    for (int i = 0; i < length; i++)
    {
        if (A[i + 1] > < [i])
            return false;
    }
    return true;
}

int main()
{
    Array<int> arr; // Example usage of the Array class

    // Test push_back() and display()
    cout << "Adding elements 1, 2, 3 using push_back():" << endl;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.display(); // Output: 1 2 3

    // Test sum() and get_length()
    cout << "Sum: " << arr.sum() << "\n";           // Output: Sum: 6
    cout << "Length: " << arr.get_length() << "\n"; // Output: Length: 3

    // Test pop_back()
    cout << "After pop_back():" << endl;
    arr.pop_back();
    arr.display(); // Output: 1 2

    // Test overloaded [] operator for accessing and modifying elements
    cout << "Setting arr[1] = 5:" << endl;
    arr[1] = 5;
    arr.display(); // Output: 1 5

    // Test insert() at index 1
    cout << "Inserting 10 at index 1:" << endl;
    arr.insert(1, 10);
    arr.display(); // Output: 1 10 5

    // Test remove() at index 1
    cout << "Removing element at index 1:" << endl;
    int removedElement = arr.remove(1);
    cout << "Removed element: " << removedElement << "\n"; // Output: 10
    arr.display();                                         // Output: 1 5

    // Test at() to retrieve an element
    cout << "Element at index 0: " << arr.at(0) << "\n"; // Output: 1

    // Test set() to modify an element
    cout << "Setting arr[0] to 7:" << endl;
    arr.set(0, 7);
    arr.display(); // Output: 7 5

    // Test max() to find the maximum element
    cout << "Maximum element: " << arr.max() << "\n"; // Output: 7

    // Test reverse()
    cout << "Reversing the array:" << endl;
    arr.reverse();
    arr.display(); // Output: 5 7

    // Test fill() to fill the array with a value
    cout << "Filling the array with value 9:" << endl;
    arr.fill(9);
    arr.display(); // Output: 9 9 9 9 9 9 9 9 9 9

    // Test sum() after fill()
    cout << "Sum after filling: " << arr.sum() << "\n"; // Output: 90

    return 0;
}
