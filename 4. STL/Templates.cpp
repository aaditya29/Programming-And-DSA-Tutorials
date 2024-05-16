
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
