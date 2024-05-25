#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
    cout << "Beauty is only skin deep" << endl;
}

int main()
{
    std::thread t1(function_1); // t1 starts running
}