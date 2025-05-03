#include <bits/stdc++.h>
using namespace std;

// Template class for Node
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

// Template class for LinkedList
template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    // Constructor
    LinkedList() { head = NULL; }

    // Destructor
    ~LinkedList();

    // Member functions
    void Insert(T element);
    void Insert(int position, T element);
    void Display();
    int Length();
    void Delete();
    void DeleteBeg();
    void DeleteLast();
};

// Insert function definition
template <class T>
void LinkedList<T>::Insert(T element)
{
    Node<T> *new_node = new Node<T>(); // Fixed memory allocation
    new_node->data = element;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node<T> *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}
// Insert at specific position function definition
template <class T>
void LinkedList<T>::Insert(int position, T element)
{
    Node<T> *new_node = new Node<T>(); // Fixed memory allocation
    new_node->data = element;
    new_node->next = NULL;
    int count = 0;

    if (position == 0)
    {
        new_node->next = head;
        head = new_node;
        return;
    }
    Node<T> *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "Insert is not valid at this position at " << position << " ";
    }

    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
// Length function definition
template <class T>
int LinkedList<T>::Length()
{
    int count = 0;
    Node<T> *last = head;
    while (last != NULL)
    {
        count++;
        last = last->next;
    }
    return count;
}

// Display function to print the linked list
template <class T>
void LinkedList<T>::Display()
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Delete function to Delete the linked list
template <class T>
void LinkedList<T>::Delete()
{
    Node<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;

    cout << "Linked List deleted successfully" << endl;
}

// Delete function to Delete the first Element linked list
template <class T>
void LinkedList<T>::DeleteBeg()
{
    Node<T> *temp;
    if (head == NULL)
    {
        cout << " Linked List is Empty";
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
}
// Delete function to Delete the Last Element linked list
template <class T>
void LinkedList<T>::DeleteLast()
{
    Node<T> *temp;
    temp = head;
    if (head == NULL)
    {
        cout << " Linked List is Empty";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
// Destructor to free memory
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function to test the linked list
int main()
{
    LinkedList<int> Ls;

    Ls.Insert(10);
    Ls.Insert(5);
    Ls.Insert(6);
    Ls.Insert(7);
    Ls.Insert(8);
    Ls.Display();
    Ls.Insert(1, 0);
    Ls.Insert(2, 10);
    Ls.Display();
    Ls.DeleteBeg();
    Ls.Display();
    Ls.DeleteLast();
    Ls.Display();
    cout << "Length: " << Ls.Length() << "\n"; // Output: 3
    Ls.Delete();
    Ls.Display();
    return 0;
}
