// Introduction Of Templates

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T square(T x)
{
    return x * x;
}
int main()
{
    cout << square<int>(5) << endl;
    cout << square<int>(3.5) << endl;
}