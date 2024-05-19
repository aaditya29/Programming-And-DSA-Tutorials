// Log in CPP

#include <iostream>

using namespace std;

class Log
{
};

int main()
{

    Log log;
    // Setting log level
    log.SetLevel(LogLevelWarning);
    cin.get();
}