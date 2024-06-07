#include <iostream>

using namespace std;

wstring tetromino[7]; // tetromino is a geometric shape composed of four squares, connected orthogonally
// playing field vairables
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr; // allocating dynamically

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

    pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create play field buffer
    for (int x = 0; x < nFieldWidth; x++)                   // Board Boundary
        for (int y = 0; y < nFieldHeight; y++)
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; // 9 is used to set the border.
}