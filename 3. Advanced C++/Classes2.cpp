// Log in CPP

#include <iostream>

using namespace std;

class Log
{
public:
    // for variables
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo; // private member

public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Warn(const char *message)
    {
    }
};

int main()
{

    Log log;
    // Setting log level
    log.SetLevel(LogLevelWarning);
    log.Warn("You are warned");
    cin.get();
}