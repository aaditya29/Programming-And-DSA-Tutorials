// Threads1

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
    // t1.join();//main thread waits for completion of t1
    t1.detach(); // t1 will freely run on its own

    if (t1.joinable())
        t1.join();
    return 0;
}