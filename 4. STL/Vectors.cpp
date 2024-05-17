// Vectors first example

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end();
    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
    {
        cout << *itr << " ";
    }
}