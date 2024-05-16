# STL In C++

> The Standard Template Library or STL in C++ is a collection of template classes and template functions that provide a generic way of programming. It is a library of container classes, algorithms, and iterators.
> It is commonly used for efficiently programming data structures, algorithms, and functions. Some built-in data structures include arrays, vectors, queues, etc.

## Templates in STL

```C++
#include <iostream>

using namespace std;

// Templates introduction

/*

Non conevnient way
int square(int x)
{
    return x * x;
}

double square(double x){
    return x * x;
}

int main()
{
    cout << square(5) << endl;
    cout << square(5.5) << endl;
}
*/

// using template

template <typename T>
T square(T x)
{
    return x * x;
}

int main()
{
    cout << square<int>(5) << endl; // telling square datatype is of int
    cout << square(5.5) << endl;    // telling square datatype is of flo
}
```

### Class Templates in STL

Class templates in C++ are a powerful feature that allows you to create generic classes that can work with different data types. This promotes code reusability and helps in writing more efficient and maintainable code.

Here's a basic example of a class template:

```C++
template <typename T>
class Box {
private:
    T data;

public:
    void set(T value) {
        data = value;
    }

    T get() {
        return data;
    }
};
```

In this example, `T` is a placeholder for the data type that will be specified when we create an instance of the `Box` class. The `Box` class has a private member data of type `T`, and two member functions set and get to set and retrieve the value of data.

To use this class template, we need to create an instance by specifying the data type:

```C++
Box<int> intBox;
intBox.set(42);
int value = intBox.get(); // value will be 42

Box<double> doubleBox;
doubleBox.set(3.14);
double pi = doubleBox.get(); // pi will be 3.14
```

Here, we create two instances of the `Box` class, one for `int` and one for `double`. The compiler generates the appropriate class definition based on the specified data type.
Class templates can also have multiple type parameters, default type parameters, and member function templates. They can be specialized for specific data types to provide optimized implementations.
