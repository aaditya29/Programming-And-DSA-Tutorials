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

## Vectors in STL

Vectors are part of the C++ Standard Template Library (STL) and are widely used sequential containers that store elements in a dynamic array.

Here are some key points about vectors in C++:

1. **Header File:** To use vectors in your C++ program, we need to include the `<vector>` header file.

2. **Declaration:** We can declare a vector like this:

```C++
std::vector<data_type> vector_name;
```

We can replace `data_type` with the type of elements we want to store in the `vector` (e.g., int, double, std::string, or a user-defined class).

3. **Initialization:** We can initialize a vector in several ways:

```C++
std::vector<int> v1; // Empty vector
std::vector<int> v2 {1, 2, 3, 4, 5}; // Initialize with values
std::vector<int> v3(5); // Initialize with 5 default elements (0 for int)
std::vector<int> v4(5, 10); // Initialize with 5 elements, all set to 10
```
