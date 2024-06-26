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

    void Error(const char *message)
    {
        if (m_LogLevel >= LogLevelError)
        {
            cout << "[Error]:" << message << endl;
        }
    }

    void Info(const char *message)
    {
        if (m_LogLevel >= LogLevelWarning)
        {
            cout << "[Info]:" << message << endl;
        }
    }

    void Warn(const char *message)
    {
        if (m_LogLevel >= LogLevelInfo)
        {
            cout << "[Warning]:" << message << endl;
        }
    }
};

int main()
{

    Log log;
    // Setting log level
    log.SetLevel(log.LogLevelWarning);
    log.Warn("You are warned");
    log.Error("We have error!!!");
    log.Info("Hello World");
    cin.get();
}