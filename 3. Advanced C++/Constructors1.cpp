#include <iostream>

using namespace std;

class Entity
{

public:
    float X, Y;

    Entity()
    {
    }

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }
    void Print()
    {
        cout << X << " , " << Y << endl;
    }
};

int main()
{
    Entity e(1.0, 2.0);
    e.Print();
    cin.get();
}