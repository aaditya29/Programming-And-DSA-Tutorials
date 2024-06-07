#include <iostream>

using namespace std;

wstring tetromino[7]; // tetromino is a geometric shape composed of four squares, connected orthogonally

// making rotation function
int Rotate(int px, int py, int r)
{

    switch (r % 4)
    {
    case 0:
        return py * 4 + px; // roating 0 degrees
    case 1:
        return 12 + py - (px * 4); // rotating 90 degrees
    case 2:
        return 15 - (py * 4) - px; // rotating 180 degrees
    case 3:
        return 3 - py + (px * 4); // rotating 270 degrees
    }
}

int main()
{
    // Creating assets
    tetromino[0].append(L"..X."); //. to express empty space and X to represent part of the shape
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"..X.");

    tetromino[2].append(L"..X.");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L".X..");
    tetromino[2].append(L"..X.");

    tetromino[3].append(L"..X.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".X..");
    tetromino[3].append(L"..X.");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L".X..");
    tetromino[4].append(L"..X.");

    tetromino[5].append(L"..X.");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L".X..");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"..X.");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L"..X.");
}