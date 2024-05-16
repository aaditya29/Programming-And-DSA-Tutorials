// Class templates program

#include <iostream>
using namespace std;

template <typename T>

T square(T x)
{
    return x * x;
}

template <typename T>
class ClassVector
{
    T arr[1000];
    int size;

public:
    ClassVector() : size(0) {}
    void push(T x)
    {
        arr[size] = x;
        size++;
    }
    T get(int i) const
    {
        return arr[i];
    }
    int getSize() const
    {
        return size;
    }

    // This function performs an element-wise multiplication of the two input vectors and stores the result in the ret vector, which is then returned.
    void print() const
    {
        const int *p = arr;
        for (int i = 0; i < size; i++)
        {
            cout << *(p++) << endl;
        }
    }
};

int main()
{
    cout << square(5) << endl;
    ClassVector<int> cv;
    cv.push(2);
    cv.push(5);
    cv.push(8);
    cv.push(9);
    cv.print();
    cout << "Print squared cv: " << endl;
    cv = square(cv);
    cv.print();
}
