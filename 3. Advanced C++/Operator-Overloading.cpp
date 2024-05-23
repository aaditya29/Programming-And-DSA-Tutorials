// Operator overloading example

#include <string>
#include <iostream>

using namespace std;

struct Vector2
{
    float x, y;

    // Defining constructor
    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    // Defining operator overloading
    Vector2 operator+(const Vector2 &other) const
    {
        return Add(other);
    }

    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
};

int main()
{
    Vector2 position(4, 5);
    Vector2 speed(6, 4);
    Vector2 powerup(5, 4);

    Vector2 result1 = position.Add(speed.Multiply(powerup));

    Vector2 result2 = position + speed; //* powerup;

    cin.get();
}