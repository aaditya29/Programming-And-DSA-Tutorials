// Class Template

#include <iostream>
using namespace std;

// creating  a function template named square that takes a single parameter x of type T.
template <typename T>
T square(T x)
{
    return x * x; // returns the square of x
}

// defining a class template named ClassVector that takes a single type parameter T.
// The class represents a simple vector data structure.

template <typename T>
class ClassVector
{
    T arr[1000]; // array of 1000 elements of type T
    int size;

public:
    ClassVector() : size(0) {} // default constructor that initializes the size member variable to 0.

    // member function adds an element x of type T to the end of the vector
    // by storing it in arr[size] and incrementing size.
    void push(T x)
    {
        arr[size] = x;
        size++;
    }

    // Printing all the elements of the vector using a loop.
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    cout << square(5) << endl;

    // Creating an instance of the BoVector class template with T being replaced by int
    ClassVector<int> cv;
    cv.push(2);
    cv.push(5);
    cv.push(8);
    cv.push(9);
    cv.print();
}