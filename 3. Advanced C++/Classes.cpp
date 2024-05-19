// Basic C++ Class

#include <iostream>

using namespace std;

class Player
{
public:
    int x, y;
    int speed;

    void Move(int x, int y)
    {
        x += x * speed;
        y += y * speed;
    }
};

int main()
{
    Player player;
    player.Move(1, -1);
    cin.get();
}