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
